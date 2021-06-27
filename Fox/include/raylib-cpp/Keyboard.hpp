/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Keyboard.hpp
*/

#ifndef RAYLIB_KEYBOARD_HPP_
#define RAYLIB_KEYBOARD_HPP_

#include <string>
#include "raylib.hpp"

namespace ray {
    class Keyboard {
    public:
        bool KeyIsPressed(int key);
        bool KeyIsDown(int key);
        bool KeyIsReleased(int key);
        bool KeyIsUp(int key);
        void ExitKeySet(int key);
        int GetPressedKey(void);
        int GetPressedChar(void);
    };
}  // namespace ray

#endif  // RAYLIB_KEYBOARD_HPP_