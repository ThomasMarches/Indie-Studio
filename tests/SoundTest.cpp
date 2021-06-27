/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** SoundTest.cpp
*/

#include "../Fox/include/raylib-cpp/Sound.hpp"
#include <gtest/gtest.h>

TEST(SoundTest, Set)
{
    ray::Sound sound = ray::Sound("assets/cry.wav");
    ray::Sound anotherOne = ray::Sound("assets/non_exisiting_sound.wav");

    anotherOne.set(sound);
    EXPECT_EQ(anotherOne.sampleCount, sound.sampleCount) << "[GTEST]: ray::Sound set() test failed.";
}

TEST(SoundTest, IsPlaying)
{
    ray::Sound sound = ray::Sound("assets/cry.wav");

    EXPECT_FALSE(sound.IsPlaying()) << "[GTEST]: ray::Sound IsPlaying() test failed.";
}