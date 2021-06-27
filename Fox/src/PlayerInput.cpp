/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** PlayerInput.cpp
*/

#include <Core/Application.hpp>
#include "Components/PlayerInput.h"

#include <utility>

PlayerInput::PlayerInput()
{
    m_Gamepad_Up = 1;
    m_Gamepad_Down = 3;
    m_Gamepad_Left = 4;
    m_Gamepad_Right = 2;
    m_Gamepad_putBomb = 7;
    m_Up = KEY_NULL;
    m_Down = KEY_NULL;
    m_Left = KEY_NULL;
    m_Right = KEY_NULL;
    m_putBomb = KEY_NULL;
}

PlayerInput::PlayerInput(fox::Application& app, const std::string& id)
{
    m_Up = app.get_player_manager().getInput(id).m_Up;
    m_Down = app.get_player_manager().getInput(id).m_Down;
    m_Left = app.get_player_manager().getInput(id).m_Left;
    m_Right = app.get_player_manager().getInput(id).m_Right;
    m_putBomb = app.get_player_manager().getInput(id).m_putBomb;
    m_Gamepad_Up = app.get_player_manager().getInput(id).m_Gamepad_Up;
    m_Gamepad_Down = app.get_player_manager().getInput(id).m_Gamepad_Down;
    m_Gamepad_Left = app.get_player_manager().getInput(id).m_Gamepad_Left;
    m_Gamepad_Right = app.get_player_manager().getInput(id).m_Gamepad_Right;
    m_Gamepad_putBomb = app.get_player_manager().getInput(id).m_Gamepad_putBomb;
    pad = app.get_player_manager().getInput(id).pad;
}

bool PlayerInput::operator==(const PlayerInput& input) const
{
    return (m_Gamepad_Down == input.m_Gamepad_Down
    && m_Gamepad_Left == input.m_Gamepad_Left
    && m_Gamepad_putBomb == input.m_Gamepad_putBomb
    && m_Gamepad_Right == input.m_Gamepad_Right
    && m_Gamepad_Up == input.m_Gamepad_Up
    && m_Up == input.m_Up && m_Down == input.m_Down
    && m_Left == input.m_Left && m_putBomb == input.m_putBomb
    && m_Right == input.m_Right);
}

//PlayerInput::PlayerInput(KeyboardKey up, KeyboardKey down, KeyboardKey left, KeyboardKey right, KeyboardKey bomb)
//    : m_Up(up),
//    m_Down(down),
//    m_Left(left),
//    m_Right(right),
//    m_putBomb(m_putBomb) {}