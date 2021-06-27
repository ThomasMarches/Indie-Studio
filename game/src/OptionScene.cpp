/*
** EPITECH PROJECT, 2021
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** OptionScene
*/

#include "raylib-cpp.hpp"
#include "FoxEngine.hpp"
#include "OptionScene.hpp"
#include "raylib-cpp/Rectangle.hpp"
#include "raylib-cpp/Texture.hpp"
#include "raylib-cpp/Gamepad.hpp"
#include "Core/PlayerManager.hpp"

void UpdateKeys(OptionScene *scene, fox::Application &app)
{
    fox::Entity e;

    if (scene->get_world().get_entity("key_up_text", e)) {
        e.get<ray::Text>()->SetString(fox::Input::key_to_string(app.get_player_manager().getCurrentInput().m_Up));
    }
    if (scene->get_world().get_entity("key_down_text", e)) {
        e.get<ray::Text>()->SetString(fox::Input::key_to_string(app.get_player_manager().getCurrentInput().m_Down));
    }
    if (scene->get_world().get_entity("key_left_text", e)) {
        e.get<ray::Text>()->SetString(fox::Input::key_to_string(app.get_player_manager().getCurrentInput().m_Left));
    }
    if (scene->get_world().get_entity("key_right_text", e)) {
        e.get<ray::Text>()->SetString(fox::Input::key_to_string(app.get_player_manager().getCurrentInput().m_Right));
    }
    if (scene->get_world().get_entity("key_bomb_text", e)) {
        e.get<ray::Text>()->SetString(fox::Input::key_to_string(app.get_player_manager().getCurrentInput().m_putBomb));
    }
    if (scene->get_world().get_entity("key_up_gamepad_image", e)) {
        e.get<fox::Image>()->sprite().Unload();
        e.get<fox::Image>()->sprite().Load(fox::Input::button_to_image(app.get_player_manager().getCurrentInput().m_Gamepad_Up));
    }
    if (scene->get_world().get_entity("key_down_gamepad_image", e)) {
        e.get<fox::Image>()->sprite().Unload();
        e.get<fox::Image>()->sprite().Load(fox::Input::button_to_image(app.get_player_manager().getCurrentInput().m_Gamepad_Down));
    }
    if (scene->get_world().get_entity("key_left_gamepad_image", e)) {
        e.get<fox::Image>()->sprite().Unload();
        e.get<fox::Image>()->sprite().Load(fox::Input::button_to_image(app.get_player_manager().getCurrentInput().m_Gamepad_Left));
    }
    if (scene->get_world().get_entity("key_right_gamepad_image", e)) {
        e.get<fox::Image>()->sprite().Unload();
        e.get<fox::Image>()->sprite().Load(fox::Input::button_to_image(app.get_player_manager().getCurrentInput().m_Gamepad_Right));
    }
    if (scene->get_world().get_entity("key_bomb_gamepad_image", e)) {
        e.get<fox::Image>()->sprite().Unload();
        e.get<fox::Image>()->sprite().Load(fox::Input::button_to_image(app.get_player_manager().getCurrentInput().m_Gamepad_putBomb));
    }
}

OptionScene::OptionScene() : fox::Scene() {}

OptionScene::OptionScene(const std::string &name) : fox::Scene(name)
{
}

OptionScene::~OptionScene() { }

void OptionScene::on_create(fox::Application& app) { }

