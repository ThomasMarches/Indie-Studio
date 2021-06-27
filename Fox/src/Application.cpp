/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Application.cpp
*/

#include <chrono>
#include "Core/Input/Input.hpp"
#include "Core/Application.hpp"
#include "raylib-cpp.hpp"
#include "Time.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include "json.hpp"
#include "Components/PlayerInput.h"
#include "FileSystem.hpp"

namespace fox
{
    template <>
    void json::deserialize(const fox::json::Value& j, KeyboardKey& obj)
    {
        obj = fox::Input::string_to_key(j.get<std::string>());
    }

    template <>
    void json::serialize(fox::json::Value& j, const KeyboardKey& obj)
    {
        j = fox::Input::key_to_string(obj);
    }

    template <>
    void json::serialize(fox::json::Value& j, const PlayerInput& obj)
    {
        j["KEY_UP"] = obj.m_Up;
        j["KEY_DOWN"] = obj.m_Down;
        j["KEY_LEFT"] = obj.m_Left;
        j["KEY_RIGHT"] = obj.m_Right;
        j["KEY_BOMB"] = obj.m_putBomb;
    }

    template <>
    void json::deserialize(const fox::json::Value& j, PlayerInput& obj)
    {
        obj.m_Up = j["KEY_UP"].get<KeyboardKey>();
        obj.m_Down = j["KEY_DOWN"].get<KeyboardKey>();
        obj.m_Left = j["KEY_LEFT"].get<KeyboardKey>();
        obj.m_Right = j["KEY_RIGHT"].get<KeyboardKey>();
        obj.m_putBomb = j["KEY_BOMB"].get<KeyboardKey>();
    }

    bool getInputFromJsonFile(std::unordered_map<std::string, PlayerInput> &inputs)
    {
        std::string out;
        fox::json::Value j_obj;
        if (file::ReadFile("game/config/input.json", out))
        {
            j_obj = fox::json::parse(out);
            inputs["player1"] = j_obj["player1"].get<PlayerInput>();
            inputs["player1"].pad = 0;
            inputs["player2"] = j_obj["player2"].get<PlayerInput>();
            inputs["player2"].pad = 1;
            inputs["player3"] = j_obj["player3"].get<PlayerInput>();
            inputs["player3"].pad = 2;
            inputs["player4"] = j_obj["player4"].get<PlayerInput>();
            inputs["player4"].pad = 3;
        } else {
            std::cout << "./bomberman: No such file";
            return false;
        }
        return (true);
    }
}

namespace fox
{
    Application::Application(int ac, char** av)
    {
        std::unordered_map<std::string, PlayerInput> inputs;

        m_bIsRunning = true;
        m_pResourceManager = new_scope<ResourceManager>();
        m_pSceneManager = new_scope<SceneManager>(*this);
        m_pAudioManager = new_scope<AudioManager>();
        m_pSaveManager = new_scope<SaveManager>();
        if (getInputFromJsonFile(inputs) != false) {
            m_pPlayerManager = new_scope<PlayerManager>(std::move(inputs));
        } else {
            m_bIsRunning = false;
        }
    }

    Application::~Application() {}

    void Application::init() {}

    void Application::quit()
    {
        m_bIsRunning = false;
    }

    void Application::run()
    {
        ray::Window window(1280, 720, "Bomberman");
        window.SetTargetFPS(60);
        InitAudioDevice();

        float fFixedDeltaTime = 0;
        float fFixedTimeStep = 1.f/60.f;
        float fDeltaTime = 0;
        auto lastUpdate = std::chrono::high_resolution_clock::now();

        init();
        while (m_bIsRunning)
        {
            if (window.ShouldClose())
                m_bIsRunning = false;

            auto now = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = now - lastUpdate;
            lastUpdate = now;

            fDeltaTime = elapsed.count();
            Time::delta_time = fDeltaTime;
            if (Time::delta_time > 0.25)
                Time::delta_time = 0.25;
            Time::time += fDeltaTime;

            fFixedDeltaTime += fDeltaTime;
            while (fFixedDeltaTime >= fFixedTimeStep)
            {
                m_pSceneManager->fix_update();
                Time::fixed_delta_time = fFixedDeltaTime;
                fFixedDeltaTime -= fFixedTimeStep;
            }
            Time::factor_physics = fFixedDeltaTime / fFixedTimeStep;

            m_pSceneManager->update();

            window.BeginDrawing();
            window.ClearBackground();
            DrawFPS(10, 10);
            m_pSceneManager->draw();
            window.EndDrawing();
        }
        m_pSceneManager.reset();
        m_pResourceManager.reset();
        CloseAudioDevice();

        fox::json::Value j = get_player_manager().getInputs();
        if (!file::WriteFile("game/config/input.json", j.dump()))
        {
            std::cerr << "./bomberman: Couldn't open json file for saving configurations." << std::endl;
        }
    }

    void Application::switch_to(const std::string &name)
    {
        m_pSceneManager->switch_to(name);
    }

    void Application::remove_scene(const std::string &name)
    {
        m_pSceneManager->remove(name);
    }

    Scene* Application::get_active()
    {
        return m_pSceneManager->get_active();
    }

    void Application::PlaySound(const std::string &group, const std::string &asset, float volume, float pitch)
    {
        m_pAudioManager->PlaySound(group, asset, volume, pitch);
    }

    void Application::PlayMusic(const std::string &group, const std::string &asset, float volume, float pitch)
    {
        m_pAudioManager->PlayMusic(group, asset, volume, pitch);
    }

    AudioGroup &Application::getGroup(const std::string &name)
    {
        return m_pAudioManager->getGroup(name);
    }

    void Application::CreateGroup(const std::string &name)
    {
        m_pAudioManager->CreateGroup(name);
    }

    void Application::StopSound(const std::string &asset)
    {
        m_pAudioManager->StopSound(asset);
    }

    // ResourceManager& Application::get_resource_manager() const
    // {
    //     return *m_pResourceManager;
    // }
}
