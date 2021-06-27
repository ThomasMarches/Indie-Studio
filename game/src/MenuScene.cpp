/*
** EPITECH PROJECT, 2021
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** MenuScene
*/

#include "raylib-cpp.hpp"
#include "FoxEngine.hpp"
#include "MenuScene.hpp"

MenuScene::MenuScene() : fox::Scene() { }

MenuScene::MenuScene(const std::string& name) : fox::Scene(name) { }

MenuScene::~MenuScene() { }

void MenuScene::on_create(fox::Application& app) { }

void MenuScene::on_enable(fox::Application& app)
{
    app.PlaySound("MusicEffect", "assets/sounds/Menu.ogg", 0.5, 1);

    auto wallpaper = m_oWorld.new_entity();
    wallpaper
        .add<ray::Texture>("assets/menu/paper.png")
        .add<fox::Transform>(Vec3(0, 40, 0));

    // HEADER

    auto main_header = m_oWorld.new_entity();
    main_header
        .add<ray::Texture>("assets/rectangle.png")
        .add<fox::Transform>(Vec3(0, 0, 0));
    main_header.get<fox::Transform>()->scale = Vec3(2.2, 1, 0);

    auto main_image = m_oWorld.new_entity();
    main_image
        .add<fox::Image>("assets/menu/home.png")
        .add<fox::Transform>();
    main_image.get<fox::Transform>()->set_parent(main_header.get<fox::Transform>().value());
    main_image.get<fox::Transform>()->set_pos(9, 9, 0);

    auto main_txt = m_oWorld.new_entity();
    main_txt
        .add<ray::Text>("Main Menu")
        .add<fox::Transform>();
    main_txt.get<fox::Transform>()->set_parent(main_header.get<fox::Transform>().value());
    main_txt.get<fox::Transform>()->set_pos(550, 15, 0);
    main_txt.get<ray::Text>()->SetColor(ray::Color(0, 191, 255)).SetFontSize(40);

    // PLAY BUTTON

    auto play_btn = m_oWorld.new_entity();
    play_btn
        .add<Animator>()
        .add<fox::Button>("assets/menu/menu_button.png", [&app]
        {
            app.PlaySound("GroupEffect", "assets/sounds/click.ogg", 1, 1);
            app.switch_to("SelectPlayer");
        })
        .add<fox::Transform>(Vec3(695, 240, 0));
    Timeline &normal_anim_play = play_btn.get<Animator>()->add_anim("Normal");
    Timeline &hover_anim_play = play_btn.get<Animator>()->add_anim("Hover");
        normal_anim_play.add<Vec3>()
            .apply(play_btn.get<fox::Transform>()->position)
            .then(0, Vec3(695, 240, 0))
            .then(1, Vec3(695, 240, 0));
        normal_anim_play.add<Vec3>()
            .apply(play_btn.get<fox::Transform>()->scale)
            .then(0, Vec3(1, 1, 1))
            .then(1, Vec3(1, 1, 1));
        hover_anim_play
            .signal(0, [&app, this] { app.PlaySound("GroupEffect", "assets/sounds/hover.ogg", 0.2, 1); })
            .add<Vec3>()
                .apply(play_btn.get<fox::Transform>()->position)
                .then(0, Vec3(660, 240, 0))
                .then(1, Vec3(660, 240, 0));
        hover_anim_play
            .add<Vec3>()
                .apply(play_btn.get<fox::Transform>()->scale)
                .then(0, Vec3(1.1, 1, 1))
                .then(1, Vec3(1.1, 1, 1));

    auto play_btn_image = m_oWorld.new_entity();
    play_btn_image
        .add<fox::Image>("assets/menu/play.png")
        .add<fox::Transform>();
    play_btn_image.get<fox::Transform>()->set_parent(play_btn.get<fox::Transform>().value());
    play_btn_image.get<fox::Transform>()->set_pos(9, 9, 0);

    auto play_btn_text = m_oWorld.new_entity();
    play_btn_text
        .add<ray::Text>("Play")
        .add<fox::Transform>();
    play_btn_text.get<fox::Transform>()->set_parent(play_btn.get<fox::Transform>().value());
    play_btn_text.get<fox::Transform>()->set_pos(100, 20, 0);
    play_btn_text.get<ray::Text>()->SetColor(ray::Color(255, 255, 255, 255)).SetFontSize(30);

    // OPTION BUTTON

    auto option_btn = m_oWorld.new_entity();
    option_btn
        .add<Animator>()
        .add<fox::Button>("assets/menu/menu_button.png", [&app]
        {
            app.PlaySound("GroupEffect", "assets/sounds/click.ogg", 1, 1);
            app.switch_to("Option");
        })
        .add<fox::Transform>(Vec3(695, 330, 0));
    Timeline &normal_anim_opt = option_btn.get<Animator>()->add_anim("Normal");
    Timeline &hover_anim_opt = option_btn.get<Animator>()->add_anim("Hover");
        normal_anim_opt.add<Vec3>()
            .apply(option_btn.get<fox::Transform>()->position)
            .then(0, Vec3(695, 330, 0))
            .then(1, Vec3(695, 330, 0));
        normal_anim_opt.add<Vec3>()
            .apply(option_btn.get<fox::Transform>()->scale)
            .then(0, Vec3(1, 1, 1))
            .then(1, Vec3(1, 1, 1));
        hover_anim_opt
        .signal(0, [&app, this] { app.PlaySound("GroupEffect", "assets/sounds/hover.ogg", 0.2, 1); })
        .add<Vec3>()
            .apply(option_btn.get<fox::Transform>()->position)
            .then(0, Vec3(660, 330, 0))
            .then(1, Vec3(660, 330, 0));
        hover_anim_opt.add<Vec3>()
            .apply(option_btn.get<fox::Transform>()->scale)
            .then(0, Vec3(1.1, 1, 1))
            .then(1, Vec3(1.1, 1, 1));

    auto option_btn_image = m_oWorld.new_entity();
    option_btn_image
        .add<fox::Image>("assets/menu/options.png")
        .add<fox::Transform>();
    option_btn_image.get<fox::Transform>()->set_parent(option_btn.get<fox::Transform>().value());
    option_btn_image.get<fox::Transform>()->set_pos(9, 9, 0);

    auto option_btn_text = m_oWorld.new_entity();
    option_btn_text
        .add<ray::Text>("Options")
        .add<fox::Transform>();
    option_btn_text.get<fox::Transform>()->set_parent(option_btn.get<fox::Transform>().value());
    option_btn_text.get<fox::Transform>()->set_pos(100, 20, 0);
    option_btn_text.get<ray::Text>()->SetColor(ray::Color(255, 255, 255, 255)).SetFontSize(30);

    // HOW TO PLAY BUTTON

    auto how_to_play_btn = m_oWorld.new_entity();
    how_to_play_btn
        .add<Animator>()
        .add<fox::Button>("assets/menu/menu_button.png", [&app]
        {
            app.PlaySound("GroupEffect", "assets/sounds/click.ogg", 1, 1);
            app.switch_to("HowToPlay");
        })
        .add<fox::Transform>(Vec3(695, 420, 0));
    Timeline &normal_anim_how = how_to_play_btn.get<Animator>()->add_anim("Normal");
    Timeline &hover_anim_how = how_to_play_btn.get<Animator>()->add_anim("Hover");
        normal_anim_how.add<Vec3>()
            .apply(how_to_play_btn.get<fox::Transform>()->position)
            .then(0, Vec3(695, 420, 0))
            .then(1, Vec3(695, 420, 0));
        normal_anim_how.add<Vec3>()
            .apply(how_to_play_btn.get<fox::Transform>()->scale)
            .then(0, Vec3(1, 1, 1))
            .then(1, Vec3(1, 1, 1));
        hover_anim_how
        .signal(0, [&app, this] { app.PlaySound("GroupEffect", "assets/sounds/hover.ogg", 0.2, 1); })
        .add<Vec3>()
            .apply(how_to_play_btn.get<fox::Transform>()->position)
            .then(0, Vec3(660, 420, 0))
            .then(1, Vec3(660, 420, 0));
        hover_anim_how.add<Vec3>()
            .apply(how_to_play_btn.get<fox::Transform>()->scale)
            .then(0, Vec3(1.1, 1, 1))
            .then(1, Vec3(1.1, 1, 1));

    auto how_to_play_btn_image = m_oWorld.new_entity();
    how_to_play_btn_image
        .add<fox::Image>("assets/menu/howto.png")
        .add<fox::Transform>();
    how_to_play_btn_image.get<fox::Transform>()->set_parent(how_to_play_btn.get<fox::Transform>().value());
    how_to_play_btn_image.get<fox::Transform>()->set_pos(9, 9, 0);

    auto how_to_play_btn_text = m_oWorld.new_entity();
    how_to_play_btn_text
        .add<ray::Text>("How To Play")
        .add<fox::Transform>();
    how_to_play_btn_text.get<fox::Transform>()->set_parent(how_to_play_btn.get<fox::Transform>().value());
    how_to_play_btn_text.get<fox::Transform>()->set_pos(100, 20, 0);
    how_to_play_btn_text.get<ray::Text>()->SetColor(ray::Color(255, 255, 255, 255)).SetFontSize(30);

    // QUIT BUTTON

    auto quit_btn = m_oWorld.new_entity();
    quit_btn
        .add<Animator>()
        .add<fox::Button>("assets/menu/menu_button.png", [&app]
        {
            app.PlaySound("GroupEffect", "assets/sounds/click.ogg", 1, 1);
            app.quit();
        })
        .add<fox::Transform>(Vec3(695, 510, 0));
    Timeline &normal_anim_quit = quit_btn.get<Animator>()->add_anim("Normal");
    Timeline &hover_anim_quit = quit_btn.get<Animator>()->add_anim("Hover");
        normal_anim_quit.add<Vec3>()
            .apply(quit_btn.get<fox::Transform>()->position)
            .then(0, Vec3(695, 510, 0))
            .then(1, Vec3(695, 510, 0));
        normal_anim_quit.add<Vec3>()
            .apply(quit_btn.get<fox::Transform>()->scale)
            .then(0, Vec3(1, 1, 1))
            .then(1, Vec3(1, 1, 1));
        hover_anim_quit
        .signal(0, [&app, this] { app.PlaySound("GroupEffect", "assets/sounds/hover.ogg", 0.2, 1); })
        .add<Vec3>()
            .apply(quit_btn.get<fox::Transform>()->position)
            .then(0, Vec3(660, 510, 0))
            .then(1, Vec3(660, 510, 0));
        hover_anim_quit.add<Vec3>()
            .apply(quit_btn.get<fox::Transform>()->scale)
            .then(0, Vec3(1.1, 1, 1))
            .then(1, Vec3(1.1, 1, 1));


    auto quit_btn_image = m_oWorld.new_entity();
    quit_btn_image
        .add<fox::Image>("assets/menu/exit.png")
        .add<fox::Transform>();
    quit_btn_image.get<fox::Transform>()->set_parent(quit_btn.get<fox::Transform>().value());
    quit_btn_image.get<fox::Transform>()->set_pos(9, 9, 0);

    auto quit_btn_text = m_oWorld.new_entity();
    quit_btn_text
        .add<ray::Text>("Quit")
        .add<fox::Transform>();
    quit_btn_text.get<fox::Transform>()->set_parent(quit_btn.get<fox::Transform>().value());
    quit_btn_text.get<fox::Transform>()->set_pos(100, 20, 0);
    quit_btn_text.get<ray::Text>()->SetColor(ray::Color(255, 255, 255, 255)).SetFontSize(30);
}

void MenuScene::on_destroy(fox::Application& app) { }
void MenuScene::on_update(fox::Application& app)
{
    if (fox::Input::get_key_down(KEY_F5))
        ray::Window::TakeAScreenshot();
}

void MenuScene::on_disable(fox::Application& app)
{
    app.StopSound("assets/sounds/Menu.ogg");
}
