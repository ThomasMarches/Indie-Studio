/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** KeyboardTest.cpp
*/

#include <gtest/gtest.h>
#include "../Fox/include/raylib-cpp/Keyboard.hpp"

TEST(KeyboardTest, KeyIsDownWithoutActions)
{
    ray::Keyboard keyboard;

    EXPECT_FALSE(keyboard.KeyIsDown(KEY_SPACE)) << "[GTEST]: ray::Keyboard IsKeyDown() function test failed.";
}

TEST(KeyboardTest, KeyIsPressedWithoutActions)
{
    ray::Keyboard keyboard;

    EXPECT_FALSE(keyboard.KeyIsPressed(KEY_SPACE)) << "[GTEST]: ray::Keyboard IsKeyPressed() function test failed.";
}

TEST(KeyboardTest, KeyIsReleasedWithoutActions)
{
    ray::Keyboard keyboard;

    EXPECT_FALSE(keyboard.KeyIsReleased(KEY_SPACE)) << "[GTEST]: ray::Keyboard IsKeyReleased() function test failed.";
}

TEST(KeyboardTest, KeyIsUpWithoutActions)
{
    ray::Keyboard keyboard;

    EXPECT_TRUE(keyboard.KeyIsUp(KEY_SPACE)) << "[GTEST]: ray::Keyboard IsKeyUp() function test failed.";
}

TEST(KeyboardTest, GetPressedCharWithoutActions)
{
    ray::Keyboard keyboard;

    EXPECT_EQ(keyboard.GetPressedChar(), 0)<< "[GTEST]: ray::Keyboard GetPressedChar() function test failed.";
}

TEST(KeyboardTest, GetPressedKeyWithoutActions)
{
    ray::Keyboard keyboard;

    EXPECT_EQ(keyboard.GetPressedKey(), 0)<< "[GTEST]: ray::Keyboard GetPressedKey() function test failed.";
}
