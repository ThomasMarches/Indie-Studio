/*
** EPITECH PROJECT, 2021
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** GameScene
*/

#include <Components/RigidBody.hpp>
#include <string>
#include <Components/PlayerInput.h>
#include <Components/Move.hpp>
#include <PauseScript.hpp>
#include <MapScript.hpp>
#include <PlayerUI.hpp>
#include <TimerScript.hpp>
#include <MapController.hpp>
#include <Components/Wall.hpp>
#include <AIScript.hpp>
#include "raylib-cpp.hpp"
#include "FoxEngine.hpp"
#include "GameScene.hpp"
#include "PlayerScript.hpp"
#include "Utils/Vec3.hpp"

GameScene::GameScene() : fox::Scene()
{
}

GameScene::GameScene(const std::string& name) : fox::Scene(name)
{
    std::srand(std::time(nullptr));
    IntToPlayerPosition = {
            {0, Vec3(-6, 2, -5)},
            {1, Vec3(-6, 2, 5)},
            {2, Vec3(6, 2, -5)},
            {3, Vec3(6, 2, 5)},
    };

    IntToUIPosition = {
            {0, Vec3(0, 200, 0)},
            {1, Vec3(0, 350, 0)},
            {2, Vec3(1030, 200, 0)},
            {3, Vec3(1030, 350, 0)},
    };
}

GameScene::~GameScene() { }

void GameScene::on_create(fox::Application& app)
{
    get_world().system<PlayerInput, Move>().kind(fox::ecs::OnUpdate)
        .each([](fox::Entity e, PlayerInput& input, Move& move)
          {
            float speedUp = e.get<PowerUp>()->getSpeedUp();

            if (input.pad.IsAvailable()) {
                if (input.pad.IsButtonDown(input.m_Gamepad_Up))
                      move.m_oVelocity.z = -move.m_fSpeed - speedUp;

                if (input.pad.IsButtonDown(input.m_Gamepad_Down))
                    move.m_oVelocity.z = move.m_fSpeed + speedUp;
                else if (input.pad.IsButtonUp(input.m_Gamepad_Down) && input.pad.IsButtonUp(input.m_Gamepad_Up))
                    move.m_oVelocity.z = 0;

                if (input.pad.IsButtonDown(input.m_Gamepad_Left))
                    move.m_oVelocity.x = -move.m_fSpeed - speedUp;

                if (input.pad.IsButtonDown(input.m_Gamepad_Right))
                    move.m_oVelocity.x = move.m_fSpeed + speedUp;
                else if (input.pad.IsButtonUp(input.m_Gamepad_Right) && input.pad.IsButtonUp(input.m_Gamepad_Left))
                    move.m_oVelocity.x = 0;
            } else {
                if (fox::Input::get_key_down(input.m_Up))
                      move.m_oVelocity.z = -move.m_fSpeed - speedUp;
                else if (fox::Input::get_key_up(input.m_Up))
                      move.m_oVelocity.z = 0;

                if (fox::Input::get_key_down(input.m_Down))
                    move.m_oVelocity.z = move.m_fSpeed + speedUp;
                else if (fox::Input::get_key_up(input.m_Down))
                    move.m_oVelocity.z = 0;

                if (fox::Input::get_key_down(input.m_Left))
                    move.m_oVelocity.x = -move.m_fSpeed - speedUp;
                else if (fox::Input::get_key_up(input.m_Left))
                    move.m_oVelocity.x = 0;

                if (fox::Input::get_key_down(input.m_Right))
                    move.m_oVelocity.x = move.m_fSpeed + speedUp;
                else if (fox::Input::get_key_up(input.m_Right))
                    move.m_oVelocity.x = 0;
          }
        });

    get_world().system<Move, fox::Transform, fox::RigidBody>().kind(fox::ecs::PreFixUpdate)
        .each([](fox::Entity e, Move& move, fox::Transform& transform, fox::RigidBody& body)
          {
              auto vel = body.get_rb()->getLinearVelocity();
              vel.x = move.m_oVelocity.x;
              vel.z = move.m_oVelocity.z;
              body.get_rb()->setLinearVelocity(vel);
          });

    get_world().system<NativeScript>().kind(fox::ecs::OnAdd)
            .each([](fox::Entity e, NativeScript& script)
                  {
                    fox::Entity var;
                    if (!e.get_world()->get_entity("map_controller", var))
                        return;
                    if (script.is<BombScript>())
                        var.get<NativeScript>()->get<MapController>()->add_bomb(e.get_id());
                  });

    get_world().system<Wall>().kind(fox::ecs::OnAdd)
            .each([](fox::Entity e, Wall& script)
                  {
                    fox::Entity var;
                    if (!e.get_world()->get_entity("map_controller", var))
                        return;
                    var.get<NativeScript>()->get<MapController>()->add_block(e.get_id());
                  });
    get_world().system<Wall>().kind(fox::ecs::OnRemove)
            .each([](fox::Entity e, Wall& script)
                  {
                    fox::Entity var;
                    if (!e.get_world()->get_entity("map_controller", var))
                        return;
                    var.get<NativeScript>()->get<MapController>()->remove_block(e.get_id());
                  });
}

