/*
** EPITECH PROJECT, 2021
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** SandboxApp
*/

#include "SandboxApp.hpp"
#include "EndScene.hpp"
#include "FoxEngine.hpp"
#include "GameScene.hpp"
#include "HowToPlayScene.hpp"
#include "MenuScene.hpp"
#include "OptionPauseScene.hpp"
#include "OptionScene.hpp"
#include "SelectionScene.hpp"
#include "SplashScreenScene.hpp"
#include "raylib-cpp.hpp"

SandboxApp::SandboxApp(int argc, char** argv) : fox::Application(argc, argv)
{
}

SandboxApp::~SandboxApp() {}

void SandboxApp::init()
{
    m_pSceneManager->add<SplashScreenScene>("SplashScreen");
    m_pSceneManager->add<MenuScene>("Menu");
    m_pSceneManager->add<OptionScene>("Option");
    m_pSceneManager->add<HowToPlayScene>("HowToPlay");
    m_pSceneManager->add<GameScene>("Game");
    m_pSceneManager->add<OptionPauseScene>("OptionPause");
    m_pSceneManager->add<SelectionScene>("SelectPlayer");
    m_pSceneManager->add<EndScene>("End");
    m_pSceneManager->switch_to("SplashScreen");

    m_pAudioManager->CreateGroup("GroupEffect");
    m_pAudioManager->CreateGroup("MusicEffect");
}

fox::Application* CreateApp(int argc, char** argv)
{
    return new SandboxApp(argc, argv);
}
