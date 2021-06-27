/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** PlayerInputTest.cpp
*/

#include <gtest/gtest.h>
#include "../Fox/include/Core/PlayerManager.hpp"
#include "../Fox/include/Components/PlayerInput.h"
#include "../Fox/include/raylib-cpp/Gamepad.hpp"

TEST(PlayerManagerTest, GetInputs)
{
    PlayerInput input1;
    PlayerInput input2;
    PlayerInput input3;

    input1.m_Down = KEY_DOWN;
    input1.m_putBomb = KEY_SPACE;
    input1.m_Up = KEY_UP;
    input1.m_Left = KEY_LEFT;
    input1.m_Right = KEY_RIGHT;

    std::unordered_map<std::string, PlayerInput> list = {{"player1", input1}, {"player2", input2}, {"player3", input3}};
    fox::PlayerManager manager = fox::PlayerManager(std::move(list));
    std::unordered_map<std::string, PlayerInput> anotherList;

    EXPECT_EQ(manager.getInput("player1"), input1) << "[GTEST]: fox::PlayerManager GetInput() test failed";
    anotherList = manager.getInputs();
    EXPECT_EQ(anotherList.at("player1"), list.at("player1")) << "[GTEST]: fox::PlayerManager constructor constructor && getInputs() test failed.";
    EXPECT_EQ(anotherList.at("player2"), list.at("player2")) << "[GTEST]: fox::PlayerManager constructor constructor && getInputs() test failed.";
    EXPECT_EQ(anotherList.at("player3"), list.at("player3")) << "[GTEST]: fox::PlayerManager constructor constructor && getInputs() test failed.";
    EXPECT_EQ(anotherList.at("player1").m_Down, list.at("player1").m_Down) << "[GTEST]: fox::PlayerManager constructor && getInputs() test failed.";
    EXPECT_EQ(anotherList.at("player1").m_Up, list.at("player1").m_Up) << "[GTEST]: fox::PlayerManager constructor && getInputs() test failed.";
    EXPECT_EQ(anotherList.at("player1").m_putBomb, list.at("player1").m_putBomb) << "[GTEST]: fox::PlayerManager constructor && getInputs() test failed.";
    EXPECT_EQ(anotherList.at("player1").m_Right, list.at("player1").m_Right) << "[GTEST]: fox::PlayerManager constructor && getInputs() test failed.";
    EXPECT_EQ(anotherList.at("player1").m_Left, list.at("player1").m_Left) << "[GTEST]: fox::PlayerManager constructor && getInputs() test failed.";
    EXPECT_EQ(anotherList.at("player1").pad, list.at("player1").pad) << "[GTEST]: fox::PlayerManager constructor && getInputs() test failed.";
}

TEST(PlayerManagerTest, IsKeyChanging)
{
    fox::PlayerManager manager;

    EXPECT_FALSE(manager.isKeyChanging()) << "[GTEST]: fox::PlayerManager isKeyChanging() test failed";
    manager.setChangingKey(true);
    EXPECT_TRUE(manager.isKeyChanging()) << "[GTEST]: fox::PlayerManager setChangingKey() && isKeyChanging() test failed";
}

TEST(PlayerManagerTest, GetSelectedKey)
{
    fox::PlayerManager manager;

    manager.setSelectedKey(fox::SelectedKey::NONE);
    EXPECT_EQ(manager.getSelectedKey(), fox::SelectedKey::NONE) << "[GTEST]: fox::PlayerManager getSelectedKey() test failed";
    manager.setSelectedKey(fox::SelectedKey::KEY_BOMB);
    EXPECT_EQ(manager.getSelectedKey(), fox::SelectedKey::KEY_BOMB) << "[GTEST]: fox::PlayerManager getSelectedKey() test failed";
    manager.setSelectedKey(fox::SelectedKey::KEY_UP);
    EXPECT_EQ(manager.getSelectedKey(), fox::SelectedKey::KEY_UP) << "[GTEST]: fox::PlayerManager getSelectedKey() test failed";
    manager.setSelectedKey(fox::SelectedKey::KEY_DOWN);
    EXPECT_EQ(manager.getSelectedKey(), fox::SelectedKey::KEY_DOWN) << "[GTEST]: fox::PlayerManager getSelectedKey() test failed";
    manager.setSelectedKey(fox::SelectedKey::KEY_LEFT);
    EXPECT_EQ(manager.getSelectedKey(), fox::SelectedKey::KEY_LEFT) << "[GTEST]: fox::PlayerManager getSelectedKey() test failed";
    manager.setSelectedKey(fox::SelectedKey::KEY_RIGHT);
    EXPECT_EQ(manager.getSelectedKey(), fox::SelectedKey::KEY_RIGHT) << "[GTEST]: fox::PlayerManager getSelectedKey() test failed";
}

