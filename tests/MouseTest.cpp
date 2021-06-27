/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** MouseTest.cpp
*/

#include <gtest/gtest.h>
#include "../Fox/include/raylib-cpp/Mouse.hpp"

TEST(MouseTest, IsButtonDownWithoutActions)
{
    ray::Mouse mouse;

    EXPECT_FALSE(mouse.IsButtonDown(0)) << "[GTEST]: ray::Mouse IsButtonDown() function test failed.";
}

TEST(MouseTest, IsButtonPressedWithoutActions)
{
    ray::Mouse mouse;

    EXPECT_FALSE(mouse.IsButtonPressed(0)) << "[GTEST]: ray::Mouse IsButtonPressed() function test failed.";
}

TEST(MouseTest, IsButtonReleasedWithoutActions)
{
    ray::Mouse mouse;

    EXPECT_FALSE(mouse.IsButtonReleased(0)) << "[GTEST]: ray::Mouse IsButtonReleased() function test failed.";
}

TEST(MouseTest, IsButtonUpWithoutActions)
{
    ray::Mouse mouse;

    EXPECT_TRUE(mouse.IsButtonUp(0)) << "[GTEST]: ray::Mouse IsButtonUp() function test failed.";
}

TEST(MouseTest, GetX)
{
    ray::Mouse mouse;

    EXPECT_EQ(mouse.GetX(), 0) << "[GTEST]: ray::Mouse GetX() without window test failed.";
}

TEST(MouseTest, GetY)
{
    ray::Mouse mouse;

    EXPECT_EQ(mouse.GetY(), 0) << "[GTEST]: ray::Mouse GetY() without window test failed.";
}

TEST(MouseTest, GetPosition)
{
    ray::Mouse mouse;

    EXPECT_EQ(mouse.GetPosition(), Vec2(0, 0)) << "[GTEST]: ray::Mouse GetPosition() without window test failed.";
}

TEST(MouseTest, GetWheelMove)
{
    ray::Mouse mouse;

    EXPECT_EQ(mouse.GetWheelMove(), 0) << "[GTEST]: ray::Mouse GetMouseWheel() without window test failed.";
}