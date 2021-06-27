/*
** EPITECH PROJECT, 2021
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** HowToPlayScene
*/

#include "raylib-cpp.hpp"
#include "FoxEngine.hpp"
#include "fstream"
#include "HowToPlayScene.hpp"
#include "raylib-cpp/Rectangle.hpp"

const std::vector<std::string> how_to_play_texts = {
    "Select what you want to do.",
    "You can choose your character and change your username. If you want to save your score enter an username.",
    "Set your key bindings or your controller bindings.",
    "You can play with 3 others players in local on a procedural map who is going to be always different.",
    "Break the destructible walls with bombs and avoid the explosions.",
    "Take the power-up to upgrade either your bomb number, your bomb ray or your speed.",
    "You can find your highscore at the end of the game in the scoreboard menu."
};

int HowToPlayScene::get_how_to_play_text_index(bool choice)
{
    static int index = 0;

    if (choice == true) {
        if (index == MAX_HOW_TO_PLAY_INDEX - 1) // check HowToPlayScene.hpp to see the value
            index = 0;
        else
            index++;
    } else {
        if (index == 0)
            index = MAX_HOW_TO_PLAY_INDEX - 1;
        else
            index--;
    }
    return (index);
}

std::string HowToPlayScene::get_how_to_play_image(bool choice)
{
    static int index = 1;
    std::string buffer = "assets/how_to_play/htp";

    if (choice == true) {
        if (index == MAX_HOW_TO_PLAY_INDEX) // check HowToPlayScene.hpp to see the value
            index = 1;
        else
            index++;
    } else {
        if (index == 1)
            index = MAX_HOW_TO_PLAY_INDEX;
        else
            index--;
    }
    buffer = buffer + std::to_string(index) + ".png";
    return (buffer);
}

HowToPlayScene::HowToPlayScene() : fox::Scene() { }

HowToPlayScene::HowToPlayScene(const std::string &name) : fox::Scene(name) { }

HowToPlayScene::~HowToPlayScene() { }

void HowToPlayScene::on_create(fox::Application& app) { }

