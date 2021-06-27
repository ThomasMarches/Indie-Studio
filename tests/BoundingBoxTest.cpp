/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** BoundingBoxTest.cpp
*/

#include <gtest/gtest.h>
#include "../Fox/include/raylib-cpp/BoundingBox.hpp"
#include "../Fox/include/Utils/Vec3.hpp"
#include "../Fox/include/raylib-cpp/Ray.hpp"

TEST(BoundingBoxTest, CheckCollisionTrue)
{
    ray::BoundingBox vec3Box(Vec3(0, 0, 0));

    EXPECT_EQ(vec3Box.CheckCollision(Vec3(0, 0, 0), 1), true) << "[GTEST]: ray::BoundingBox CheckCollision() true test failed.";
    EXPECT_EQ(vec3Box.CheckCollision(ray::BoundingBox(Vec3(0, 0, 0))), true) << "[GTEST]: ray::BoundingBox CheckCollision() true test failed.";
    EXPECT_EQ(vec3Box.CheckCollision(ray::Ray(Vec3(0, 0, 0), Vec3(0, 0, 0))), true) << "[GTEST]: ray::BoundingBox CheckCollision() true test failed.";
}

TEST(BoundingBoxTest, CheckCollisionFalse)
{
    ray::BoundingBox vec3Box(Vec3(0, 0, 0));

    EXPECT_EQ(vec3Box.CheckCollision(Vec3(10, 10, 10), 1), false) << "[GTEST]: ray::BoundingBox CheckCollision() false test failed.";
    EXPECT_EQ(vec3Box.CheckCollision(ray::BoundingBox(Vec3(10, 10, 10))), false) << "[GTEST]: ray::BoundingBox CheckCollision() false test failed.";
    EXPECT_EQ(vec3Box.CheckCollision(ray::Ray(Vec3(10, 0, -50), Vec3(10, 10, 10))), false) << "[GTEST]: ray::BoundingBox CheckCollision() false test failed.";
}

TEST(BoundingBoxTest, Set)
{
    ray::BoundingBox vec3Box(Vec3(0, 0, 0));

    vec3Box.set(ray::BoundingBox(Vec3(1, 1, 1)));
    EXPECT_EQ(vec3Box, ray::BoundingBox(Vec3(1, 1, 1))) << "[GTEST]: ray::BoundingBox set() test failed.";
}

TEST(BoundingBoxTest, OperatorEqualEqual)
{
    ray::BoundingBox vec3Box(Vec3(0, 0, 0));

    EXPECT_TRUE(vec3Box == ray::BoundingBox(Vec3(0, 0, 0))) << "[GTEST]: ray::BoundingBox operator== test failed.";
    EXPECT_FALSE(vec3Box == ray::BoundingBox(Vec3(2, 2, 2))) << "[GTEST]: ray::BoundingBox operator== test failed.";
}