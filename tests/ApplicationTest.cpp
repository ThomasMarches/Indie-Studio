/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** ApplicationTest.cpp
*/

#include <gtest/gtest.h>
#include "../Fox/include/Core/Application.hpp"
#include "../Fox/include/Core/SceneManager.hpp"
#include "../Fox/include/Core/Scene.hpp"
#include "../game/include/SandboxApp.hpp"

TEST(ApplicationTests, IsAppRunningTest)
{
    fox::Application app(0, NULL);

    EXPECT_TRUE(app.m_bIsRunning) << "[GTEST]: fox::Application IsAppRunning test failed.";
    app.quit();
    EXPECT_FALSE(app.m_bIsRunning) << "[GTEST]: fox::Application IsAppRunning test failed.";
}

TEST(ApplicationTests, CreateGroupTest)
{
    fox::Application app(0, NULL);

    app.CreateGroup("Music Group");
    EXPECT_EQ(app.getGroup("Music Group").getAudioName(), "Music Group") << "[GTEST]: fox::Application getGroup() test failed.";
}

TEST(ApplicationTests, IsKeyChangingTest)
{
    fox::Application app(0, NULL);

    EXPECT_FALSE(app.get_player_manager().isKeyChanging()) << "[GTEST]: fox::Application isKeyChanging() test failed.";
    app.get_player_manager().setChangingKey(true);
    EXPECT_TRUE(app.get_player_manager().isKeyChanging()) << "[GTEST]: fox::Application isKeyChanging() test failed.";
}