TEST(PlayerManagerTest, GetCurrentInput)
{
    PlayerInput input1;
    PlayerInput input2;
    std::unordered_map<std::string, PlayerInput> list = {{"player1", input1}, {"player2", input2}};
    fox::PlayerManager manager = fox::PlayerManager(std::move(list));

    manager.setCurrent(1);
    EXPECT_EQ(manager.getCurrentInput(), input1) << "[GTEST]: fox::PlayerManager getCurrentInput() test failed";
    EXPECT_EQ(manager.getCurrentId(), 1) << "[GTEST]: fox::PlayerManager getCurrentId() test failed";
    manager.setCurrent(2);
    EXPECT_EQ(manager.getCurrentInput(), input2) << "[GTEST]: fox::PlayerManager getCurrentInput() test failed";
    EXPECT_EQ(manager.getCurrentId(), 2) << "[GTEST]: fox::PlayerManager getCurrentId() test failed";
}

TEST(PlayerManagerTest, ChangeSpecificKey)
{
    PlayerInput input1;
    std::unordered_map<std::string, PlayerInput> list = {{"player1", input1}};
    fox::PlayerManager manager = fox::PlayerManager(std::move(list));

    manager.ChangeSpecificKey(KEY_SPACE, fox::SelectedKey::KEY_UP);
    EXPECT_EQ(manager.getInput("player1").m_Up, KEY_SPACE) << "[GTEST]: fox::PlayerManager ChangeSpecificKey() test failed";
    manager.ChangeSpecificKey(KEY_SPACE, fox::SelectedKey::KEY_BOMB);
    EXPECT_EQ(manager.getInput("player1").m_putBomb, KEY_SPACE) << "[GTEST]: fox::PlayerManager ChangeSpecificKey() test failed";
    manager.ChangeSpecificKey(KEY_SPACE, fox::SelectedKey::KEY_LEFT);
    EXPECT_EQ(manager.getInput("player1").m_Left, KEY_SPACE) << "[GTEST]: fox::PlayerManager ChangeSpecificKey() test failed";
    manager.ChangeSpecificKey(KEY_SPACE, fox::SelectedKey::KEY_RIGHT);
    EXPECT_EQ(manager.getInput("player1").m_Right, KEY_SPACE) << "[GTEST]: fox::PlayerManager ChangeSpecificKey() test failed";
    manager.ChangeSpecificKey(KEY_SPACE, fox::SelectedKey::KEY_DOWN);
    EXPECT_EQ(manager.getInput("player1").m_Down, KEY_SPACE) << "[GTEST]: fox::PlayerManager ChangeSpecificKey() test failed";
}

TEST(PlayerManagerTest, ChangeSpecificButton)
{
    PlayerInput input1;
    PlayerInput input2;
    ray::Gamepad pad = 1;
    std::unordered_map<std::string, PlayerInput> list = {{"player1", input1}, {"player2", input2}};
    fox::PlayerManager manager = fox::PlayerManager(std::move(list));

    manager.setCurrent(2);
    manager.ChangeSpecificButton(1, fox::SelectedKey::KEY_GAMEPAD_UP);
    EXPECT_EQ(manager.getInput("player2").m_Gamepad_Up, 1) << "[GTEST]: fox::PlayerManager ChangeSpecificButton() test failed";
    manager.ChangeSpecificButton(1, fox::SelectedKey::KEY_GAMEPAD_BOMB);
    EXPECT_EQ(manager.getInput("player2").m_Gamepad_putBomb, 1) << "[GTEST]: fox::PlayerManager ChangeSpecificButton() test failed";
    manager.ChangeSpecificButton(1, fox::SelectedKey::KEY_GAMEPAD_LEFT);
    EXPECT_EQ(manager.getInput("player2").m_Gamepad_Left, 1) << "[GTEST]: fox::PlayerManager ChangeSpecificButton() test failed";
    manager.ChangeSpecificButton(1, fox::SelectedKey::KEY_GAMEPAD_RIGHT);
    EXPECT_EQ(manager.getInput("player2").m_Gamepad_Right, 1) << "[GTEST]: fox::PlayerManager ChangeSpecificButton() test failed";
    manager.ChangeSpecificButton(1, fox::SelectedKey::KEY_GAMEPAD_DOWN);
    EXPECT_EQ(manager.getInput("player2").m_Gamepad_Down, 1) << "[GTEST]: fox::PlayerManager ChangeSpecificButton() test failed";
}