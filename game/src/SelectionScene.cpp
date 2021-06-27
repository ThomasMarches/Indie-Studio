/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** SelectionScene.cpp
*/

#include "SelectionScene.hpp"
#include "FoxEngine.hpp"
#include "fstream"
#include "raylib-cpp.hpp"
#include "raylib-cpp/InputBox.hpp"
#include "raylib-cpp/Rectangle.hpp"
#include "raylib-cpp/Window.hpp"
#include <GameScene.hpp>

static int handle_player_index(int add)
{
    static int index = 1;

    index += add;
    if (index < 1)
        index = 1;
    if (index > 4)
        index = 4;
    return (index);
}

static const std::string get_player_image(bool choice, int number, int *color)
{
    static int index = 1;
    static int index2 = 1;
    static int index3 = 1;
    static int index4 = 1;
    std::string buffer = "assets/selection_screen/player";

    switch (number)
    {
        case 1:
            if (choice == true) {
                if (index == 4)
                    index = 1;
                else
                    index++;
            } else {
                if (index == 1)
                    index = 4;
                else
                    index--;
            }
            buffer = buffer + std::to_string(index) + ".png";
            *color = index;
            break;
        case 2:
            if (choice == true) {
                if (index2 == 4)
                    index2 = 1;
                else
                    index2++;
            } else {
                if (index2 == 1)
                    index2 = 4;
                else
                    index2--;
            }
            buffer = buffer + std::to_string(index2) + ".png";
            *color = index2;
            break;
        case 3:
            if (choice == true) {
                if (index3 == 4)
                    index3 = 1;
                else
                    index3++;
            } else {
                if (index3 == 1)
                    index3 = 4;
                else
                    index3--;
            }
            buffer = buffer + std::to_string(index3) + ".png";
            *color = index3;
            break;
        case 4:
            if (choice == true) {
                if (index4 == 4)
                    index4 = 1;
                else
                    index4++;
            } else {
                if (index4 == 1)
                    index4 = 4;
                else
                    index4--;
            }
            buffer = buffer + std::to_string(index4) + ".png";
            *color = index4;
            break;
        default:
            break;
    }
    return (buffer);
}

SelectionScene::SelectionScene() : fox::Scene() { }

SelectionScene::SelectionScene(const std::string &name) : fox::Scene(name) { }

SelectionScene::~SelectionScene() { }

void SelectionScene::on_create(fox::Application& app) { }