void HowToPlayScene::on_enable(fox::Application& app) {


    app.PlaySound("MusicEffect", "assets/sounds/how-to-play.ogg", 1, 1);

    // BACKGROUND


    auto background2 = m_oWorld.new_entity();
     background2
        .add<ray::Texture>("assets/menu/paper.png")
        .add<fox::Transform>(Vec3(30, 0, 0));

    auto background = m_oWorld.new_entity();
     background
        .add<ray::Texture>("assets/menu/paper.png")
        .add<fox::Transform>(Vec3(-500, 0, 0));

    auto main_header = m_oWorld.new_entity("Main header");
    main_header
        .add<ray::Texture>("assets/rectangle.png")
        .add<fox::Transform>(Vec3(0, 0, 0));
    main_header.get<fox::Transform>()->scale = Vec3(2.2, 1, 0);

    auto htp_image = m_oWorld.new_entity();
    htp_image
        .add<ray::Texture>("assets/howto.png")
        .add<fox::Transform>();
    htp_image.get<fox::Transform>()->set_parent(main_header.get<fox::Transform>().value());
    htp_image.get<fox::Transform>()->set_pos(9, 9, 0);

    auto htp_text = m_oWorld.new_entity();
    htp_text
        .add<ray::Text>("How To Play")
        .add<fox::Transform>(Vec3(510, 15, 0));
    htp_text.get<ray::Text>()->SetColor(ray::Color(0, 191, 255)).SetFontSize(40);

    // BANNER

    auto banner = m_oWorld.new_entity("Banner");
     banner
        .add<ray::Texture>("assets/rectangle.png")
        .add<fox::Transform>(Vec3(0, 655, 0));
    banner.get<fox::Transform>()->scale = Vec3(3, 1, 0);

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
        .signal(0, [&app, this] { app.PlaySound("GroupEffect", "assets/sounds/hover.ogg", 0.02, 1); })
        .add<Vec3>()
            .apply(go_back_to_menu.get<fox::Transform>()->scale)
            .then(0, Vec3(0.11, 0.11, 0.11))
            .then(1, Vec3(0.11, 0.11, 0.11));
    go_back_to_menu.get<fox::Button>()->sprite().SetColor(ray::Color(0, 191, 255));

    // RECT

    auto rec1 = m_oWorld.new_entity();
    rec1
        .add<fox::Transform>(Vec3(90, 100, 0))
        .add<ray::Rectangle>(100, 90, 1100, 500, ray::Color(255, 255, 255, 255));


    auto rec2 = m_oWorld.new_entity();
    rec2
        .add<fox::Transform>(Vec3(95, 105, 0))
        .add<ray::Rectangle>(105, 95, 1090, 490, ray::Color(0, 0, 0, 255));

    // ARROWS

    auto left_arrow = m_oWorld.new_entity();
     left_arrow
            .add<Animator>()
            .add<fox::Transform>(Vec3(10, 300, 0))
            .add<fox::Button>("assets/left_arrow.png", [this, &app]{
                fox::Entity e;
                Vec2 size;
                Vec3 scale;

                app.PlaySound("GroupEffect", "assets/sounds/click.ogg", 1, 1);
                if (get_world().get_entity("Image htp", e))
                {

                    e.get<fox::Image>()->sprite().Unload();
                    e.get<fox::Image>()->sprite().Load(get_how_to_play_image(false));
                    size = e.get<fox::Image>()->sprite().GetSize();
                    scale.x = 1090 / size.x;
                    scale.y = 490 / size.y;
                    e.get<fox::Transform>()->scale = scale;
                }
                if (get_world().get_entity("How to play text", e))
                {
                    e.get<ray::Text>()->SetString(how_to_play_texts.at(get_how_to_play_text_index(false)));
                }
            });

    left_arrow.get<fox::Button>()->sprite().SetColor(ray::Color(0, 191, 255));
    left_arrow.get<Animator>()->add_anim("Normal")
        .add<Vec3>()
            .apply(left_arrow.get<fox::Transform>()->scale)
            .then(0, Vec3(0.15, 0.15, 0))
            .then(1, Vec3(0.15, 0.15, 0));
    left_arrow.get<Animator>()->add_anim("Hover")
        .signal(0, [&app, this] { app.PlaySound("GroupEffect", "assets/sounds/hover.ogg", 0.02, 1); })
        .add<Vec3>()
            .apply(left_arrow.get<fox::Transform>()->scale)
            .then(0, Vec3(0.17, 0.17, 0))
            .then(1, Vec3(0.17, 0.17, 0));


    auto right_arrow = m_oWorld.new_entity();
     right_arrow
            .add<Animator>()
            .add<fox::Transform>(Vec3(1200, 300, 0))
            .add<fox::Button>("assets/right_arrow.png", [this, &app]{
                fox::Entity e;
                Vec2 size;
                Vec3 scale;

                app.PlaySound("GroupEffect", "assets/sounds/click.ogg", 1, 1);
                if (get_world().get_entity("Image htp", e))
                {
                    e.get<fox::Image>()->sprite().Unload();
                    e.get<fox::Image>()->sprite().Load(get_how_to_play_image(true));
                    size = e.get<fox::Image>()->sprite().GetSize();
                    scale.x = 1090 / size.x;
                    scale.y = 490 / size.y;
                    e.get<fox::Transform>()->scale = scale;
                }
                if (get_world().get_entity("How to play text", e))
                {
                    e.get<ray::Text>()->SetString(how_to_play_texts.at(get_how_to_play_text_index(true)));
                }
            });
    right_arrow.get<fox::Button>()->sprite().SetColor(ray::Color(0, 191, 255));
    right_arrow.get<Animator>()->add_anim("Normal")
        .add<Vec3>()
            .apply(right_arrow.get<fox::Transform>()->scale)
            .then(0, Vec3(0.15, 0.15, 0))
            .then(1, Vec3(0.15, 0.15, 0));
    right_arrow.get<Animator>()->add_anim("Hover")
        .signal(0, [&app, this] { app.PlaySound("GroupEffect", "assets/sounds/hover.ogg", 0.02, 1); })
        .add<Vec3>()
            .apply(right_arrow.get<fox::Transform>()->scale)
            .then(0, Vec3(0.17, 0.17, 0))
            .then(1, Vec3(0.17, 0.17, 0));


    // IMAGE HOW TO PLAY

    auto image_htp = m_oWorld.new_entity("Image htp");
    image_htp
        .add<fox::Image>("assets/how_to_play/htp1.png")
        .add<fox::Transform>(Vec3(95, 105, 0));
    image_htp.get<fox::Transform>()->scale = Vec3(0.5, 0.5, 0);

    Vec2 size;
    Vec3 scale;

    size = image_htp.get<fox::Image>()->sprite().GetSize();
    scale.x = 1090 / size.x;
    scale.y = 490 / size.y;
    image_htp.get<fox::Transform>()->scale = scale;


    // BANNER TEXTE

    auto banner_text = m_oWorld.new_entity("How to play text");
    banner_text
        .add<ray::Text>(how_to_play_texts.at(0))
        .add<fox::Transform>(Vec3(100, 670, 0));
        banner_text.get<ray::Text>()->SetColor(ray::Color(0, 191, 255)).SetFontSize(20);
}

void HowToPlayScene::on_destroy(fox::Application& app) { }
void HowToPlayScene::on_update(fox::Application& app)
{
    if (fox::Input::get_key_down(KEY_F5))
        ray::Window::TakeAScreenshot();
}

void HowToPlayScene::on_disable(fox::Application& app)
{
    app.StopSound("assets/sounds/how-to-play.ogg");
}
