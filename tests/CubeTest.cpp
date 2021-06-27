/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** CubeTest.cpp
*/

#include <gtest/gtest.h>
#include "../Fox/include/raylib-cpp/Cube.hpp"

TEST(CubeTest, BasicGetLength)
{
    ray::Cube cube;

    EXPECT_EQ(cube.GetLength(), 1) << "[GTEST]: ray::Cube basic constructor && GetLength() test failed.";
}

TEST(CubeTest, BasicGetColor)
{
    ray::Cube cube;

    EXPECT_EQ(cube.GetColor(), ray::Color(230, 41, 55, 255)) << "[GTEST]: ray::Cube basic constructor && GetColor() test failed.";
}

TEST(CubeTest, SetSize)
{
    ray::Cube cube;

    cube.SetSize(Vec2(1, 1));
    EXPECT_EQ(cube.GetSize(), Vec2(1, 1)) << "[GTEST]: ray::Cube SetSize() && GetSize() test failed.";
}

TEST(CubeTest, SetColor)
{
    ray::Cube cube;

    cube.SetColor(ray::Color(255, 255, 255, 255));
    EXPECT_EQ(cube.GetColor(), ray::Color(255, 255, 255, 255)) << "[GTEST]: ray::Cube SetColor() && GetColor() test failed.";
}

TEST(CubeTest, SetLength)
{
    ray::Cube cube;

    cube.SetLength(1.5);
    EXPECT_EQ(cube.GetLength(), 1.5) << "[GTEST]: ray::Cube SetLength() && GetLength() test failed.";
}

TEST(CubeTest, OperatorEqualEqual)
{
    ray::Cube cube;
    ray::Cube anotherCube;

    EXPECT_TRUE(cube == anotherCube) << "[GTEST] : ray::Cube operator== test failed.";
}