void SelectionScene::on_enable(fox::Application& app)
{
    app.PlaySound("MusicEffect", "assets/sounds/selection.ogg", 1, 1);

    app.get_player_manager().updateSkin("player1", 1);
    app.get_player_manager().updateSkin("player2", 2);
    app.get_player_manager().updateSkin("player3", 3);
    app.get_player_manager().updateSkin("player4", 4);

    auto background = m_oWorld.new_entity();
     background
        .add<ray::Texture>("assets/menu/background.png")
        .add<fox::Transform>(Vec3(0, 0, 0));

    // HEADER

    auto player_header = m_oWorld.new_entity();
    player_header
        .add<ray::Texture>("assets/rectangle.png")
        .add<fox::Transform>(Vec3(0, 0, 0));
    player_header.get<fox::Transform>()->scale = Vec3(2.2, 1, 0);

    auto header_image = m_oWorld.new_entity();
    header_image
        .add<ray::Texture>("assets/menu/play.png")
        .add<fox::Transform>();
    header_image.get<fox::Transform>()->set_parent(player_header.get<fox::Transform>().value());
    header_image.get<fox::Transform>()->set_pos(9, 9, 0);

    auto header_txt = m_oWorld.new_entity();
    header_txt
        .add<ray::Text>("Player Selection")
        .add<fox::Transform>();
    header_txt.get<fox::Transform>()->set_parent(player_header.get<fox::Transform>().value());
    header_txt.get<fox::Transform>()->set_pos(500, 15, 0);
    header_txt.get<ray::Text>()->SetColor(ray::Color(0, 191, 255)).SetFontSize(40);


    // FOOTER TEXT

    auto footer_text = m_oWorld.new_entity();
    footer_text
        .add<ray::Text>("Press F1 to add a player and F2 to remove one.")
        .add<fox::Transform>(Vec3(320, 665, 0));
    footer_text.get<ray::Text>()->SetColor(ray::Color(0, 191, 255)).SetFontSize(22);

    auto footer_text2 = m_oWorld.new_entity();
    footer_text2
        .add<ray::Text>("You can put your mouse on the input zone to change the name of players and IAs.")
        .add<fox::Transform>(Vec3(220, 690, 0));
    footer_text2.get<ray::Text>()->SetColor(ray::Color(0, 191, 255)).SetFontSize(22);

    // GO BACK TO MENU BUTTON

    auto go_back_to_menu = m_oWorld.new_entity();
    go_back_to_menu
        .add<Animator>()
        .add<fox::Button>("assets/button/return.png", [&app]
        {
            app.PlaySound("GroupEffect", "assets/sounds/click.ogg", 1, 1);
            app.switch_to("Menu");
        })
        .add<fox::Transform>(Vec3(20, 660, 0));
    go_back_to_menu.get<Animator>()->add_anim("Normal")
        .add<Vec3>()
            .apply(go_back_to_menu.get<fox::Transform>()->scale)
            .then(0, Vec3(0.1, 0.1, 0.1))
            .then(1, Vec3(0.1, 0.1, 0.1));
    go_back_to_menu.get<Animator>()->add_anim("Hover")
        .signal(0, [&app, this] { app.PlaySound("GroupEffect", "assets/sounds/hover.ogg", 0.2, 1); })
        .add<Vec3>()
            .apply(go_back_to_menu.get<fox::Transform>()->scale)
            .then(0, Vec3(0.11, 0.11, 0.11))
            .then(1, Vec3(0.11, 0.11, 0.11));
    go_back_to_menu.get<fox::Button>()->sprite().SetColor(ray::Color(255, 183, 3));

    // PLAYER

    auto input_box1 = m_oWorld.new_entity("input_box1", "input_boxes", true);
    input_box1
        .add<ray::InputBox>(91, 496, 180, 50, ray::Color(240, 255, 255, 127), 9)
        .add<fox::Transform>(Vec3(91, 496, 0));

    auto player1_title = m_oWorld.new_entity("player1_title");
    player1_title
        .add<ray::Text>("Player 1")
        .add<fox::Transform>(Vec3(140, 95, 0));
    player1_title.get<ray::Text>()->SetColor(ray::Color(0, 0, 0, 255)).SetFontSize(25);

    auto rec1 = m_oWorld.new_entity();
    rec1
        .add<fox::Transform>(Vec3(60, 150, 0))
        .add<ray::Rectangle>(60, 150, 250, 400, ray::Color(255, 255, 255, 255));


    auto rec2 = m_oWorld.new_entity();
    rec2
        .add<fox::Transform>(Vec3(65, 155, 0))
        .add<ray::Rectangle>(65, 155, 240, 390, ray::Color(0, 0, 0, 255));

    auto name_header = m_oWorld.new_entity();
    name_header
        .add<fox::Transform>(Vec3(60, 490, 0))
        .add<ray::Rectangle>(60, 490, 250, 60, ray::Color(255, 255, 255, 255));

    auto player1_image = m_oWorld.new_entity("player1_image");
    player1_image
        .add<fox::Image>("assets/selection_screen/player1.png")
        .add<fox::Transform>(Vec3(90, 155, 0));
    player1_image.get<fox::Transform>()->scale = Vec3(2.25, 2.25, 0);

    auto left_arrow1 = m_oWorld.new_entity();
     left_arrow1
            .add<Animator>()
            .add<fox::Transform>(Vec3(55, 495, 0))
            .add<fox::Button>("assets/left_arrow.png", [this, &app]{
                fox::Entity e;
                int color = 0;
                app.PlaySound("GroupEffect", "assets/sounds/click.ogg", 1, 1);
                if (get_world().get_entity("player1_image", e))
                {
                    e.get<fox::Image>()->sprite().Unload();
                    e.get<fox::Image>()->sprite().Load(get_player_image(false, 1, &color));
                    app.get_player_manager().updateSkin("player1", color);
                }
            });
    left_arrow1.get<Animator>()->add_anim("Normal");
    left_arrow1.get<Animator>()->add_anim("Hover")
        .signal(0, [&app, this] { app.PlaySound("GroupEffect", "assets/sounds/hover.ogg", 0.2, 1); });
    left_arrow1.get<fox::Button>()->sprite().SetColor(ray::Color(255, 183, 3));
    left_arrow1.get<fox::Transform>()->scale = Vec3(0.10, 0.10, 0);

    auto right_arrow1 = m_oWorld.new_entity();
     right_arrow1
            .add<Animator>()
            .add<fox::Transform>(Vec3(267, 495, 0))
            .add<fox::Button>("assets/right_arrow.png", [this, &app]{
                fox::Entity e;
                int color = 0;
                app.PlaySound("GroupEffect", "assets/sounds/click.ogg", 1, 1);
                if (get_world().get_entity("player1_image", e))
                {
                    e.get<fox::Image>()->sprite().Unload();
                    e.get<fox::Image>()->sprite().Load(get_player_image(true, 1, &color));
                    app.get_player_manager().updateSkin("player1", color);
                }
            });
    right_arrow1.get<Animator>()->add_anim("Normal");
    right_arrow1.get<Animator>()->add_anim("Hover")
        .signal(0, [&app, this] { app.PlaySound("GroupEffect", "assets/sounds/hover.ogg", 0.2, 1); });
    right_arrow1.get<fox::Button>()->sprite().SetColor(ray::Color(255, 183, 3));
    right_arrow1.get<fox::Transform>()->scale = Vec3(0.10, 0.10, 0);

    // PLAYER 2

    auto player2_title = m_oWorld.new_entity("player2_title");
    player2_title
        .add<ray::Text>("IA 1")
        .add<fox::Transform>(Vec3(440, 95, 0));
    player2_title.get<ray::Text>()->SetColor(ray::Color(0, 0, 0, 255)).SetFontSize(25);

    auto input_box2 = m_oWorld.new_entity("input_box2", "input_boxes", false);
    input_box2
        .add<ray::InputBox>(391, 496, 180, 50, ray::Color(240, 255, 255, 127), 9)
        .add<fox::Transform>(Vec3(20, 20, 0));

    auto rec3 = m_oWorld.new_entity();
    rec3
        .add<fox::Transform>(Vec3(360, 150, 0))
        .add<ray::Rectangle>(360, 150, 250, 400, ray::Color(255, 255, 255, 255));

    auto rec4 = m_oWorld.new_entity();
    rec4
        .add<fox::Transform>(Vec3(365, 155, 0))
        .add<ray::Rectangle>(365, 155, 240, 390, ray::Color(0, 0, 0, 255));

    auto name_header2 = m_oWorld.new_entity();
    name_header2
        .add<fox::Transform>(Vec3(360, 490, 0))
        .add<ray::Rectangle>(360, 490, 250, 60, ray::Color(255, 255, 255, 255));

    auto player2_image = m_oWorld.new_entity("player2_image");
    player2_image
        .add<fox::Image>("assets/selection_screen/player2.png")
        .add<fox::Transform>(Vec3(390, 155, 0));
    player2_image.get<fox::Transform>()->scale = Vec3(2.25, 2.25, 0);

    auto left_arrow2 = m_oWorld.new_entity();
     left_arrow2
            .add<Animator>()
            .add<fox::Transform>(Vec3(355, 495, 0))
            .add<fox::Button>("assets/left_arrow.png", [this, &app]{
                fox::Entity e;
                int color = 0;
                app.PlaySound("GroupEffect", "assets/sounds/click.ogg", 1, 1);
                if (get_world().get_entity("player2_image", e))
                {
                    e.get<fox::Image>()->sprite().Unload();
                    e.get<fox::Image>()->sprite().Load(get_player_image(false, 2, &color));
                    app.get_player_manager().updateSkin("player2", color);
                }
            });
    left_arrow2.get<Animator>()->add_anim("Normal");
    left_arrow2.get<Animator>()->add_anim("Hover")
        .signal(0, [&app, this] { app.PlaySound("GroupEffect", "assets/sounds/hover.ogg", 0.2, 1); });
    left_arrow2.get<fox::Transform>()->scale = Vec3(0.10, 0.10, 0);
    left_arrow2.get<fox::Button>()->sprite().SetColor(ray::Color(255, 183, 3));

    auto right_arrow2 = m_oWorld.new_entity();
     right_arrow2
            .add<Animator>()
            .add<fox::Transform>(Vec3(567, 495, 0))
            .add<fox::Button>("assets/right_arrow.png", [this, &app]{
                fox::Entity e;
                int color = 0;
                app.PlaySound("GroupEffect", "assets/sounds/click.ogg", 1, 1);
                if (get_world().get_entity("player2_image", e))
                {
                    e.get<fox::Image>()->sprite().Unload();
                    e.get<fox::Image>()->sprite().Load(get_player_image(true, 2, &color));
                    app.get_player_manager().updateSkin("player2", color);
                }
            });
    right_arrow2.get<Animator>()->add_anim("Normal");
    right_arrow2.get<Animator>()->add_anim("Hover")
        .signal(0, [&app, this] { app.PlaySound("GroupEffect", "assets/sounds/hover.ogg", 0.2, 1); });
    right_arrow2.get<fox::Button>()->sprite().SetColor(ray::Color(255, 183, 3));
    right_arrow2.get<fox::Transform>()->scale = Vec3(0.10, 0.10, 0);


    // PLAYER 3

    auto input_box3 = m_oWorld.new_entity("input_box3", "input_boxes", false);
    input_box3
        .add<ray::InputBox>(691, 496, 180, 50, ray::Color(240, 255, 255, 127), 9)
        .add<fox::Transform>(Vec3(20, 20, 0));

    auto player3_title = m_oWorld.new_entity("player3_title");
    player3_title
        .add<ray::Text>("IA 2")
        .add<fox::Transform>(Vec3(740, 95, 0));
    player3_title.get<ray::Text>()->SetColor(ray::Color(0, 0, 0, 255)).SetFontSize(25);

    auto rec5 = m_oWorld.new_entity();
    rec5
        .add<fox::Transform>(Vec3(660, 150, 0))
        .add<ray::Rectangle>(660, 150, 250, 400, ray::Color(255, 255, 255, 255));

    auto rec6 = m_oWorld.new_entity();
    rec6
        .add<fox::Transform>(Vec3(665, 155, 0))
        .add<ray::Rectangle>(665, 155, 240, 390, ray::Color(0, 0, 0, 255));

    auto name_header3 = m_oWorld.new_entity();
    name_header3
        .add<fox::Transform>(Vec3(660, 490, 0))
        .add<ray::Rectangle>(660, 490, 250, 60, ray::Color(255, 255, 255, 255));

    auto player3_image = m_oWorld.new_entity("player3_image");
    player3_image
        .add<fox::Image>("assets/selection_screen/player3.png")
        .add<fox::Transform>(Vec3(690, 155, 0));
    player3_image.get<fox::Transform>()->scale = Vec3(2.25, 2.25, 0);

    auto left_arrow3 = m_oWorld.new_entity();
     left_arrow3
            .add<Animator>()
            .add<fox::Transform>(Vec3(655, 495, 0))
            .add<fox::Button>("assets/left_arrow.png", [this, &app]{
                int color = 0;
                fox::Entity e;
                app.PlaySound("GroupEffect", "assets/sounds/click.ogg", 1, 1);
                if (get_world().get_entity("player3_image", e))
                {
                    e.get<fox::Image>()->sprite().Unload();
                    e.get<fox::Image>()->sprite().Load(get_player_image(false, 3, &color));
                    app.get_player_manager().updateSkin("player3", color);
                }
            });
    left_arrow3.get<Animator>()->add_anim("Normal");
    left_arrow3.get<Animator>()->add_anim("Hover")
        .signal(0, [&app, this] { app.PlaySound("GroupEffect", "assets/sounds/hover.ogg", 0.2, 1); });
    left_arrow3.get<fox::Button>()->sprite().SetColor(ray::Color(255, 183, 3));
    left_arrow3.get<fox::Transform>()->scale = Vec3(0.10, 0.10, 0);

    auto right_arrow3 = m_oWorld.new_entity();
     right_arrow3
            .add<Animator>()
            .add<fox::Transform>(Vec3(867, 495, 0))
            .add<fox::Button>("assets/right_arrow.png", [this, &app]{
                fox::Entity e;
                int color = 0;
                app.PlaySound("GroupEffect", "assets/sounds/click.ogg", 1, 1);
                if (get_world().get_entity("player3_image", e))
                {
                    e.get<fox::Image>()->sprite().Unload();
                    e.get<fox::Image>()->sprite().Load(get_player_image(true, 3, &color));
                    app.get_player_manager().updateSkin("player3", color);
                }
            });
    right_arrow3.get<Animator>()->add_anim("Normal");
    right_arrow3.get<Animator>()->add_anim("Hover")
        .signal(0, [&app, this] { app.PlaySound("GroupEffect", "assets/sounds/hover.ogg", 0.2, 1); });
    right_arrow3.get<fox::Button>()->sprite().SetColor(ray::Color(255, 183, 3));
    right_arrow3.get<fox::Transform>()->scale = Vec3(0.10, 0.10, 0);


    // PLAYER 4

    auto input_box4 = m_oWorld.new_entity("input_box4", "input_boxes", false);
    input_box4
        .add<ray::InputBox>(991, 496, 180, 50, ray::Color(240, 255, 255, 127), 9)
        .add<fox::Transform>(Vec3(20, 20, 0));

    auto player4_title = m_oWorld.new_entity("player4_title");
    player4_title
        .add<ray::Text>("IA 3")
        .add<fox::Transform>(Vec3(1040, 95, 0));
    player4_title.get<ray::Text>()->SetColor(ray::Color(0, 0, 0, 255)).SetFontSize(25);


    auto rec7 = m_oWorld.new_entity();
    rec7
        .add<fox::Transform>(Vec3(960, 150, 0))
        .add<ray::Rectangle>(960, 150, 250, 400, ray::Color(255, 255, 255, 255));

    auto rec8 = m_oWorld.new_entity();
    rec8
        .add<fox::Transform>(Vec3(965, 155, 0))
        .add<ray::Rectangle>(965, 155, 240, 390, ray::Color(0, 0, 0, 255));

    auto name_header4 = m_oWorld.new_entity();
    name_header4
        .add<fox::Transform>(Vec3(960, 490, 0))
        .add<ray::Rectangle>(960, 490, 250, 60, ray::Color(255, 255, 255, 255));

    auto player4_image = m_oWorld.new_entity("player4_image");
    player4_image
        .add<fox::Image>("assets/selection_screen/player4.png")
        .add<fox::Transform>(Vec3(990, 155, 0));
    player4_image.get<fox::Transform>()->scale = Vec3(2.25, 2.25, 0);

    auto left_arrow4 = m_oWorld.new_entity();
     left_arrow4
            .add<Animator>()
            .add<fox::Transform>(Vec3(955, 495, 0))
            .add<fox::Button>("assets/left_arrow.png", [this, &app]{
                fox::Entity e;
                int color = 0;
                app.PlaySound("GroupEffect", "assets/sounds/click.ogg", 1, 1);
                if (get_world().get_entity("player4_image", e))
                {
                    e.get<fox::Image>()->sprite().Unload();
                    e.get<fox::Image>()->sprite().Load(get_player_image(false, 4, &color));
                    app.get_player_manager().updateSkin("player4", color);
                }
            });
    left_arrow4.get<Animator>()->add_anim("Normal");
    left_arrow4.get<Animator>()->add_anim("Hover")
        .signal(0, [&app, this] { app.PlaySound("GroupEffect", "assets/sounds/hover.ogg", 0.2, 1); });
    left_arrow4.get<fox::Button>()->sprite().SetColor(ray::Color(255, 183, 3));
    left_arrow4.get<fox::Transform>()->scale = Vec3(0.10, 0.10, 0);

    auto right_arrow4 = m_oWorld.new_entity();
     right_arrow4
            .add<Animator>()
            .add<fox::Transform>(Vec3(1167, 495, 0))
            .add<fox::Button>("assets/right_arrow.png", [this, &app]{
                fox::Entity e;
                int color = 0;
                app.PlaySound("GroupEffect", "assets/sounds/click.ogg", 1, 1);
                if (get_world().get_entity("player4_image", e))
                {
                    e.get<fox::Image>()->sprite().Unload();
                    e.get<fox::Image>()->sprite().Load(get_player_image(true, 1, &color));
                    app.get_player_manager().updateSkin("player4", color);
                }
            });
    right_arrow4.get<Animator>()->add_anim("Normal");
    right_arrow4.get<Animator>()->add_anim("Hover")
        .signal(0, [&app, this] { app.PlaySound("GroupEffect", "assets/sounds/hover.ogg", 0.2, 1); });
    right_arrow4.get<fox::Button>()->sprite().SetColor(ray::Color(255, 183, 3));
    right_arrow4.get<fox::Transform>()->scale = Vec3(0.10, 0.10, 0);

    // PLAY BUTTON

    auto play_button = m_oWorld.new_entity();
    play_button
        .add<fox::Transform>(Vec3(1200, 650, 0))
        .add<Animator>()
        .add<fox::Button>("assets/button/start.png", [this, &app]{
                std::vector<std::string> playerNames;
                std::vector<fox::Entity> entities;
                int x = 0;

                app.PlaySound("GroupEffect", "assets/sounds/click.ogg", 1, 1);
                if (get_world().get_entities_with_tag("input_boxes", entities))
                    for (std::vector<fox::Entity>::iterator it = entities.begin(); it != entities.end(); it++) {
                        if (it->is_enable()) {
                            if (it->get<ray::InputBox>()->getIndex() > 0)
                                playerNames.push_back(it->get<ray::InputBox>()->getContent());
                            else
                                playerNames.push_back("Player " + std::to_string(x + 1));
                        }
                        x++;
                    }
                app.get_player_manager().setPlayerNames(playerNames);
                app.switch_to("Game");
        });
    play_button.get<Animator>()->add_anim("Normal")
        .add<Vec3>()
            .apply(play_button.get<fox::Transform>()->scale)
            .then(0, Vec3(0.3, 0.3, 0.3))
            .then(1, Vec3(0.3, 0.3, 0.3));
    play_button.get<Animator>()->add_anim("Hover")
        .signal(0, [&app, this] { app.PlaySound("GroupEffect", "assets/sounds/hover.ogg", 0.2, 1); })
        .add<Vec3>()
            .apply(play_button.get<fox::Transform>()->scale)
            .then(0, Vec3(0.32, 0.32, 0.32))
            .then(1, Vec3(0.32, 0.32, 0.32));
    play_button.get<fox::Button>()->sprite().SetColor(ray::Color(255, 183, 3));

    auto banner = m_oWorld.new_entity("Banner");
     banner
        .add<ray::Texture>("assets/rectangle.png")
        .add<fox::Transform>(Vec3(0, 655, 0));
    banner.get<fox::Transform>()->scale = Vec3(3, 1, 0);
}

