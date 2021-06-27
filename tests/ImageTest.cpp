/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** ImageTest.cpp
*/

#include <gtest/gtest.h>
#include "../Fox/include/raylib-cpp/Image.hpp"

TEST(ImageTest, Set)
{
    ray::Image img = ray::Image("assets/button/carré.png");
    ray::Image anotherImg = ray::Image("assets/button/rond.png");

    anotherImg.set(img);
    EXPECT_EQ(anotherImg.data, img.data) << "[GTEST]: ray::Image set() test failed";

    EXPECT_EQ(anotherImg.width, img.width) << "[GTEST]: ray::Image set() test failed";

    EXPECT_EQ(anotherImg.height, img.height) << "[GTEST]: ray::Image set() test failed";

    EXPECT_EQ(anotherImg.mipmaps, img.mipmaps) << "[GTEST]: ray::Image set() test failed";

    EXPECT_EQ(anotherImg.format, img.format) << "[GTEST]: ray::Image set() test failed";
}

TEST(ImageTest, Load)
{
    ray::Image img = ray::Image("assets/button/carré.png");
    ray::Image anotherImg = ray::Image("assets/button/rond.png");

    img.Load("assets/button/rond.png");
    EXPECT_EQ(anotherImg.width, img.width) << "[GTEST]: ray::Image Load() test failed";

    EXPECT_EQ(anotherImg.height, img.height) << "[GTEST]: ray::Image Load() test failed";

    EXPECT_EQ(anotherImg.mipmaps, img.mipmaps) << "[GTEST]: ray::Image Load() test failed";

    EXPECT_EQ(anotherImg.format, img.format) << "[GTEST]: ray::Image Load() test failed";
}
