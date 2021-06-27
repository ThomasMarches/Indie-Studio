/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** PlayerScript.hpp
*/

#ifndef ECS_PLAYERSCRIPT_HPP
#define ECS_PLAYERSCRIPT_HPP

#include "ScriptableBehaviour.hpp"
#include "BombScript.hpp"
#include <Components/Score.hpp>
#include <Components/PowerUp.hpp>
#include "Components/Timeline.hpp"

class PlayerScript : public ScriptableBehaviour
{
    PlayerInput* input = nullptr;
public:
    PlayerScript(const std::string &textureFilepath) : _filePath(textureFilepath)
    {
        IntToPlayerPosition = {
            {0, Vec3(-6, 0.7, -5)},
            {1, Vec3(-6, 0.7, 5)},
            {2, Vec3(6, 0.7, -5)},
            {3, Vec3(6, 0.7, 5)},
        };
    }

    virtual void on_create() override
    {
        get_world().new_entity("respawn_text" + get_component<fox::EntityName>()->get(), false)
            .add<ray::Text>("Press your bomb key to respawn")
            .add<fox::Transform>(Vec3(500, 625, 0));
        add_component<Move>(6);
        add_component<PowerUp>();
        add_component<fox::Score>(0);
        add_component<fox::Health>();
        add_component<ray::Model>(getFilepath());
        add_component<BoxCollider>(get_scene());
        add_component<fox::RigidBody>(get_scene());
        get_component<fox::Health>()->subscribe_died([this]
        {
            std::string EntityName = get_component<fox::EntityName>()->get();
            int PlayerNumber = EntityName.at(EntityName.size() - 1) - 48;
            fox::Entity e;
            get_app().PlaySound("GroupEffect", "assets/sounds/death.ogg", 1, 1);
            get_component<PowerUp>()->resetPowerUpValues();
            get_component<fox::Score>()->decrementScore(100);
            get_app().get_player_manager().incrementScore(EntityName, -100);
            get_component<fox::Transform>()->set_pos(IntToPlayerPosition[PlayerNumber]);
            if (get_world().get_entity("respawn_text" + EntityName, e))
                e.set_enable(true);

            get_world().remove_component<BoxCollider>(get_id());
            get_world().remove_component<fox::RigidBody>(get_id());
            get_world().enable_entity(get_id(), false);
        });
        input = &get_component<PlayerInput>().value();
    }

    virtual void on_update() override
    {
        fox::Entity e;

        if (fox::Input::get_key_down(input->m_putBomb) ||
            input->pad.IsButtonReleased(input->m_Gamepad_putBomb)) { // CODECHECK GAMEPAD ( REALEASED / PRESSED ? )
            if (get_world().is_entity_enable(get_id())) {
                if (!get_component<PowerUp>()->increaseNumberOfBomb())
                    return;
                auto bomb = new_entity()
                        .add<NativeScript>()
                        .add<fox::Transform>(get_component<fox::Transform>()->position);
                bomb.get<NativeScript>()->bind<BombScript>(get_component<fox::EntityName>()->get(), get_component<PowerUp>()->getBombRangeUp());
                bomb.get<fox::Transform>()->set_pos(get_component<fox::Transform>()->position);
            } else {
                if (get_world().get_entity("respawn_text" + get_component<fox::EntityName>()->get(), e))
                    e.set_enable(false);
                get_world().enable_entity(get_id(), true);
                get_world().add_component<BoxCollider>(get_id(), get_scene());
                get_world().add_component<fox::RigidBody>(get_id(), get_scene());
            }
        }
    }

    virtual void on_destroy() override {}

    virtual void on_collision_enter(fox::Collider& colider) override
    {
        auto tag_option = get_world().get_component<fox::EntityTag>(colider.entity);

        if (!tag_option)
            return;
        auto tag = tag_option.value().get();

        if (tag == "speed_power_up") {
            get_component<PowerUp>()->setSpeedUp(get_component<PowerUp>()->getSpeedUp() + SPEED_UP);
            get_world().delete_entity(colider.entity);
        }
        if (tag == "fire_power_up") {
            get_component<PowerUp>()->setBombRangeUp(get_component<PowerUp>()->getBombRangeUp() + 1);
            get_world().delete_entity(colider.entity);
        }
        if (tag == "bomb_power_up") {
            get_component<PowerUp>()->setBombNumberUp(get_component<PowerUp>()->getBombNumberUp() + 1);
            get_world().delete_entity(colider.entity);
        }
    }

    const std::string &getFilepath() const
    {
        return _filePath;
    }

private:
    const std::string _filePath;
    std::unordered_map<int, Vec3> IntToPlayerPosition;
};
#endif //ECS_PLAYERSCRIPT_HPP
