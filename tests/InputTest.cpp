/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** InputTest.cpp
*/

#include <gtest/gtest.h>
#include "../Fox/include/Core/Input/Input.hpp"

TEST(InputTest, GetKey)
{
    EXPECT_EQ(fox::Input::get_key(KEY_SPACE), 0);
}

TEST(InputTest, GetKeyDown)
{
    EXPECT_EQ(fox::Input::get_key_down(KEY_SPACE), 0);
}

TEST(InputTest, GetMouseBtn)
{
    EXPECT_EQ(fox::Input::get_mouse_btn(MOUSE_LEFT_BUTTON), 0);
}

TEST(InputTest, GetMouseBtnDown)
{
    EXPECT_EQ(fox::Input::get_mouse_btn_down(MOUSE_LEFT_BUTTON), 0);
}

TEST(InputTest, GetMouseBtnUp)
{
    EXPECT_EQ(fox::Input::get_mouse_btn_up(MOUSE_LEFT_BUTTON), 0);
}

TEST(InputTest, GetMousePos)
{
    EXPECT_EQ(fox::Input::mouse_pos(), Vec2(0, 0));
}

TEST(InputTest, MouseWheel)
{
    EXPECT_EQ(fox::Input::mouse_wheel(), 0);
}

TEST(InputTest, GetPressedKey)
{
    EXPECT_EQ(fox::Input::get_pressed_key(), 0);
}

TEST(InputTest, GetPressedButton)
{
    EXPECT_EQ(fox::Input::get_pressed_button(), 0);
}

TEST(InputTest, ButtonToImage)
{
    EXPECT_EQ(fox::Input::button_to_image(0), "") << "[GTEST]: fox::Input button_to_image() test failed.";
    EXPECT_EQ(fox::Input::button_to_image(1), "assets/button/D-Pad-Up.png") << "[GTEST]: fox::Input button_to_image() test failed.";
    EXPECT_EQ(fox::Input::button_to_image(2), "assets/button/D-Pad-Right.png") << "[GTEST]: fox::Input button_to_image() test failed.";
    EXPECT_EQ(fox::Input::button_to_image(3), "assets/button/D-Pad-Down.png") << "[GTEST]: fox::Input button_to_image() test failed.";
    EXPECT_EQ(fox::Input::button_to_image(4), "assets/button/D-Pad-Left.png") << "[GTEST]: fox::Input button_to_image() test failed.";
    EXPECT_EQ(fox::Input::button_to_image(5), "assets/button/triangle.png") << "[GTEST]: fox::Input button_to_image() test failed.";
    EXPECT_EQ(fox::Input::button_to_image(6), "assets/button/rond.png") << "[GTEST]: fox::Input button_to_image() test failed.";
    EXPECT_EQ(fox::Input::button_to_image(7), "assets/button/croix.png") << "[GTEST]: fox::Input button_to_image() test failed.";
    EXPECT_EQ(fox::Input::button_to_image(8), "assets/button/carré.png") << "[GTEST]: fox::Input button_to_image() test failed.";
}

