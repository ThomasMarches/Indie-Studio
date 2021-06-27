/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** bigsetTest.cpp
*/

#include <gtest/gtest.h>
#include "../Fox/include/Utils/bitsets.hpp"

TEST(bigsetTest, BasicTest)
{
    bitset set;
    bitset anotherSet(10);
    bitset anotherOne(set);
    bitset emptySet;

    EXPECT_EQ(set.size(), 8) << "[GTEST]: bitset basic constructor test failed.";
    EXPECT_EQ(anotherSet.size(), 10) << "[GTEST]: bitset basic constructor test failed.";
    EXPECT_EQ(anotherOne.size(), 8) << "[GTEST]: bitset basic constructor test failed.";

    emptySet = anotherSet;
    EXPECT_EQ(emptySet.size(), anotherSet.size()) << "[GTEST]: bitset operator= && size() test failed.";
}