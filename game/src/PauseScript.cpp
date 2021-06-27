/*
** EPITECH PROJECT, 2021
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** BombScript
*/

#include "PauseScript.hpp"
#include "Components.hpp"
#include <GameScene.hpp>

PauseScript::PauseScript(bool &bIsPaused) : m_bIsPaused(bIsPaused)
{
    m_bIsPaused = true;
}

void PauseScript::on_create()
{
    auto wallpaper = get_world().new_entity();
    wallpaper
            .add<ray::Texture>("assets/blue_wall.png")
            .add<fox::Transform>(Vec3(0, 40, 0));
    m_vEntities.push_back(wallpaper.get_id());

    // HEADER

    auto main_header = get_world().new_entity();
    main_header
            .add<ray::Texture>("assets/rectangle.png")
            .add<fox::Transform>(Vec3(0, 0, 0));
    main_header.get<fox::Transform>()->scale = Vec3(2.2, 1, 0);
    m_vEntities.push_back(main_header.get_id());

    auto main_image = get_world().new_entity();
    main_image
            .add<fox::Image>("assets/pause.png")
            .add<fox::Transform>();
    main_image.get<fox::Transform>()->set_parent(main_header.get<fox::Transform>().value());
    main_image.get<fox::Transform>()->set_pos(9, 9, 0);
    m_vEntities.push_back(main_image.get_id());

    auto main_txt = get_world().new_entity();
    main_txt
            .add<ray::Text>("Pause Menu")
            .add<fox::Transform>();
    main_txt.get<fox::Transform>()->set_parent(main_header.get<fox::Transform>().value());
    main_txt.get<fox::Transform>()->set_pos(550, 15, 0);
    main_txt.get<ray::Text>()->SetColor(ray::Color(0, 191, 255)).SetFontSize(40);
    m_vEntities.push_back(main_txt.get_id());

    // PLAY BUTTON

    auto play_btn = get_world().new_entity();
    play_btn
            .add<Animator>()
            .add<fox::Button>("assets/menu_button2.png", [this]{destroy(); std::cout << "Destroy!" << std::endl; })
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
    hover_anim_play.add<Vec3>()
            .apply(play_btn.get<fox::Transform>()->position)
            .then(0, Vec3(660, 240, 0))
            .then(1, Vec3(660, 240, 0));
    hover_anim_play.add<Vec3>()
            .apply(play_btn.get<fox::Transform>()->scale)
            .then(0, Vec3(1.1, 1, 1))
            .then(1, Vec3(1.1, 1, 1));
    m_vEntities.push_back(play_btn.get_id());

    auto play_btn_image = get_world().new_entity();
    play_btn_image
            .add<fox::Image>("assets/menu/play.png")
            .add<fox::Transform>();
    play_btn_image.get<fox::Transform>()->set_parent(play_btn.get<fox::Transform>().value());
    play_btn_image.get<fox::Transform>()->set_pos(9, 9, 0);
    m_vEntities.push_back(play_btn_image.get_id());

    auto play_btn_text = get_world().new_entity();
    play_btn_text
            .add<ray::Text>("Play")
            .add<fox::Transform>();
    play_btn_text.get<fox::Transform>()->set_parent(play_btn.get<fox::Transform>().value());
    play_btn_text.get<fox::Transform>()->set_pos(100, 20, 0);
    play_btn_text.get<ray::Text>()->SetColor(ray::Color(255, 255, 255, 255)).SetFontSize(30);
    m_vEntities.push_back(play_btn_text.get_id());

    // OPTION BUTTON

    auto option_btn = get_world().new_entity();
    option_btn
            .add<Animator>()
            .add<fox::Button>("assets/menu_button2.png", [this]{ get_app().switch_to("OptionPause"); })
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
    hover_anim_opt.add<Vec3>()
            .apply(option_btn.get<fox::Transform>()->position)
            .then(0, Vec3(660, 330, 0))
            .then(1, Vec3(660, 330, 0));
    hover_anim_opt.add<Vec3>()
            .apply(option_btn.get<fox::Transform>()->scale)
            .then(0, Vec3(1.1, 1, 1))
            .then(1, Vec3(1.1, 1, 1));
    m_vEntities.push_back(option_btn.get_id());


    auto option_btn_image = get_world().new_entity();
    option_btn_image
            .add<fox::Image>("assets/menu/options.png")
            .add<fox::Transform>();
    option_btn_image.get<fox::Transform>()->set_parent(option_btn.get<fox::Transform>().value());
    option_btn_image.get<fox::Transform>()->set_pos(9, 9, 0);
    m_vEntities.push_back(option_btn_image.get_id());

    auto option_btn_text = get_world().new_entity();
    option_btn_text
            .add<ray::Text>("Options")
            .add<fox::Transform>();
    option_btn_text.get<fox::Transform>()->set_parent(option_btn.get<fox::Transform>().value());
    option_btn_text.get<fox::Transform>()->set_pos(100, 20, 0);
    option_btn_text.get<ray::Text>()->SetColor(ray::Color(255, 255, 255, 255)).SetFontSize(30);
    m_vEntities.push_back(option_btn_text.get_id());

    // HOW TO PLAY BUTTON

    auto how_to_play_btn = get_world().new_entity();
    how_to_play_btn
            .add<Animator>()
            .add<fox::Button>("assets/menu_button2.png", [this]
            {
                get_app().remove_scene("Game");
                  get_app().add_scene<GameScene>("Game");
                get_app().switch_to("Menu");
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
    hover_anim_how.add<Vec3>()
            .apply(how_to_play_btn.get<fox::Transform>()->position)
            .then(0, Vec3(660, 420, 0))
            .then(1, Vec3(660, 420, 0));
    hover_anim_how.add<Vec3>()
            .apply(how_to_play_btn.get<fox::Transform>()->scale)
            .then(0, Vec3(1.1, 1, 1))
            .then(1, Vec3(1.1, 1, 1));
    m_vEntities.push_back(how_to_play_btn.get_id());

    auto how_to_play_btn_image = get_world().new_entity();
    how_to_play_btn_image
            .add<fox::Image>("assets/menu/home.png")
            .add<fox::Transform>();
    how_to_play_btn_image.get<fox::Transform>()->set_parent(how_to_play_btn.get<fox::Transform>().value());
    how_to_play_btn_image.get<fox::Transform>()->set_pos(9, 9, 0);
    m_vEntities.push_back(how_to_play_btn_image.get_id());

    auto how_to_play_btn_text = get_world().new_entity();
    how_to_play_btn_text
            .add<ray::Text>("Go back to menu")
            .add<fox::Transform>();
    how_to_play_btn_text.get<fox::Transform>()->set_parent(how_to_play_btn.get<fox::Transform>().value());
    how_to_play_btn_text.get<fox::Transform>()->set_pos(100, 20, 0);
    how_to_play_btn_text.get<ray::Text>()->SetColor(ray::Color(255, 255, 255, 255)).SetFontSize(30);
    m_vEntities.push_back(how_to_play_btn_text.get_id());

    // QUIT BUTTON

    auto quit_btn = get_world().new_entity();
    quit_btn
            .add<Animator>()
            .add<fox::Button>("assets/menu_button2.png", [this]{get_app().quit();})
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
    hover_anim_quit.add<Vec3>()
            .apply(quit_btn.get<fox::Transform>()->position)
            .then(0, Vec3(660, 510, 0))
            .then(1, Vec3(660, 510, 0));
    hover_anim_quit.add<Vec3>()
            .apply(quit_btn.get<fox::Transform>()->scale)
            .then(0, Vec3(1.1, 1, 1))
            .then(1, Vec3(1.1, 1, 1));
    m_vEntities.push_back(quit_btn.get_id());


    auto quit_btn_image = get_world().new_entity();
    quit_btn_image
            .add<fox::Image>("assets/menu/exit.png")
            .add<fox::Transform>();
    quit_btn_image.get<fox::Transform>()->set_parent(quit_btn.get<fox::Transform>().value());
    quit_btn_image.get<fox::Transform>()->set_pos(9, 9, 0);
    m_vEntities.push_back(quit_btn_image.get_id());

    auto quit_btn_text = get_world().new_entity();
    quit_btn_text
            .add<ray::Text>("Quit")
            .add<fox::Transform>();
    quit_btn_text.get<fox::Transform>()->set_parent(quit_btn.get<fox::Transform>().value());
    quit_btn_text.get<fox::Transform>()->set_pos(100, 20, 0);
    quit_btn_text.get<ray::Text>()->SetColor(ray::Color(255, 255, 255, 255)).SetFontSize(30);
    m_vEntities.push_back(quit_btn_text.get_id());
}

void PauseScript::on_update() {}

void PauseScript::on_destroy()
{
    m_bIsPaused = false;

    for (auto& e : m_vEntities)
        get_world().delete_entity(e);
    m_vEntities.clear();

    auto& vEnt = get_world().get_entities();
    for (int i = 0; i < vEnt.size(); ++i)
    {
        get_world().enable_entity(vEnt[i], true);
    }
}