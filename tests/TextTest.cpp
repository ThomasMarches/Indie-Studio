/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** TextTest.cpp
*/

#include "../Fox/include/raylib-cpp/Text.hpp"
#include <gtest/gtest.h>

TEST(TextTest, ConstructorGetString)
{
    ray::Text text = ray::Text("basic test string");

    EXPECT_EQ(text.GetString(), "basic test string") << "[GTEST]: ray::Text GetString() test failed";
}

TEST(TextTest, SetString)
{
    ray::Text text = ray::Text("basic test string");

    text.SetString("Another basic test string");
    EXPECT_EQ(text.GetString(), "Another basic test string") << "[GTEST]: ray::Text SetString() test failed";
}

TEST(TextTest, ConstructorGetColor)
{
    ray::Text colorText = ray::Text("A basic colored text", ray::Color(0, 0, 0, 255));

    EXPECT_EQ(colorText.GetColor(), ray::Color(0, 0, 0, 255)) << "[GTEST]: ray::Text GetColor() test failed";
}

TEST(TextTest, SetColor)
{
    ray::Text colorText = ray::Text("A basic colored text", ray::Color(0, 0, 0, 255));

    colorText.SetColor(ray::Color(0, 121, 241, 255));
    EXPECT_EQ(colorText.GetColor(), ray::Color(0, 121, 241, 255)) << "[GTEST]: ray::Text SetColor().GetColor() test failed";
}

TEST(TextTest, ConstructorGetFontSize)
{
    ray::Text text = ray::Text("basic test string");

    EXPECT_EQ(text.GetFontSize(), 20) << "[GTEST]: ray::Text GetFontSize() failed";
}

TEST(TextTest, SetFontSize)
{
    ray::Text text = ray::Text("basic test string");

    text.SetFontSize(40);
    EXPECT_EQ(text.GetFontSize(), 40) << "[GTEST]: ray::Text SetFontSize().GetFontSize() test failed";
}