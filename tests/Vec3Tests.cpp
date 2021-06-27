/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Vec3Test.cpp
*/

#include <gtest/gtest.h>
#include "../Fox/include/Utils/Vec3.hpp"

TEST(Vec3Tests, ConstructorTest)
{
    Vec3 first = Vec3(1, 1, 1);
    Vec3 second = Vec3(1, 1, 1);
    Vec3 third = Vec3(2, 2, 2);

    EXPECT_EQ(Vec3(), Vec3(0, 0, 0)) << "[GTEST]: Vec3 empty constructor test failed.";
    EXPECT_EQ(Vec3(1, 1, 1), Vec3(1, 1, 1)) << "[GTEST]: Vec3 constructor test failed.";
}

TEST(Vec3Tests, OperatorEqualEqual)
{
    Vec3 first = Vec3(1, 1, 1);
    Vec3 second = Vec3(1, 1, 1);
    Vec3 third = Vec3(2, 2, 2);

    EXPECT_TRUE(first == second) << "[GTEST]: Vec3 operator== test failed.";
    EXPECT_FALSE(first == third) << "[GTEST]: Vec3 operator== test failed.";
}

TEST(Vec3Tests, OperatorDifferent)
{
    Vec3 first = Vec3(1, 1, 1);
    Vec3 second = Vec3(1, 1, 1);
    Vec3 third = Vec3(2, 2, 2);

    EXPECT_FALSE(first != second) << "[GTEST]: Vec3 operator!= test failed.";
    EXPECT_TRUE(first != third) << "[GTEST]: Vec3 operator!= test failed.";
}

TEST(Vec3Tests, OperatorPlusEqual)
{
    Vec3 first = Vec3(1, 1, 1);
    Vec3 second = Vec3(1, 1, 1);

    second += first;
    EXPECT_EQ(second, Vec3(2, 2, 2)) << "[GTEST]: Vec3 operator+= test failed.";
}

TEST(Vec3Tests, OperatorMinusEqual)
{
    Vec3 first = Vec3(1, 1, 1);
    Vec3 second = Vec3(1, 1, 1);

    second -= first;
    EXPECT_EQ(second, Vec3(0, 0, 0)) << "[GTEST]: Vec3 operator-= test failed.";
}

TEST(Vec3Tests, OperatorTimesEqual)
{
    Vec3 first = Vec3(1, 1, 1);

    first *= 2;
    EXPECT_EQ(first, Vec3(2, 2, 2)) << "[GTEST]: Vec3 operator*= test failed.";
}

TEST(Vec3Tests, LengthSquare)
{
    Vec3 first = Vec3(2, 2, 2);

    EXPECT_EQ(first.LengthSquare(), 12) << "[GTEST]: Vec3 LengthSquare() test failed.";
}

TEST(Vec3Tests, Set)
{
    Vec3 first = Vec3(2, 2, 2);

    first.set(3, 3, 3);
    EXPECT_EQ(first, Vec3(3, 3, 3)) << "[GTEST]: Vec3 set() test failed.";
}

TEST(Vec3Tests, OperatorMinus)
{
    EXPECT_EQ(Vec3(1, 1, 1) - Vec3(1, 1, 1), Vec3(0, 0, 0)) << "[GTEST]: Vec3 operator- test failed.";
}

TEST(Vec3Tests, OperatorPlus)
{
    EXPECT_EQ(Vec3(1, 1, 1) + Vec3(1, 1, 1), Vec3(2, 2, 2)) << "[GTEST]: Vec3 operator+ test failed.";
}

TEST(Vec3Tests, OperatorTimes)
{
    EXPECT_EQ(Vec3(1, 1, 1) * 2, Vec3(2, 2, 2)) << "[GTEST]: Vec3 operator* (Vec3 * float) test failed.";
    EXPECT_EQ(Vec3(1, 1, 1) * Vec3(2, 3, 4), Vec3(2, 3, 4)) << "[GTEST]: Vec3 operator* (Vec3 * Vec3) test failed.";
}

TEST(Vec3Tests, Dot)
{
    Vec3 first = Vec3(2, 2, 2);
    Vec3 second = Vec3(2, 2, 2);

    EXPECT_EQ(dot(first, second), 12) << "[GTEST]: Vec3 dot() test failed.";
}

TEST(Vec3Tests, LowValuesTest)
{
    EXPECT_EQ(project(Vec3(0.000001, 0.000001, 0.000001), Vec3(0.000001, 0.000001, 0.000001)), Vec3(0, 0, 0)) << "[GTEST]: Vec3 project() too low value test failed.";
    EXPECT_EQ(reflect(Vec3(0.000001, 0.000001, 0.000001), Vec3(0.000001, 0.000001, 0.000001)), Vec3(0, 0, 0)) << "[GTEST]: Vec3 reflect() too low value test failed.";
    EXPECT_EQ(slerp(Vec3(2, 2, 2), Vec3(2, 2, 2), 0.005), Vec3(2, 2, 2)) << "[GTEST]: Vec3 slerp() with low float value test failed.";
    EXPECT_EQ(Vec3(0.000001, 0.000001, 0.000001).Length(), 0.0f) << "[GTEST]: Vec3 Length() with low Vec3 values test failed.";
    EXPECT_EQ(nlerp(Vec3(0.000001, 0.000001, 0.000001), Vec3(0.000001, 0.000001, 0.000001), 2), Vec3(0.000001, 0.000001, 0.000001)) << "[GTEST]: Vec3 nlerp() with low Vec3 values test failed.";
}

TEST(Vec3Tests, Cross)
{
    EXPECT_EQ(cross(Vec3(2, 2, 2), Vec3(2, 2, 2)), Vec3(0, 0, 0)) << "[GTEST]: Vec3 cross() test failed.";
}

TEST(Vec3Tests, Lerp)
{
    EXPECT_EQ(lerp(Vec3(2, 2, 2), Vec3(2, 2, 2), 2), Vec3(2, 2, 2)) << "[GTEST]: Vec3 lerp() test failed.";
}