void OptionScene::on_enable(fox::Application& app) {

    app.PlaySound("MusicEffect", "assets/sounds/Option.ogg", 1, 1);

    // RECTANGLE

    auto wallpaper = m_oWorld.new_entity();
    wallpaper
        .add<ray::Texture>("assets/options/wp_opt.png")
        .add<fox::Transform>(Vec3(0, 0, 0));

    auto option_header = m_oWorld.new_entity();
    option_header
        .add<ray::Texture>("assets/rectangle.png")
        .add<fox::Transform>(Vec3(0, 0, 0));
    option_header.get<fox::Transform>()->scale = Vec3(2.2, 1, 0);

    auto rec1 = m_oWorld.new_entity();
    rec1
        .add<fox::Transform>(Vec3(100, 150, 0))
        .add<ray::Rectangle>(100, 150, 700, 500, ray::Color(255, 183, 3));


    auto rec2 = m_oWorld.new_entity();
    rec2
        .add<fox::Transform>(Vec3(105, 155, 0))
        .add<ray::Rectangle>(105, 155, 690, 490, ray::Color(2, 48, 71));


    // OPTION TEXT + IMAGE

    auto option_text = m_oWorld.new_entity();
    option_text
        .add<ray::Text>("Options")
        .add<fox::Transform>();
    option_text.get<fox::Transform>()->set_parent(option_header.get<fox::Transform>().value());
    option_text.get<fox::Transform>()->set_pos(570, 15, 0);
    option_text.get<ray::Text>()->SetColor(ray::Color(0, 191, 255)).SetFontSize(40);

    auto option_btn_image = m_oWorld.new_entity();
    option_btn_image
        .add<ray::Texture>("assets/options/options_title.png")
        .add<fox::Transform>();
    option_btn_image.get<fox::Transform>()->set_parent(option_header.get<fox::Transform>().value());
    option_btn_image.get<fox::Transform>()->set_pos(15, 9, 0);


    // GO BACK TO MENU BUTTON

    auto go_back_to_menu = m_oWorld.new_entity();
    go_back_to_menu
        .add<Animator>()
        .add<fox::Button>("assets/button/return.png", [&app]{
            app.PlaySound("GroupEffect", "assets/sounds/click.ogg", 1, 1);
            if (app.get_player_manager().getSelectedKey() == fox::SelectedKey::NONE)
                app.switch_to("Menu");
        })
        .add<fox::Transform>(Vec3(20, 650, 0));
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


    // SOUND MUSIC

    auto music_rec = m_oWorld.new_entity("Music_sound_rec");
        music_rec
            .add<ray::Texture>("assets/rec2.png")
            .add<fox::Transform>(Vec3(950, 305, 0));

    auto minus_button_music = m_oWorld.new_entity();
    minus_button_music
        .add<Animator>()
        .add<fox::Button>("assets/options/minus.png", [this, &app]{
            fox::Entity e;
            app.PlaySound("GroupEffect", "assets/sounds/click.ogg", 1, 1);
            if (get_world().get_entity("Music_sound_rec", e))
            {
                Vec3 &tScale = e.get<fox::Transform>()->scale;
                tScale = Vec3(tScale.x - 0.2, 1, 1);
                if (tScale.x <= 0)
                    tScale.x = 0;
                app.getGroup("MusicEffect").setVolume(tScale.x);
            }
        })
        .add<fox::Transform>(Vec3(900, 300, 0));
    minus_button_music.get<fox::Button>()->sprite().SetColor(ray::Color(0, 191, 255));
    minus_button_music.get<Animator>()->add_anim("Normal")
        .add<Vec3>()
            .apply(minus_button_music.get<fox::Transform>()->scale)
            .then(0, Vec3(0.05, 0.05, 0))
            .then(1, Vec3(0.05, 0.05, 0));
    minus_button_music.get<Animator>()->add_anim("Hover")
        .signal(0, [&app, this] { app.PlaySound("GroupEffect", "assets/sounds/hover.ogg", 0.2, 1); })
        .add<Vec3>()
            .apply(minus_button_music.get<fox::Transform>()->scale)
            .then(0, Vec3(0.06, 0.06, 0))
            .then(1, Vec3(0.06, 0.06, 0));



    auto plus_button_music = m_oWorld.new_entity("plus_button_music");
    plus_button_music
        .add<Animator>()
        .add<fox::Button>("assets/options/plus.png", [this, &app]{
            fox::Entity e;
            app.PlaySound("GroupEffect", "assets/sounds/click.ogg", 1, 1);
            if (get_world().get_entity("Music_sound_rec", e))
            {
                Vec3 &tScale = e.get<fox::Transform>()->scale;
                tScale = Vec3(tScale.x + 0.2, 1, 1);
                if (tScale.x >= 1)
                    tScale.x = 1;
                app.getGroup("MusicEffect").setVolume(tScale.x);
            }
        })
        .add<fox::Transform>(Vec3(1140, 300, 0));
    plus_button_music.get<fox::Button>()->sprite().SetColor(ray::Color(0, 191, 255));
    plus_button_music.get<Animator>()->add_anim("Normal")
        .add<Vec3>()
            .apply(plus_button_music.get<fox::Transform>()->scale)
            .then(0, Vec3(0.05, 0.05, 0))
            .then(1, Vec3(0.05, 0.05, 0));
    plus_button_music.get<Animator>()->add_anim("Hover")
        .signal(0, [&app, this] { app.PlaySound("GroupEffect", "assets/sounds/hover.ogg", 0.2, 1); })
        .add<Vec3>()
            .apply(plus_button_music.get<fox::Transform>()->scale)
            .then(0, Vec3(0.06, 0.06, 0))
            .then(1, Vec3(0.06, 0.06, 0));

    auto button_music_text = m_oWorld.new_entity();
    button_music_text
        .add<ray::Text>("Music sound")
        .add<fox::Transform>(Vec3(950, 250, 0));
    button_music_text.get<ray::Text>()->SetColor(ray::Color(255, 183, 3)).SetFontSize(25);


    // SOUND EFFECT


    auto effect_rec = m_oWorld.new_entity("Effect_sound_rec");
     effect_rec
            .add<ray::Texture>("assets/rec2.png")
            .add<fox::Transform>(Vec3(950, 155, 0));

    auto minus_button_effect = m_oWorld.new_entity();
    minus_button_effect
        .add<Animator>()
        .add<fox::Button>("assets/options/minus.png", [this, &app]{
            fox::Entity e;
            app.PlaySound("GroupEffect", "assets/sounds/click.ogg", 1, 1);
            if (get_world().get_entity("Effect_sound_rec", e))
            {
                Vec3 &tScale = e.get<fox::Transform>()->scale;
                tScale = Vec3(tScale.x - 0.2, 1, 1);
                if (tScale.x <= 0)
                    tScale.x = 0;
                app.getGroup("GroupEffect").setVolume(tScale.x);
            }
        })
        .add<fox::Transform>(Vec3(900, 150, 0));
    minus_button_effect.get<fox::Button>()->sprite().SetColor(ray::Color(0, 191, 255));
    minus_button_effect.get<Animator>()->add_anim("Normal")
        .add<Vec3>()
            .apply(minus_button_effect.get<fox::Transform>()->scale)
            .then(0, Vec3(0.05, 0.05, 0))
            .then(1, Vec3(0.05, 0.05, 0));
    minus_button_effect.get<Animator>()->add_anim("Hover")
        .signal(0, [&app, this] { app.PlaySound("GroupEffect", "assets/sounds/hover.ogg", 0.2, 1); })
        .add<Vec3>()
            .apply(minus_button_effect.get<fox::Transform>()->scale)
            .then(0, Vec3(0.06, 0.06, 0))
            .then(1, Vec3(0.06, 0.06, 0));

    auto plus_button_effect = m_oWorld.new_entity();
    plus_button_effect
        .add<Animator>()
        .add<fox::Button>("assets/options/plus.png", [this, &app]{
            fox::Entity e;
            app.PlaySound("GroupEffect", "assets/sounds/click.ogg", 1, 1);
            if (get_world().get_entity("Effect_sound_rec", e))
            {
                Vec3 &tScale = e.get<fox::Transform>()->scale;
                tScale = Vec3(tScale.x + 0.2, 1, 1);
                if (tScale.x >= 1)
                    tScale.x = 1;
                app.getGroup("GroupEffect").setVolume(tScale.x);
            }
        })
        .add<fox::Transform>(Vec3(1140, 150, 0));
    plus_button_effect.get<fox::Button>()->sprite().SetColor(ray::Color(0, 191, 255));
    plus_button_effect.get<Animator>()->add_anim("Normal")
        .add<Vec3>()
            .apply(plus_button_effect.get<fox::Transform>()->scale)
            .then(0, Vec3(0.05, 0.05, 0))
            .then(1, Vec3(0.05, 0.05, 0));
    plus_button_effect.get<Animator>()->add_anim("Hover")
        .signal(0, [&app, this] { app.PlaySound("GroupEffect", "assets/sounds/hover.ogg", 0.2, 1); })
        .add<Vec3>()
            .apply(plus_button_effect.get<fox::Transform>()->scale)
            .then(0, Vec3(0.06, 0.06, 0))
            .then(1, Vec3(0.06, 0.06, 0));

    auto button_effect_text = m_oWorld.new_entity();
    button_effect_text
        .add<ray::Text>("Effect sound")
        .add<fox::Transform>(Vec3(950, 100, 0));
    button_effect_text.get<ray::Text>()->SetColor(ray::Color(255, 183, 3)).SetFontSize(25);


    // ARROW

    auto left_arrow = m_oWorld.new_entity();
     left_arrow
            .add<Animator>()
            .add<fox::Transform>(Vec3(20, 360, 0))
            .add<fox::Button>("assets/left_arrow.png", [this, &app]{
                app.PlaySound("GroupEffect", "assets/sounds/click.ogg", 1, 1);
                if (app.get_player_manager().getSelectedKey() == fox::SelectedKey::NONE) {
                    fox::Entity e;
                    app.get_player_manager().setCurrent(app.get_player_manager().getCurrentId() - 1);
                    if (get_world().get_entity("player_title", e))
                    {
                        std::string strNew = "Player " + std::to_string(app.get_player_manager().getCurrentId());
                        e.get<ray::Text>()->SetString(strNew);
                        UpdateKeys(this, app);
                    }
                }
            });
    left_arrow.get<fox::Button>()->sprite().SetColor(ray::Color(0, 191, 255));
    left_arrow.get<Animator>()->add_anim("Normal")
        .add<Vec3>()
            .apply(left_arrow.get<fox::Transform>()->scale)
            .then(0, Vec3(0.15, 0.15, 0))
            .then(1, Vec3(0.15, 0.15, 0));
    left_arrow.get<Animator>()->add_anim("Hover")
        .signal(0, [&app, this] { app.PlaySound("GroupEffect", "assets/sounds/hover.ogg", 0.2, 1); })
        .add<Vec3>()
            .apply(left_arrow.get<fox::Transform>()->scale)
            .then(0, Vec3(0.17, 0.17, 0))
            .then(1, Vec3(0.17, 0.17, 0));


    auto right_arrow = m_oWorld.new_entity();
     right_arrow
            .add<Animator>()
            .add<fox::Transform>(Vec3(810, 360, 0))
            .add<fox::Button>("assets/right_arrow.png", [this, &app]{
                app.PlaySound("GroupEffect", "assets/sounds/click.ogg", 1, 1);
                if (app.get_player_manager().getSelectedKey() == fox::SelectedKey::NONE) {
                    fox::Entity e;
                    app.get_player_manager().setCurrent(app.get_player_manager().getCurrentId() + 1);
                    if (get_world().get_entity("player_title", e))
                    {
                        std::string strNew = "Player " + std::to_string(app.get_player_manager().getCurrentId());
                        e.get<ray::Text>()->SetString(strNew);
                        UpdateKeys(this, app);
                    }
                }
            });
    right_arrow.get<fox::Button>()->sprite().SetColor(ray::Color(0, 191, 255));
    right_arrow.get<Animator>()->add_anim("Normal")
        .add<Vec3>()
            .apply(right_arrow.get<fox::Transform>()->scale)
            .then(0, Vec3(0.15, 0.15, 0))
            .then(1, Vec3(0.15, 0.15, 0));
    right_arrow.get<Animator>()->add_anim("Hover")
        .signal(0, [&app, this] { app.PlaySound("GroupEffect", "assets/sounds/hover.ogg", 0.2, 1); })
        .add<Vec3>()
            .apply(right_arrow.get<fox::Transform>()->scale)
            .then(0, Vec3(0.17, 0.17, 0))
            .then(1, Vec3(0.17, 0.17, 0));


    // TEXTE KEYBOARD + GAMEPAD + PLAYER NUMBER
    auto rec_title = m_oWorld.new_entity();
    rec_title
        .add<ray::Text>("Keyboard and Gamepad Settings")
        .add<fox::Transform>(Vec3(275, 100, 0));
    rec_title.get<ray::Text>()->SetColor(ray::Color(255, 183, 3)).SetFontSize(25);

    auto player_number = m_oWorld.new_entity("player_title");
    player_number
        .add<ray::Text>("Player 1")
        .add<fox::Transform>(Vec3(400, 175, 0));
    player_number.get<ray::Text>()->SetColor(ray::Color(255, 183, 3)).SetFontSize(25);


    // RECTANGLES TOUCHES KEYBOARD

    auto text_rec1 = m_oWorld.new_entity();
    text_rec1
        .add<fox::Button>("assets/rec_key.png", [this, &app]{
            app.PlaySound("GroupEffect", "assets/sounds/click.ogg", 1, 1);
            if (app.get_player_manager().isKeyChanging() == false) {
                fox::Entity e;
                app.get_player_manager().setChangingKey(true);
                if (get_world().get_entity("key_up_text", e)) {
                    e.get<ray::Text>()->SetString("");
                }
                if (get_world().get_entity("press_a_key", e)) {
                    e.set_enable(true);
                }
                app.get_player_manager().setSelectedKey(fox::SelectedKey::KEY_UP);
            }
        })
        .add<fox::Transform>(Vec3(290, 240, 0))
        .add<Animator>();
    text_rec1.get<Animator>()->add_anim("Normal");
    text_rec1.get<Animator>()->add_anim("Hover")
        .signal(0, [&app, this] { app.PlaySound("GroupEffect", "assets/sounds/hover.ogg", 0.2, 1); });

    auto text_rec2 = m_oWorld.new_entity();
    text_rec2
        .add<fox::Transform>(Vec3(290, 290, 0))
        .add<fox::Button>("assets/rec_key.png", [this, &app]{
            app.PlaySound("GroupEffect", "assets/sounds/click.ogg", 1, 1);
            if (app.get_player_manager().isKeyChanging() == false) {
                fox::Entity e;
                app.get_player_manager().setChangingKey(true);
                if (get_world().get_entity("key_down_text", e)) {
                    e.get<ray::Text>()->SetString("");
                }
                if (get_world().get_entity("press_a_key", e)) {
                    e.set_enable(true);
                }
                app.get_player_manager().setSelectedKey(fox::SelectedKey::KEY_DOWN);
            }
        })
        .add<Animator>();
    text_rec2.get<Animator>()->add_anim("Normal");
    text_rec2.get<Animator>()->add_anim("Hover")
        .signal(0, [&app, this] { app.PlaySound("GroupEffect", "assets/sounds/hover.ogg", 0.2, 1); });

    auto text_rec3 = m_oWorld.new_entity();
    text_rec3
        .add<fox::Transform>(Vec3(290, 340, 0))
        .add<fox::Button>("assets/rec_key.png", [this, &app]{
            app.PlaySound("GroupEffect", "assets/sounds/click.ogg", 1, 1);
            if (app.get_player_manager().isKeyChanging() == false) {
                fox::Entity e;
                app.get_player_manager().setChangingKey(true);
                if (get_world().get_entity("key_left_text", e)) {
                    e.get<ray::Text>()->SetString("");
                }
                if (get_world().get_entity("press_a_key", e)) {
                    e.set_enable(true);
                }
                app.get_player_manager().setSelectedKey(fox::SelectedKey::KEY_LEFT);
            }
        })
        .add<Animator>();
    text_rec3.get<Animator>()->add_anim("Normal");
    text_rec3.get<Animator>()->add_anim("Hover")
        .signal(0, [&app, this] { app.PlaySound("GroupEffect", "assets/sounds/hover.ogg", 0.2, 1); });

    auto text_rec4 = m_oWorld.new_entity();
    text_rec4
        .add<fox::Transform>(Vec3(290, 390, 0))
        .add<fox::Button>("assets/rec_key.png", [this, &app]{
            app.PlaySound("GroupEffect", "assets/sounds/click.ogg", 1, 1);
            if (app.get_player_manager().isKeyChanging() == false) {
                fox::Entity e;
                app.get_player_manager().setChangingKey(true);
                if (get_world().get_entity("key_right_text", e)) {
                    e.get<ray::Text>()->SetString("");
                }
                if (get_world().get_entity("press_a_key", e)) {
                    e.set_enable(true);
                }
                app.get_player_manager().setSelectedKey(fox::SelectedKey::KEY_RIGHT);
            }
        })
        .add<Animator>();
    text_rec4.get<Animator>()->add_anim("Normal");
    text_rec4.get<Animator>()->add_anim("Hover")
        .signal(0, [&app, this] { app.PlaySound("GroupEffect", "assets/sounds/hover.ogg", 0.2, 1); });

    auto text_rec5 = m_oWorld.new_entity();
    text_rec5
        .add<fox::Transform>(Vec3(290, 440, 0))
        .add<fox::Button>("assets/rec_key.png", [this, &app]{
            app.PlaySound("GroupEffect", "assets/sounds/click.ogg", 1, 1);
            if (app.get_player_manager().isKeyChanging() == false) {
                fox::Entity e;
                app.get_player_manager().setChangingKey(true);
                if (get_world().get_entity("key_bomb_text", e)) {
                    e.get<ray::Text>()->SetString("");
                }
                if (get_world().get_entity("press_a_key", e)) {
                    e.set_enable(true);
                }
                app.get_player_manager().setSelectedKey(fox::SelectedKey::KEY_BOMB);
            }
        })
        .add<Animator>();
    text_rec5.get<Animator>()->add_anim("Normal");
    text_rec5.get<Animator>()->add_anim("Hover")
        .signal(0, [&app, this] { app.PlaySound("GroupEffect", "assets/sounds/hover.ogg", 0.2, 1); });

    auto press_a_key = m_oWorld.new_entity("press_a_key", false)
        .add<ray::Text>("Press a key on your keyboard")
        .add<fox::Transform>(Vec3(250, 600, 0))
        .add<Animator>();
    press_a_key.get<ray::Text>()->SetColor(ray::Color(255, 255, 255, 255)).SetFontSize(25);
    press_a_key.get<Animator>()->add_anim("Blink")
        .loop(true)
        .add<std::uint8_t>()
            .apply(press_a_key.get<ray::Text>()->GetColor().a)
            .then(0, 0)
            .then(1, 255)
            .then(2, 0);

    // RECTANGLES TOUCHES GAMEPAD

    auto text_rec1_gamepad = m_oWorld.new_entity("text_rec1_gamepad", false);
    text_rec1_gamepad
        .add<fox::Button>("assets/rec_key.png", [this, &app]{
            app.PlaySound("GroupEffect", "assets/sounds/click.ogg", 1, 1);
            if (app.get_player_manager().isKeyChanging() == false) {
                fox::Entity e;
                app.get_player_manager().setChangingKey(true);
                if (get_world().get_entity("key_up_gamepad_image", e)) {
                    e.set_enable(true);
                }
                if (get_world().get_entity("press_a_key_gamepad", e)) {
                    e.set_enable(true);
                }
                app.get_player_manager().setSelectedKey(fox::SelectedKey::KEY_GAMEPAD_UP);
            }
        })
        .add<fox::Transform>(Vec3(460, 240, 0))
        .add<Animator>();
    text_rec1_gamepad.get<Animator>()->add_anim("Normal");
    text_rec1_gamepad.get<Animator>()->add_anim("Hover")
        .signal(0, [&app, this] { app.PlaySound("GroupEffect", "assets/sounds/hover.ogg", 0.2, 1); });

    auto text_rec2_gamepad = m_oWorld.new_entity("text_rec2_gamepad", false);
    text_rec2_gamepad
        .add<fox::Transform>(Vec3(460, 290, 0))
        .add<fox::Button>("assets/rec_key.png", [this, &app]{
            app.PlaySound("GroupEffect", "assets/sounds/click.ogg", 1, 1);
            if (app.get_player_manager().isKeyChanging() == false) {
                fox::Entity e;
                app.get_player_manager().setChangingKey(true);
                if (get_world().get_entity("key_down_gamepad_image", e)) {
                    e.set_enable(true);
                }
                if (get_world().get_entity("press_a_key_gamepad", e)) {
                    e.set_enable(true);
                }
                app.get_player_manager().setSelectedKey(fox::SelectedKey::KEY_GAMEPAD_DOWN);
            }
        })
        .add<Animator>();
    text_rec2_gamepad.get<Animator>()->add_anim("Normal");
    text_rec2_gamepad.get<Animator>()->add_anim("Hover")
        .signal(0, [&app, this] { app.PlaySound("GroupEffect", "assets/sounds/hover.ogg", 0.2, 1); });

    auto text_rec3_gamepad = m_oWorld.new_entity("text_rec3_gamepad", false);
    text_rec3_gamepad
        .add<fox::Transform>(Vec3(460, 340, 0))
        .add<fox::Button>("assets/rec_key.png", [this, &app]{
            app.PlaySound("GroupEffect", "assets/sounds/click.ogg", 1, 1);
            if (app.get_player_manager().isKeyChanging() == false) {
                fox::Entity e;
                app.get_player_manager().setChangingKey(true);
                if (get_world().get_entity("key_left_gamepad_image", e)) {
                    e.set_enable(true);
                }
                if (get_world().get_entity("press_a_key_gamepad", e)) {
                    e.set_enable(true);
                }
                app.get_player_manager().setSelectedKey(fox::SelectedKey::KEY_GAMEPAD_LEFT);
            }
        })
        .add<Animator>();
    text_rec3_gamepad.get<Animator>()->add_anim("Normal");
    text_rec3_gamepad.get<Animator>()->add_anim("Hover")
        .signal(0, [&app, this] { app.PlaySound("GroupEffect", "assets/sounds/hover.ogg", 0.2, 1); });

    auto text_rec4_gamepad = m_oWorld.new_entity("text_rec4_gamepad", false);
    text_rec4_gamepad
        .add<fox::Transform>(Vec3(460, 390, 0))
        .add<fox::Button>("assets/rec_key.png", [this, &app]{
            app.PlaySound("GroupEffect", "assets/sounds/click.ogg", 1, 1);
            if (app.get_player_manager().isKeyChanging() == false) {
                fox::Entity e;
                app.get_player_manager().setChangingKey(true);
                if (get_world().get_entity("key_right_gamepad_image", e)) {
                    e.set_enable(true);
                }
                if (get_world().get_entity("press_a_key_gamepad", e)) {
                    e.set_enable(true);
                }
                app.get_player_manager().setSelectedKey(fox::SelectedKey::KEY_GAMEPAD_RIGHT);
            }
        })
        .add<Animator>();
    text_rec4_gamepad.get<Animator>()->add_anim("Normal");
    text_rec4_gamepad.get<Animator>()->add_anim("Hover")
        .signal(0, [&app, this] { app.PlaySound("GroupEffect", "assets/sounds/hover.ogg", 0.2, 1); });

    auto text_rec5_gamepad = m_oWorld.new_entity("text_rec5_gamepad", false);
    text_rec5_gamepad
        .add<fox::Transform>(Vec3(460, 440, 0))
        .add<fox::Button>("assets/rec_key.png", [this, &app]{
            app.PlaySound("GroupEffect", "assets/sounds/click.ogg", 1, 1);
            if (app.get_player_manager().isKeyChanging() == false) {
                fox::Entity e;
                app.get_player_manager().setChangingKey(true);
                if (get_world().get_entity("key_bomb_gamepad_image", e)) {
                    e.set_enable(true);
                }
                if (get_world().get_entity("press_a_key_gamepad", e)) {
                    e.set_enable(true);
                }
                app.get_player_manager().setSelectedKey(fox::SelectedKey::KEY_GAMEPAD_BOMB);
            }
        })
        .add<Animator>();
    text_rec5_gamepad.get<Animator>()->add_anim("Normal");
    text_rec5_gamepad.get<Animator>()->add_anim("Hover")
        .signal(0, [&app, this] { app.PlaySound("GroupEffect", "assets/sounds/hover.ogg", 0.2, 1); });

    auto press_a_key_gamepad = m_oWorld.new_entity("press_a_key_gamepad", false);
    press_a_key_gamepad
        .add<ray::Text>("Press a button on your gamepad")
        .add<fox::Transform>(Vec3(275, 600, 0))
        .add<Animator>();
    press_a_key_gamepad.get<ray::Text>()->SetColor(ray::Color(255, 255, 255, 255)).SetFontSize(25);
    press_a_key_gamepad.get<Animator>()->add_anim("Blink")
        .loop(true)
        .add<std::uint8_t>()
            .apply(press_a_key_gamepad.get<ray::Text>()->GetColor().a)
            .then(0, 0)
            .then(1, 255)
            .then(2, 0);

    // TOUCHES

    auto key_up_text = m_oWorld.new_entity();
    key_up_text
        .add<ray::Text>("Key Up :")
        .add<fox::Transform>(Vec3(120, 250, 0));
    key_up_text.get<ray::Text>()->SetColor(ray::Color(255, 183, 3)).SetFontSize(25);

    auto key_down_text = m_oWorld.new_entity();
    key_down_text
        .add<ray::Text>("Key Down :")
        .add<fox::Transform>(Vec3(120, 300, 0));
    key_down_text.get<ray::Text>()->SetColor(ray::Color(255, 183, 3)).SetFontSize(25);

    auto key_left_text = m_oWorld.new_entity();
    key_left_text
        .add<ray::Text>("Key Left :")
        .add<fox::Transform>(Vec3(120, 350, 0));
    key_left_text.get<ray::Text>()->SetColor(ray::Color(255, 183, 3)).SetFontSize(25);

    auto key_right_text = m_oWorld.new_entity();
    key_right_text
        .add<ray::Text>("Key Right :")
        .add<fox::Transform>(Vec3(120, 400, 0));
    key_right_text.get<ray::Text>()->SetColor(ray::Color(255, 183, 3)).SetFontSize(25);

    auto key_bomb_text = m_oWorld.new_entity();
    key_bomb_text
        .add<ray::Text>("Key Bomb :")
        .add<fox::Transform>(Vec3(120, 450, 0));
    key_bomb_text.get<ray::Text>()->SetColor(ray::Color(255, 183, 3)).SetFontSize(25);



    // TEXT KEY


    auto key_up_text_key = m_oWorld.new_entity("key_up_text");
    key_up_text_key
        .add<ray::Text>(fox::Input::key_to_string(app.get_player_manager().getCurrentInput().m_Up))
        .add<fox::Transform>(Vec3(300, 250, 0));
    key_up_text_key.get<ray::Text>()->SetColor(ray::Color(0, 191, 255)).SetFontSize(25);

    auto key_down_text_key = m_oWorld.new_entity("key_down_text");
    key_down_text_key
        .add<ray::Text>(fox::Input::key_to_string(app.get_player_manager().getCurrentInput().m_Down))
        .add<fox::Transform>(Vec3(300, 300, 0));
    key_down_text_key.get<ray::Text>()->SetColor(ray::Color(0, 191, 255)).SetFontSize(25);

    auto key_left_text_key = m_oWorld.new_entity("key_left_text");
    key_left_text_key
        .add<ray::Text>(fox::Input::key_to_string(app.get_player_manager().getCurrentInput().m_Left))
        .add<fox::Transform>(Vec3(300, 350, 0));
    key_left_text_key.get<ray::Text>()->SetColor(ray::Color(0, 191, 255)).SetFontSize(25);

    auto key_right_text_key = m_oWorld.new_entity("key_right_text");
    key_right_text_key
        .add<ray::Text>(fox::Input::key_to_string(app.get_player_manager().getCurrentInput().m_Right))
        .add<fox::Transform>(Vec3(300, 400, 0));
    key_right_text_key.get<ray::Text>()->SetColor(ray::Color(0, 191, 255)).SetFontSize(25);

    auto key_bomb_text_key = m_oWorld.new_entity("key_bomb_text");
    key_bomb_text_key
        .add<ray::Text>(fox::Input::key_to_string(app.get_player_manager().getCurrentInput().m_putBomb))
        .add<fox::Transform>(Vec3(300, 450, 0));
    key_bomb_text_key.get<ray::Text>()->SetColor(ray::Color(0, 191, 255)).SetFontSize(25);


    // GAMEPAD BUTTON


    auto key_up_gamepad_image = m_oWorld.new_entity("key_up_gamepad_image", false);
    key_up_gamepad_image
        .add<fox::Image>(fox::Input::button_to_image(app.get_player_manager().getCurrentInput().m_Gamepad_Up))
        .add<fox::Transform>(Vec3(470, 243, 0));

    auto key_down_gamepad_image = m_oWorld.new_entity("key_down_gamepad_image", false);
    key_down_gamepad_image
        .add<fox::Image>(fox::Input::button_to_image(app.get_player_manager().getCurrentInput().m_Gamepad_Down))
        .add<fox::Transform>(Vec3(470, 293, 0));

    auto key_left_gamepad_image = m_oWorld.new_entity("key_left_gamepad_image", false);
    key_left_gamepad_image
        .add<fox::Image>(fox::Input::button_to_image(app.get_player_manager().getCurrentInput().m_Gamepad_Left))
        .add<fox::Transform>(Vec3(470, 343, 0));

    auto key_right_gamepad_image = m_oWorld.new_entity("key_right_gamepad_image", false);
    key_right_gamepad_image
        .add<fox::Image>(fox::Input::button_to_image(app.get_player_manager().getCurrentInput().m_Gamepad_Right))
        .add<fox::Transform>(Vec3(470, 393, 0));

    auto key_bomb_gamepad_image = m_oWorld.new_entity("key_bomb_gamepad_image", false);
    key_bomb_gamepad_image
        .add<fox::Image>(fox::Input::button_to_image(app.get_player_manager().getCurrentInput().m_Gamepad_putBomb))
        .add<fox::Transform>(Vec3(470, 443, 0));
}

