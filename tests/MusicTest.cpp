/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** MusicTest.cpp
*/

#include <gtest/gtest.h>
#include "../Fox/include/raylib-cpp/Music.hpp"

TEST(MusicTest, GetTimePlayed)
{
    ray::Music music = ray::Music("assets/cry.wav");

    EXPECT_EQ(music.GetTimePlayed(), 0) << "[GTEST]: ray::Music GetTimePlayed() test failed";
}

TEST(MusicTest, Set)
{
    ray::Music music = ray::Music("assets/cry.wav");
    ray::Music aLastOne = ray::Music("assets/non_exisiting_sound.wav");

    aLastOne.set(music);
    EXPECT_EQ(aLastOne.ctxType, music.ctxType) << "[GTEST]: ray::Music set() test failed.";
    EXPECT_EQ(aLastOne.ctxData, music.ctxData) << "[GTEST]: ray::Music set() test failed.";
    EXPECT_EQ(aLastOne.looping, music.looping) << "[GTEST]: ray::Music set() test failed.";
    EXPECT_EQ(aLastOne.sampleCount, music.sampleCount) << "[GTEST]: ray::Music set() test failed.";
    aLastOne.stream.buffer = NULL;
}

TEST(MusicTest, IsPlaying)
{
    ray::Music music = ray::Music("assets/cry.wav");

    EXPECT_FALSE(music.IsPlaying()) << "[GTEST]: ray::Music IsPlaying() test failed";
}