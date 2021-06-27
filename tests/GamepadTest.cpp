/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** GamepadTest.cpp
*/

#include <gtest/gtest.h>
#include "../Fox/include/raylib-cpp/Gamepad.hpp"

TEST(GamepadTest, GetPadNumber)
{
    ray::Gamepad pad = ray::Gamepad(0);

    EXPECT_EQ(pad.GetPadNumber(), 0) << "[GTEST]: ray::Gamepad GetPadNumber() test failed.";
}

TEST(GamepadTest, OperatorEqualEqual)
{
    ray::Gamepad pad = ray::Gamepad(1);
    ray::Gamepad pad2;

    pad2 = pad;
    EXPECT_EQ(pad2.GetPadNumber(), 1) << "[GTEST]: ray::Gamepad operator=(ray::Gamepad) && GetPadNumber() test failed.";
}

TEST(GamepadTest, OperatorEqual)
{
    ray::Gamepad pad = ray::Gamepad(1);

    pad = 2;
    EXPECT_EQ(pad.GetPadNumber(), 2) << "[GTEST]: ray::Gamepad operator=(int) with int && GetPadNumber() test failed.";
}

TEST(GamepadTest, IsAvailable)
{
    ray::Gamepad pad;

    EXPECT_FALSE(pad.IsAvailable()) << "[GTEST]: ray::Gamepad isAvailable() test failed. PLEASE DONT PLUG ANY GAMEPADS FOR THOSE TESTS";
}

TEST(GamepadTest, IsMouseButtonDownWithoutPad)
{
    ray::Gamepad pad;

    EXPECT_FALSE(pad.IsButtonDown(2)) << "[GTEST]: ray::Gamepad IsButtonDown() without gamepad test failed. PLEASE DONT PLUG ANY GAMEPADS FOR THOSE TESTS";
}

TEST(GamepadTest, IsMouseButtonPressedWithoutPad)
{
    ray::Gamepad pad;

    EXPECT_FALSE(pad.IsButtonPressed(2)) << "[GTEST]: ray::Gamepad IsButtonPressed() without gamepad test failed. PLEASE DONT PLUG ANY GAMEPADS FOR THOSE TESTS";
}

TEST(GamepadTest, IsMouseButtonReleasedWithoutPad)
{
    ray::Gamepad pad;

    EXPECT_FALSE(pad.IsButtonReleased(2)) << "[GTEST]: ray::Gamepad IsButtonReleased() without gamepad test failed. PLEASE DONT PLUG ANY GAMEPADS FOR THOSE TESTS";
}

TEST(GamepadTest, IsButtonUpWithoutPad)
{
    ray::Gamepad pad;

    EXPECT_FALSE(pad.IsButtonUp(2)) << "[GTEST]: ray::Gamepad IsButtonUp() without gamepad test failed. PLEASE DONT PLUG ANY GAMEPADS FOR THOSE TESTS";
}

TEST(GamepadTest, GetAxisCountWithoutPad)
{
    ray::Gamepad pad = ray::Gamepad(0);

    EXPECT_EQ(pad.GetAxisCount(), 0) << "[GTEST]: ray::Gamepad GetAxisCount() without gamepad test failed. PLEASE DONT PLUG ANY GAMEPADS FOR THOSE TESTS";
}

TEST(GamepadTest, GetButtonPressedWithoutPad)
{
    ray::Gamepad pad = ray::Gamepad(0);

    EXPECT_EQ(pad.GetButtonPressed(), 0) << "[GTEST]: ray::Gamepad GetButtonPressed() without gamepad test failed. PLEASE DONT PLUG ANY GAMEPADS FOR THOSE TESTS";
}