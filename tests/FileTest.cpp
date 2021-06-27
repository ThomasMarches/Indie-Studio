/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** FileTest.cpp
*/

#include <gtest/gtest.h>
#include "../Fox/include/FileSystem.hpp"

TEST(FileTest, WriteFile)
{
    EXPECT_TRUE(fox::file::WriteFile("tests/test.txt", "A simple content")) << "[GTEST]: fox::file WriteFile() on proper file test failed.";
}

TEST(FileTest, ReadFile)
{
    std::string save;

    EXPECT_TRUE(fox::file::ReadFile("tests/test.txt", save)) << "[GTEST]: fox::file ReadFile() test failed.";
    EXPECT_TRUE(save == "A simple content") << "[GTEST]: fox::file ReadFile() content check test failed.";
    EXPECT_FALSE(fox::file::ReadFile("AFileThatDoesntExist.cpp", save)) << "[GTEST]: fox::file ReadFile() on file that doesn't exist test failed.";
}