void GameScene::on_enable(fox::Application& app)
{
    int x = 0;
    int save = 0;
    int total = 0;
    std::vector<Vec2> positions = {{-6, -5}, {-6, 5}, {6, -5}, {6, 5}};

    if (!m_bIsPaused) {
        app.PlaySound("MusicEffect", "assets/sounds/game.ogg", 1, 1);
        ray::Keyboard key;
        key.ExitKeySet(KEY_DELETE);

        std::vector<std::string> playerNames = app.get_player_manager().getPlayerNames();
        std::unordered_map<std::string, int> scores;

        get_world().new_entity("map_controller")
                .add<NativeScript>()
                .get<NativeScript>()->bind<MapController>();

        get_world().new_entity()
                .add<NativeScript>()
                .get<NativeScript>()->bind<MapScript>();

        get_world().new_entity()
                .add<ray::Camera3D>(Vec3(0, 25, 10), Vec3(), Vec3(0, 1.0f, 0), 35.f, CAMERA_PERSPECTIVE)
                .add<fox::Transform>();

        for (std::vector<std::string>::iterator it = playerNames.begin(); it != playerNames.end(); it++) {
            get_world().new_entity("player" + std::to_string(x), "players", true)
                    .add<NativeScript>()
                    .add<PlayerInput>(app, "player" + std::to_string(x + 1))
                    .add<fox::Transform>(IntToPlayerPosition[x], Vec3(.8, .8, .8))
                    .get<NativeScript>()->bind<PlayerScript>("assets/characters/" + app.get_player_manager().getPlayerColorAtIndex(x + 1) + ".gltf");
            scores["player" + std::to_string(x)] = 0;
            x++;
        }

        save = x;
        x = 0;
        get_world().new_entity()
                .add<NativeScript>()
                .get<NativeScript>()->bind<TimerScript>();

        int IA_number = 4 - playerNames.size();
        for (int i = 0; i < IA_number; i++, save++) {
            get_world().new_entity("ia_" + std::to_string(i + 1), "players", true)
                    .add<NativeScript>()
                    .get<NativeScript>()->bind<AIScript>(positions[save].x, positions[save].y, "assets/characters/" + app.get_player_manager().getPlayerColorAtIndex(save + 1) + ".gltf");
            scores["ia_" + std::to_string(i + 1)] = 0;
        }
        app.get_player_manager().updateScore(scores);

        for (std::vector<std::string>::iterator it = playerNames.begin(); it != playerNames.end(); it++) {
            get_world().new_entity()
                    .add<NativeScript>()
                    .get<NativeScript>()->bind<PlayerUI>(*it, x, IntToUIPosition[x], true);
            x++;
        }
        for (int i = 1; i <= 4 - playerNames.size(); x++, i++) {
            get_world().new_entity()
                    .add<NativeScript>()
                    .get<NativeScript>()->bind<PlayerUI>("IA " + std::to_string(i), x, IntToUIPosition[x], false);
        }
    }
}

void GameScene::on_destroy(fox::Application& app) { }

void GameScene::on_update(fox::Application& app)
{
    if (fox::Input::get_key_down(KEY_ESCAPE)) {
        auto& vEnt = get_world().get_entities();
        for (int i = 0; i < vEnt.size(); ++i)
        {
            get_world().enable_entity(vEnt[i], false);
        }

        get_world().new_entity()
            .add<NativeScript>()
            .get<NativeScript>()->bind<PauseScript>(m_bIsPaused);
    }
    if (fox::Input::get_key_down(KEY_F5))
        ray::Window::TakeAScreenshot();
}

void GameScene::on_disable(fox::Application &app)
{
    app.StopSound("assets/sounds/game.ogg");
}
