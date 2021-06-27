/*
** EPITECH PROJECT, 2021
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** SplashScreenScene
*/

#include "raylib-cpp.hpp"
#include "FoxEngine.hpp"
#include "SplashScreenScene.hpp"
#include "RaylibSplashScreenScript.hpp"

SplashScreenScene::SplashScreenScene() : fox::Scene() { }

SplashScreenScene::SplashScreenScene(const std::string& name) : fox::Scene(name) { }

SplashScreenScene::~SplashScreenScene() { }

void SplashScreenScene::on_create(fox::Application& app) { }

void SplashScreenScene::on_enable(fox::Application& app)
{
    app.PlaySound("MusicEffect", "assets/sounds/splashscreen.ogg", 1, 1);

    auto text_present = m_oWorld.new_entity();
    text_present.add<ray::Texture>("assets/epitech.png")
            .add<Animator>()
            .add<fox::Transform>(Vec3(250, 210, 0));
    text_present.get<Animator>()->add_anim("Idle")
        .add<std::uint8_t>()
            .apply(text_present.get<ray::Texture>()->GetColor().a)
            .then(0, 0)
            .then(15, 0)
            .then(17, 255)
            .then(19, 0);

    auto text_with = m_oWorld.new_entity();
    text_with
        .add<NativeScript>()
        .add<Animator>()
        .add<fox::Transform>(Vec3(0, 0, 0))
        .get<NativeScript>()->bind<RaylibSplashScreenScript>();

    auto splash_screen = m_oWorld.new_entity();
    splash_screen
        .add<ray::Texture>("assets/splash.png")
        .add<Animator>()
        .add<fox::Transform>(Vec3(64, 10, 0));
    splash_screen.get<Animator>()->add_anim("Idle")
        .add<std::uint8_t>()
            .apply(splash_screen.get<ray::Texture>()->GetColor().a)
            .then(0, 0)
            .then(21, 0)
            .then(25, 255);

    auto splash_screen_text = m_oWorld.new_entity();
    splash_screen_text
        .add<ray::Text>("Press space to play", ray::Color(230, 41, 55, 255))
        .add<Animator>()
        .add<fox::Transform>(Vec3(530, 680, 0));
    splash_screen_text.get<Animator>()->add_anim("Idle")
        .add<std::uint8_t>()
            .apply(splash_screen_text.get<ray::Text>()->GetColor().a)
            .then(0, 0)
            .then(21, 0)
            .then(25, 255);
}

void SplashScreenScene::on_destroy(fox::Application& app) { }
void SplashScreenScene::on_update(fox::Application& app)
{
    if (fox::Input::get_mouse_btn_down(MOUSE_LEFT_BUTTON)) {
        app.switch_to("Menu");
    } else if (fox::Input::get_key_down(KEY_SPACE)) {
        app.switch_to("Menu");
    }
    if (fox::Input::get_key_down(KEY_F5))
        ray::Window::TakeAScreenshot();
}

void SplashScreenScene::on_disable(fox::Application& app)
{
    app.StopSound("assets/sounds/splashscreen.ogg");
}