TEST(InputTest, StringToKey)
{
    EXPECT_EQ(fox::Input::string_to_key("A"), KEY_A) << "[GTEST]: fox::Input string_to_key() test failed.";
    EXPECT_EQ(fox::Input::string_to_key("B"), KEY_B) << "[GTEST]: fox::Input string_to_key() test failed.";
    EXPECT_EQ(fox::Input::string_to_key("C"), KEY_C) << "[GTEST]: fox::Input string_to_key() test failed.";
    EXPECT_EQ(fox::Input::string_to_key("D"), KEY_D) << "[GTEST]: fox::Input string_to_key() test failed.";
    EXPECT_EQ(fox::Input::string_to_key("E"), KEY_E) << "[GTEST]: fox::Input string_to_key() test failed.";
    EXPECT_EQ(fox::Input::string_to_key("F"), KEY_F) << "[GTEST]: fox::Input string_to_key() test failed.";
    EXPECT_EQ(fox::Input::string_to_key("G"), KEY_G) << "[GTEST]: fox::Input string_to_key() test failed.";
    EXPECT_EQ(fox::Input::string_to_key("H"), KEY_H) << "[GTEST]: fox::Input string_to_key() test failed.";
    EXPECT_EQ(fox::Input::string_to_key("I"), KEY_I) << "[GTEST]: fox::Input string_to_key() test failed.";
    EXPECT_EQ(fox::Input::string_to_key("J"), KEY_J) << "[GTEST]: fox::Input string_to_key() test failed.";
    EXPECT_EQ(fox::Input::string_to_key("K"), KEY_K) << "[GTEST]: fox::Input string_to_key() test failed.";
    EXPECT_EQ(fox::Input::string_to_key("L"), KEY_L) << "[GTEST]: fox::Input string_to_key() test failed.";
    EXPECT_EQ(fox::Input::string_to_key("M"), KEY_M) << "[GTEST]: fox::Input string_to_key() test failed.";
    EXPECT_EQ(fox::Input::string_to_key("N"), KEY_N) << "[GTEST]: fox::Input string_to_key() test failed.";
    EXPECT_EQ(fox::Input::string_to_key("O"), KEY_O) << "[GTEST]: fox::Input string_to_key() test failed.";
    EXPECT_EQ(fox::Input::string_to_key("P"), KEY_P) << "[GTEST]: fox::Input string_to_key() test failed.";
    EXPECT_EQ(fox::Input::string_to_key("Q"), KEY_Q) << "[GTEST]: fox::Input string_to_key() test failed.";
    EXPECT_EQ(fox::Input::string_to_key("R"), KEY_R) << "[GTEST]: fox::Input string_to_key() test failed.";
    EXPECT_EQ(fox::Input::string_to_key("S"), KEY_S) << "[GTEST]: fox::Input string_to_key() test failed.";
    EXPECT_EQ(fox::Input::string_to_key("T"), KEY_T) << "[GTEST]: fox::Input string_to_key() test failed.";
    EXPECT_EQ(fox::Input::string_to_key("U"), KEY_U) << "[GTEST]: fox::Input string_to_key() test failed.";
    EXPECT_EQ(fox::Input::string_to_key("V"), KEY_V) << "[GTEST]: fox::Input string_to_key() test failed.";
    EXPECT_EQ(fox::Input::string_to_key("W"), KEY_W) << "[GTEST]: fox::Input string_to_key() test failed.";
    EXPECT_EQ(fox::Input::string_to_key("X"), KEY_X) << "[GTEST]: fox::Input string_to_key() test failed.";
    EXPECT_EQ(fox::Input::string_to_key("Y"), KEY_Y) << "[GTEST]: fox::Input string_to_key() test failed.";
    EXPECT_EQ(fox::Input::string_to_key("Z"), KEY_Z) << "[GTEST]: fox::Input string_to_key() test failed.";
    EXPECT_EQ(fox::Input::string_to_key("Up"), KEY_UP) << "[GTEST]: fox::Input string_to_key() test failed.";
    EXPECT_EQ(fox::Input::string_to_key("Down"), KEY_DOWN) << "[GTEST]: fox::Input string_to_key() test failed.";
    EXPECT_EQ(fox::Input::string_to_key("Left"), KEY_LEFT) << "[GTEST]: fox::Input string_to_key() test failed.";
    EXPECT_EQ(fox::Input::string_to_key("Right"), KEY_RIGHT) << "[GTEST]: fox::Input string_to_key() test failed.";
    EXPECT_EQ(fox::Input::string_to_key("Space"), KEY_SPACE) << "[GTEST]: fox::Input string_to_key() test failed.";
    EXPECT_EQ(fox::Input::string_to_key("Escape"), KEY_ESCAPE) << "[GTEST]: fox::Input string_to_key() test failed.";
    EXPECT_EQ(fox::Input::string_to_key("Enter"), KEY_ENTER) << "[GTEST]: fox::Input string_to_key() test failed.";
    EXPECT_EQ(fox::Input::string_to_key("Tab"), KEY_TAB) << "[GTEST]: fox::Input string_to_key() test failed.";
    EXPECT_EQ(fox::Input::string_to_key("Backspace"), KEY_BACKSPACE) << "[GTEST]: fox::Input string_to_key() test failed.";
}

