/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Keyboard.cpp
*/

#include "raylib-cpp/Keyboard.hpp"

namespace ray
{
    // Detect if a key has been pressed once
    bool Keyboard::KeyIsPressed(int key)
    {
        return IsKeyPressed(key);
    }

    // Detect if a key is being pressed
    bool Keyboard::KeyIsDown(int key)
    {
        return IsKeyDown(key);
    }

    // Detect if a key has been released once
    bool Keyboard::KeyIsReleased(int key)
    {
        return IsKeyReleased(key);
    }

    // Detect is a key is not being pressed
    bool Keyboard::KeyIsUp(int key)
    {
        return IsKeyUp(key);
    }

    // Set a custom key to exit program (default is ESC)
    void Keyboard::ExitKeySet(int key)
    {
        SetExitKey(key);
    }

    // Get key pressed (keycode), call it multiple times for keys queued
    int Keyboard::GetPressedKey(void)
    {
        return GetKeyPressed();
    }
    // Get char pressed (unicode), call it multiple times for chars queued
    int Keyboard::GetPressedChar(void)
    {
        return GetCharPressed();
    }
} // namespace ray