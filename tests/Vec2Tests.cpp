/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Vec3Test.cpp
*/

#include <gtest/gtest.h>
#include "../Fox/include/Utils/Vec2.hpp"

TEST(Vec2Tests, Constructor)
{
    EXPECT_EQ(Vec2(), Vec2(0, 0)) << "[GTEST]: Vec2 empty constructor test failed.";
    EXPECT_EQ(Vec2(1, 1), Vec2(1, 1)) << "[GTEST]: Vec2 constructor test failed.";
}

TEST(Vec2Tests, SetAudioStreamVolume)
{
    Vec2 first = Vec2(1, 1);

    first.set(2, 2);
    EXPECT_EQ(first, Vec2(2, 2)) << "[GTEST]: Vec2 set() test failed";
}

TEST(Vec2Tests, OperatorMinus)
{
    Vec2 first = Vec2(1, 1);
    Vec2 second = Vec2(1, 1);

    EXPECT_EQ(first - second, Vec2(0, 0)) << "[GTEST]: Vec2 operator- test failed";
}

TEST(Vec2Tests, OperatorPlusEqual)
{
    Vec2 first = Vec2(1, 1);

    first += Vec2(1, 1);
    EXPECT_EQ(first, Vec2(2, 2)) << "[GTEST]: Vec2 operator+= test failed";
}

TEST(Vec2Tests, OperatorMinusEqual)
{
    Vec2 first = Vec2(1, 1);

    first -= Vec2(1, 1);
    EXPECT_EQ(first, Vec2(0, 0)) << "[GTEST]: Vec2 operator-= test failed";
}

TEST(Vec2Tests, OperatorTimesEqual)
{
    Vec2 first = Vec2(1, 1);

    first *= 2;
    EXPECT_EQ(first, Vec2(2, 2)) << "[GTEST]: Vec2 operator*= test failed";
}

TEST(Vec2Tests, Length)
{
    EXPECT_EQ(Vec2(3, 4).Length(), 5) << "[GTEST]: Vec2 Length() test failed";
}

TEST(Vec2Tests, OperatorVec3)
{
    Vec2 first = Vec2(1, 1);

    EXPECT_EQ(Vec3(first), Vec3(1, 1, 0)) << "[GTEST]: Vec2 operator Vec3() test failed";
}