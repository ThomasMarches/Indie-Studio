/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** AudioTest.cpp
*/

#include <gtest/gtest.h>
#include "../Fox/include/Core/Audio/AudioGroup.hpp"
#include "../Fox/include/Core/Audio/AudioManager.hpp"

TEST(AudioTests, GetAudioNameTest)
{
    fox::AudioGroup group("Musics");

    EXPECT_EQ(group.getAudioName(), "Musics") << "[GTEST]: AudioGroup getAudioName() test failed.";
    group.setAudioName("Effects");
    EXPECT_EQ(group.getAudioName(), "Effects") << "[GTEST]: AudioGroup setAudioName() test failed.";
}

TEST(AudioTests, GetVolumeTest)
{
    fox::AudioGroup group("Musics");

    EXPECT_EQ(group.getVolume(), 1) << "[GTEST]: AudioGroup getVolume() test failed.";
    group.setVolume(10);
    EXPECT_EQ(group.getVolume(), 10) << "[GTEST]: AudioGroup setVolume() test failed.";
}

TEST(AudioTests, CreateGroupTest)
{
    fox::AudioManager manager;

    manager.CreateGroup("Musics");
    EXPECT_NO_THROW(manager.getGroup("Musics")) << "[GTEST]: AudioManager normal getGroup() test failed.";
}

TEST(AudioTests, GetGroupErrorTest)
{
    fox::AudioManager manager;

    EXPECT_THROW(manager.getGroup("Effects"), std::runtime_error) << "[GTEST]: AudioManager exceptions on getGroup() test failed.";
}