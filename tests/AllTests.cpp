/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** AllTests.cpp
*/

#include <gtest/gtest.h>

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    for (int i = 1; i < argc; ++i) {
        std::cout << "Input[" << i << "]: "<< argv[i] << std::endl;
    }

    return RUN_ALL_TESTS();
}