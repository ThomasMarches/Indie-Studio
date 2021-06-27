/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** PlayerInput.h
*/

#ifndef ECS_PLAYERINPUT_H
#define ECS_PLAYERINPUT_H


#include <string>
#include "raylib.hpp"
#include "raylib-cpp/Gamepad.hpp"

namespace fox
{
    class Application;
}

class PlayerInput
{
    public:
        PlayerInput();
        PlayerInput(fox::Application& app, const std::string& id);
        KeyboardKey m_Up;
        KeyboardKey m_Down;
        KeyboardKey m_Left;
        KeyboardKey m_Right;
        KeyboardKey m_putBomb;
        int m_Gamepad_Up;
        int m_Gamepad_Down;
        int m_Gamepad_Left;
        int m_Gamepad_Right;
        int m_Gamepad_putBomb;
        ray::Gamepad pad;
        bool operator==(const PlayerInput& input) const;
};


#endif //ECS_PLAYERINPUT_H