void SelectionScene::on_destroy(fox::Application& app) {}


void SelectionScene::on_disable(fox::Application& app)
{
    app.StopSound("assets/sounds/selection.ogg");
}

void SelectionScene::on_update(fox::Application& app)
{
    fox::Entity e;
    std::vector<fox::Entity> entities;

    if (fox::Input::get_key_down(KEY_F1)) {
        handle_player_index(1);
        if (get_world().get_entity("player" + std::to_string(handle_player_index(0)) + "_title", e))
            e.get<ray::Text>()->SetString("Player " + std::to_string(handle_player_index(0)));
        if (get_world().get_entity("input_box" + std::to_string(handle_player_index(0)), e))
            e.set_enable(true);
        for (int i = 1; get_world().get_entity("player" + std::to_string(handle_player_index(0) + i) + "_title", e); i++) {
            e.get<ray::Text>()->SetString("IA " + std::to_string(i));
        }
    }
    if (fox::Input::get_key_down(KEY_F2)) {
        handle_player_index(-1);
        for (int i = 1; get_world().get_entity("player" + std::to_string(handle_player_index(0) + i) + "_title", e); i++) {
            e.get<ray::Text>()->SetString("IA " + std::to_string(i));
            if (get_world().get_entity("input_box" + std::to_string(handle_player_index(0) + i), e))
                e.set_enable(false);
        }
    }
    if (fox::Input::get_key_down(KEY_F5))
        ray::Window::TakeAScreenshot();
    if (get_world().get_entities_with_tag("input_boxes", entities))
        for (std::vector<fox::Entity>::iterator it = entities.begin(); it != entities.end(); it++)
            it->get<ray::InputBox>()->UpdateBox();
}
