/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** RectangleTest.cpp
*/

#include <gtest/gtest.h>
#include "../Fox/include/raylib-cpp/Rectangle.hpp"

TEST(RectangleTest, getColor)
{
    ray::Rectangle rec = ray::Rectangle(10, 10, 10, 10, ray::Color(0, 0, 0, 255));

    EXPECT_EQ(rec.getColor(), ray::Color(0, 0, 0, 255)) << "[GTEST]: ray::Rectangle getColor() failed.";
}

TEST(RectangleTest, setColor)
{
    ray::Rectangle rec = ray::Rectangle(10, 10, 10, 10, ray::Color(0, 0, 0, 255));

    rec.setColor(ray::Color(255, 255, 255, 255));
    EXPECT_EQ(rec.getColor(), ray::Color(255, 255, 255, 255)) << "[GTEST]: ray::Rectangle getColor() failed.";
}

TEST(RectangleTest, OperatorEqual)
{
    ray::Rectangle rec = ray::Rectangle(10, 10, 10, 10, ray::Color(0, 0, 0, 255));
    ray::Rectangle emptyRec;

    emptyRec = rec;
    EXPECT_EQ(emptyRec.x, rec.x) << "[GTEST]: ray::Rectangle operator= failed.";
    EXPECT_EQ(emptyRec.y, rec.y) << "[GTEST]: ray::Rectangle operator= failed.";
    EXPECT_EQ(emptyRec.width, rec.width) << "[GTEST]: ray::Rectangle operator= failed.";
    EXPECT_EQ(emptyRec.height, rec.height) << "[GTEST]: ray::Rectangle operator= failed.";
}

TEST(RectangleTest, CheckCollision)
{
    ray::Rectangle rec = ray::Rectangle(10, 10, 10, 10);
    ray::Rectangle anotherRec = ray::Rectangle(10, 10, 10, 10, ray::Color(0, 0, 0, 255));

    EXPECT_TRUE(rec.CheckCollision(anotherRec)) << "[GTEST]: ray::Rectangle CheckCollision(ray::Rectangle) test failed.";
    EXPECT_TRUE(rec.CheckCollision(Vec2(10, 10))) << "[GTEST]: ray::Rectangle CheckCollision(Vec2) test failed.";
    EXPECT_TRUE(rec.CheckCollision(Vec2(10, 10), 2)) << "[GTEST]: ray::Rectangle CheckCollision(Vec2, float) test failed.";
}

TEST(RectangleTest, GetSize)
{
    ray::Rectangle rec = ray::Rectangle(10, 10, 10, 10);

    EXPECT_EQ(rec.GetSize(), Vec2(10, 10)) << "[GTEST]: ray::Rectangle GetSize() test failed.";
}

TEST(RectangleTest, GetPosition)
{
    ray::Rectangle rec = ray::Rectangle(10, 10, 10, 10);

    EXPECT_EQ(rec.GetPosition(), Vec2(10, 10)) << "[GTEST]: ray::Rectangle GetSize() test failed.";
}

TEST(RectangleTest, SetPosition)
{
    ray::Rectangle rec = ray::Rectangle(10, 10, 10, 10);

    rec.SetPosition(20, 20);
    EXPECT_EQ(rec.GetPosition(), Vec2(20, 20)) << "[GTEST]: ray::Rectangle GetSize() test failed.";
}

TEST(RectangleTest, SetSize)
{
    ray::Rectangle rec = ray::Rectangle(10, 10, 10, 10);

    rec.SetSize(20, 20);
    EXPECT_EQ(rec.GetSize(), Vec2(20, 20)) << "[GTEST]: ray::Rectangle GetSize() && SetSize() test failed.";
}