TEST(InputTest, KeyToString)
{
    EXPECT_EQ(fox::Input::key_to_string(KEY_A), "A") << "[GTEST]: fox::Input key_to_string() test failed.";
    EXPECT_EQ(fox::Input::key_to_string(KEY_B), "B") << "[GTEST]: fox::Input key_to_string() test failed.";
    EXPECT_EQ(fox::Input::key_to_string(KEY_C), "C") << "[GTEST]: fox::Input key_to_string() test failed.";
    EXPECT_EQ(fox::Input::key_to_string(KEY_D), "D") << "[GTEST]: fox::Input key_to_string() test failed.";
    EXPECT_EQ(fox::Input::key_to_string(KEY_E), "E") << "[GTEST]: fox::Input key_to_string() test failed.";
    EXPECT_EQ(fox::Input::key_to_string(KEY_F), "F") << "[GTEST]: fox::Input key_to_string() test failed.";
    EXPECT_EQ(fox::Input::key_to_string(KEY_G), "G") << "[GTEST]: fox::Input key_to_string() test failed.";
    EXPECT_EQ(fox::Input::key_to_string(KEY_H), "H") << "[GTEST]: fox::Input key_to_string() test failed.";
    EXPECT_EQ(fox::Input::key_to_string(KEY_I), "I") << "[GTEST]: fox::Input key_to_string() test failed.";
    EXPECT_EQ(fox::Input::key_to_string(KEY_J), "J") << "[GTEST]: fox::Input key_to_string() test failed.";
    EXPECT_EQ(fox::Input::key_to_string(KEY_K), "K") << "[GTEST]: fox::Input key_to_string() test failed.";
    EXPECT_EQ(fox::Input::key_to_string(KEY_L), "L") << "[GTEST]: fox::Input key_to_string() test failed.";
    EXPECT_EQ(fox::Input::key_to_string(KEY_M), "M") << "[GTEST]: fox::Input key_to_string() test failed.";
    EXPECT_EQ(fox::Input::key_to_string(KEY_N), "N") << "[GTEST]: fox::Input key_to_string() test failed.";
    EXPECT_EQ(fox::Input::key_to_string(KEY_O), "O") << "[GTEST]: fox::Input key_to_string() test failed.";
    EXPECT_EQ(fox::Input::key_to_string(KEY_P), "P") << "[GTEST]: fox::Input key_to_string() test failed.";
    EXPECT_EQ(fox::Input::key_to_string(KEY_Q), "Q") << "[GTEST]: fox::Input key_to_string() test failed.";
    EXPECT_EQ(fox::Input::key_to_string(KEY_R), "R") << "[GTEST]: fox::Input key_to_string() test failed.";
    EXPECT_EQ(fox::Input::key_to_string(KEY_S), "S") << "[GTEST]: fox::Input key_to_string() test failed.";
    EXPECT_EQ(fox::Input::key_to_string(KEY_T), "T") << "[GTEST]: fox::Input key_to_string() test failed.";
    EXPECT_EQ(fox::Input::key_to_string(KEY_U), "U") << "[GTEST]: fox::Input key_to_string() test failed.";
    EXPECT_EQ(fox::Input::key_to_string(KEY_V), "V") << "[GTEST]: fox::Input key_to_string() test failed.";
    EXPECT_EQ(fox::Input::key_to_string(KEY_W), "W") << "[GTEST]: fox::Input key_to_string() test failed.";
    EXPECT_EQ(fox::Input::key_to_string(KEY_X), "X") << "[GTEST]: fox::Input key_to_string() test failed.";
    EXPECT_EQ(fox::Input::key_to_string(KEY_Y), "Y") << "[GTEST]: fox::Input key_to_string() test failed.";
    EXPECT_EQ(fox::Input::key_to_string(KEY_Z), "Z") << "[GTEST]: fox::Input key_to_string() test failed.";
    EXPECT_EQ(fox::Input::key_to_string(KEY_UP), "Up") << "[GTEST]: fox::Input key_to_string() test failed.";
    EXPECT_EQ(fox::Input::key_to_string(KEY_DOWN), "Down") << "[GTEST]: fox::Input key_to_string() test failed.";
    EXPECT_EQ(fox::Input::key_to_string(KEY_LEFT), "Left") << "[GTEST]: fox::Input key_to_string() test failed.";
    EXPECT_EQ(fox::Input::key_to_string(KEY_RIGHT), "Right") << "[GTEST]: fox::Input key_to_string() test failed.";
    EXPECT_EQ(fox::Input::key_to_string(KEY_ESCAPE), "Escape") << "[GTEST]: fox::Input key_to_string() test failed.";
    EXPECT_EQ(fox::Input::key_to_string(KEY_ENTER), "Enter") << "[GTEST]: fox::Input key_to_string() test failed.";
    EXPECT_EQ(fox::Input::key_to_string(KEY_TAB), "Tab") << "[GTEST]: fox::Input key_to_string() test failed.";
    EXPECT_EQ(fox::Input::key_to_string(KEY_SPACE), "Space") << "[GTEST]: fox::Input key_to_string() test failed.";
    EXPECT_EQ(fox::Input::key_to_string(KEY_BACKSPACE), "Backspace") << "[GTEST]: fox::Input key_to_string() test failed.";
}