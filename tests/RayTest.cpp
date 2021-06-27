/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Raylib-cpp.cpp
*/

#include <gtest/gtest.h>
#include "../Fox/include/Utils/Vec3.hpp"
#include "../Fox/include/raylib-cpp/BoundingBox.hpp"
#include "../Fox/include/raylib-cpp/Ray.hpp"

TEST(RayTest, Set)
{
    ray::Ray ray = ray::Ray(Vec3(10, 10, 0), Vec3(10, 10, 0));
    ray::Ray anotherRay = ray::Ray(ray);
    ray::Ray aLastOne = ray::Ray(Vec3(0, 0, 0), Vec3(0, 0, 0));

    aLastOne.set(anotherRay);
    EXPECT_EQ(anotherRay.position.x, aLastOne.position.x) << "[GTEST]: ray::Ray set() && operator= test failed.";
    EXPECT_EQ(anotherRay.position.y, aLastOne.position.y) << "[GTEST]: ray::Ray set() && operator= test failed.";
    EXPECT_EQ(anotherRay.position.z, aLastOne.position.z) << "[GTEST]: ray::Ray set() && operator= test failed.";

    EXPECT_EQ(anotherRay.direction.x, aLastOne.direction.x) << "[GTEST]: ray::Ray set() && operator= test failed.";
    EXPECT_EQ(anotherRay.direction.y, aLastOne.direction.y) << "[GTEST]: ray::Ray set() && operator= test failed.";
    EXPECT_EQ(anotherRay.direction.z, aLastOne.direction.z) << "[GTEST]: ray::Ray set() && operator= test failed.";
}

TEST(RayTest, OperatorEqual)
{
    ray::Ray ray = ray::Ray(Vec3(10, 10, 0), Vec3(10, 10, 0));
    ray::Ray aLastOne = ray::Ray(Vec3(0, 0, 0), Vec3(0, 0, 0));

    aLastOne = ray;
    EXPECT_EQ(ray.position.x, aLastOne.position.x) << "[GTEST]: ray::Ray operator= test failed.";
    EXPECT_EQ(ray.position.y, aLastOne.position.y) << "[GTEST]: ray::Ray operator= test failed.";
    EXPECT_EQ(ray.position.z, aLastOne.position.z) << "[GTEST]: ray::Ray operator= test failed.";

    EXPECT_EQ(ray.direction.x, aLastOne.direction.x) << "[GTEST]: ray::Ray operator= test failed.";
    EXPECT_EQ(ray.direction.y, aLastOne.direction.y) << "[GTEST]: ray::Ray operator= test failed.";
    EXPECT_EQ(ray.direction.z, aLastOne.direction.z) << "[GTEST]: ray::Ray operator= test failed.";
}

TEST(RayTest, CheckCollisionSphere)
{
    Vec3 vec3;
    ray::Ray ray = ray::Ray(Vec3(10, 10, 0), Vec3(10, 10, 0));

    EXPECT_TRUE(ray.CheckCollisionSphere(Vec3(10, 10, 0), 2)) << "[GTEST]: ray::Ray CheckCollisionSphere(Vec3, float) test failed.";
    EXPECT_TRUE(ray.CheckCollisionSphere(Vec3(10, 10, 0), 2, &vec3)) << "[GTEST]: ray::Ray CheckCollisionSphere(Vec3, float *Vec3) test failed.";
}

TEST(RayTest, CheckCollision)
{
    ray::Ray ray = ray::Ray(Vec3(10, 10, 0), Vec3(10, 10, 0));
    ray::BoundingBox vec3Box = ray::BoundingBox(Vec3(10, 10, 0));

    EXPECT_TRUE(ray.CheckCollision(vec3Box)) << "[GTEST]: ray::Ray CheckCollision() test failed.";
}