void OptionScene::on_destroy(fox::Application& app) { }

void OptionScene::on_update(fox::Application& app)
{
    int save = 0;
    fox::Entity e;

    if (IsGamepadAvailable(app.get_player_manager().getCurrentId() - 1)) {
        if (get_world().get_entity("text_rec1_gamepad", e) && e.is_enable() == false)
            e.set_enable(true);
        if (get_world().get_entity("text_rec2_gamepad", e) && e.is_enable() == false)
            e.set_enable(true);
        if (get_world().get_entity("text_rec3_gamepad", e) && e.is_enable() == false)
            e.set_enable(true);
        if (get_world().get_entity("text_rec4_gamepad", e) && e.is_enable() == false)
            e.set_enable(true);
        if (get_world().get_entity("text_rec5_gamepad", e) && e.is_enable() == false)
            e.set_enable(true);
        if (get_world().get_entity("key_up_gamepad_image", e) && e.is_enable() == false)
            e.set_enable(true);
        if (get_world().get_entity("key_down_gamepad_image", e) && e.is_enable() == false)
            e.set_enable(true);
        if (get_world().get_entity("key_left_gamepad_image", e) && e.is_enable() == false)
            e.set_enable(true);
        if (get_world().get_entity("key_right_gamepad_image", e) && e.is_enable() == false)
            e.set_enable(true);
        if (get_world().get_entity("key_bomb_gamepad_image", e) && e.is_enable() == false)
            e.set_enable(true);
    } else {
        if (get_world().get_entity("text_rec1_gamepad", e) && e.is_enable() == true)
            e.set_enable(false);
        if (get_world().get_entity("text_rec2_gamepad", e) && e.is_enable() == true)
            e.set_enable(false);
        if (get_world().get_entity("text_rec3_gamepad", e) && e.is_enable() == true)
            e.set_enable(false);
        if (get_world().get_entity("text_rec4_gamepad", e) && e.is_enable() == true)
            e.set_enable(false);
        if (get_world().get_entity("text_rec5_gamepad", e) && e.is_enable() == true)
            e.set_enable(false);
        if (get_world().get_entity("key_up_gamepad_image", e) && e.is_enable() == true)
            e.set_enable(false);
        if (get_world().get_entity("key_down_gamepad_image", e) && e.is_enable() == true)
            e.set_enable(false);
        if (get_world().get_entity("key_left_gamepad_image", e) && e.is_enable() == true)
            e.set_enable(false);
        if (get_world().get_entity("key_right_gamepad_image", e) && e.is_enable() == true)
            e.set_enable(false);
        if (get_world().get_entity("key_bomb_gamepad_image", e) && e.is_enable() == true)
            e.set_enable(false);
        if (get_world().get_entity("press_a_key_gamepad", e) && e.is_enable() == true)
            e.set_enable(false);
    }

    if (app.get_player_manager().isKeyChanging() == true)
    {
        if ((save = fox::Input::get_pressed_key()) > 0)
        {
            if (app.get_player_manager().isKeyFree(static_cast<KeyboardKey>(save)))
            {
                switch (app.get_player_manager().getSelectedKey())
                {
                    case fox::SelectedKey::KEY_UP:
                        if (get_world().get_entity("key_up_text", e))
                            e.get<ray::Text>()->SetString(fox::Input::key_to_string(static_cast<KeyboardKey>(save)));
                        app.get_player_manager().ChangeSpecificKey(static_cast<KeyboardKey>(save), fox::SelectedKey::KEY_UP);
                        break;
                    case fox::SelectedKey::KEY_DOWN:
                        if (get_world().get_entity("key_down_text", e))
                            e.get<ray::Text>()->SetString(fox::Input::key_to_string(static_cast<KeyboardKey>(save)));
                        app.get_player_manager().ChangeSpecificKey(static_cast<KeyboardKey>(save), fox::SelectedKey::KEY_DOWN);
                        break;
                    case fox::SelectedKey::KEY_LEFT:
                        if (get_world().get_entity("key_left_text", e))
                            e.get<ray::Text>()->SetString(fox::Input::key_to_string(static_cast<KeyboardKey>(save)));
                        app.get_player_manager().ChangeSpecificKey(static_cast<KeyboardKey>(save), fox::SelectedKey::KEY_LEFT);
                        break;
                    case fox::SelectedKey::KEY_RIGHT:
                        if (get_world().get_entity("key_right_text", e))
                            e.get<ray::Text>()->SetString(fox::Input::key_to_string(static_cast<KeyboardKey>(save)));
                        app.get_player_manager().ChangeSpecificKey(static_cast<KeyboardKey>(save), fox::SelectedKey::KEY_RIGHT);
                        break;
                    case fox::SelectedKey::KEY_BOMB:
                        if (get_world().get_entity("key_bomb_text", e))
                            e.get<ray::Text>()->SetString(fox::Input::key_to_string(static_cast<KeyboardKey>(save)));
                        app.get_player_manager().ChangeSpecificKey(static_cast<KeyboardKey>(save), fox::SelectedKey::KEY_BOMB);
                        break;
                    default:
                        break;
                }
                if (get_world().get_entity("press_a_key", e) && e.is_enable() == true)
                    e.set_enable(false);
                app.get_player_manager().setChangingKey(false);
                app.get_player_manager().setSelectedKey(fox::SelectedKey::NONE);
            } else
                std::cout << "This keyboard key is already taken." << std::endl;
        }
        if (IsGamepadAvailable(app.get_player_manager().getCurrentId() - 1))
        {
            if ((save = app.get_player_manager().getCurrentInput().pad.GetPressedButtonOnSpecificPad()) != -0)
            {
                if (app.get_player_manager().isButtonFree(save, app.get_player_manager().getCurrentId()))
                {
                    switch (app.get_player_manager().getSelectedKey())
                    {
                        case fox::SelectedKey::KEY_GAMEPAD_UP:
                            if (get_world().get_entity("key_up_gamepad_image", e))
                                e.get<fox::Image>()->sprite().Unload();
                                e.get<fox::Image>()->sprite().Load(fox::Input::button_to_image(save));
                            app.get_player_manager().ChangeSpecificButton(save, fox::SelectedKey::KEY_GAMEPAD_UP);
                            break;
                        case fox::SelectedKey::KEY_GAMEPAD_DOWN:
                            if (get_world().get_entity("key_down_gamepad_image", e))
                                e.get<fox::Image>()->sprite().Unload();
                                e.get<fox::Image>()->sprite().Load(fox::Input::button_to_image(save));
                            app.get_player_manager().ChangeSpecificButton(save, fox::SelectedKey::KEY_GAMEPAD_DOWN);
                            break;
                        case fox::SelectedKey::KEY_GAMEPAD_LEFT:
                            if (get_world().get_entity("key_left_gamepad_image", e))
                                e.get<fox::Image>()->sprite().Unload();
                                e.get<fox::Image>()->sprite().Load(fox::Input::button_to_image(save));
                            app.get_player_manager().ChangeSpecificButton(save, fox::SelectedKey::KEY_GAMEPAD_LEFT);
                            break;
                        case fox::SelectedKey::KEY_GAMEPAD_RIGHT:
                            if (get_world().get_entity("key_right_gamepad_image", e))
                                e.get<fox::Image>()->sprite().Unload();
                                e.get<fox::Image>()->sprite().Load(fox::Input::button_to_image(save));
                            app.get_player_manager().ChangeSpecificButton(save, fox::SelectedKey::KEY_GAMEPAD_RIGHT);
                            break;
                        case fox::SelectedKey::KEY_GAMEPAD_BOMB:
                            if (get_world().get_entity("key_bomb_gamepad_image", e))
                                e.get<fox::Image>()->sprite().Unload();
                                e.get<fox::Image>()->sprite().Load(fox::Input::button_to_image(save));
                            app.get_player_manager().ChangeSpecificButton(save, fox::SelectedKey::KEY_GAMEPAD_BOMB);
                            break;
                        default:
                            break;
                    }
                    if (get_world().get_entity("press_a_key_gamepad", e) && e.is_enable() == true)
                        e.set_enable(false);
                    app.get_player_manager().setChangingKey(false);
                    app.get_player_manager().setSelectedKey(fox::SelectedKey::NONE);
                } else
                    std::cout << "This keyboard key is already taken." << std::endl;
            }
        }
    }
    if (fox::Input::get_key_down(KEY_F5))
        ray::Window::TakeAScreenshot();
}

void OptionScene::on_disable(fox::Application& app)
{
    app.StopSound("assets/sounds/Option.ogg");
}
