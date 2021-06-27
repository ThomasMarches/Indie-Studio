/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** ColorTest.cpp
*/

#include "../Fox/include/raylib-cpp/Color.hpp"
#include <gtest/gtest.h>

TEST(ColorTest, EmptyConstructor)
{
    ray::Color anotherColor(100, 100, 100);
    ray::Color emptyColor;

    EXPECT_EQ(emptyColor, ray::Color(0, 0, 0, 255)) << "[GTEST]: ray::Color empty constructor test failed";
    EXPECT_EQ(anotherColor, ray::Color(100, 100, 100, 255)) << "[GTEST]: ray::Color empty constructor test failed";
}

TEST(ColorTest, UnsignedCharConstructor)
{
    ray::Color color(100, 100, 100, 100);

    EXPECT_EQ(color, ray::Color(100, 100, 100, 100)) << "[GTEST]: ray::Color unsigned char constructor test failed";
}

TEST(ColorTest, Set)
{
    ray::Color color(100, 100, 100, 100);

    color.set(ray::Color(200, 200, 200, 200));
    EXPECT_EQ(color, ray::Color(200, 200, 200, 200)) << "[GTEST]: ray::Color set() test failed";
}

TEST(ColorTest, OperatorEqual)
{
    ray::Color color(100, 100, 100, 100);
    ray::Color aLastColor;

    aLastColor = color;
    EXPECT_EQ(aLastColor, ray::Color(100, 100, 100, 100)) << "[GTEST]: ray::Color operator= test failed()";
}