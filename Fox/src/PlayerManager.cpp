/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** PlayerManager.cpp
*/

#include <Core/Input/Input.hpp>
#include "Components/PlayerInput.h"
#include "Core/PlayerManager.hpp"

namespace fox
{
    std::unordered_map<KeyboardKey, bool> Input::m_vStates;
    std::unordered_map<int, std::string> Input::IntString = {
        {0, ""},
        {1, "assets/button/D-Pad-Up.png"},
        {2, "assets/button/D-Pad-Right.png"},
        {3, "assets/button/D-Pad-Down.png"},
        {4, "assets/button/D-Pad-Left.png"},
        {5, "assets/button/triangle.png"},
        {6, "assets/button/rond.png"},
        {7, "assets/button/croix.png"},
        {8, "assets/button/carré.png"}
    };

    std::unordered_map<std::string, KeyboardKey> Input::StringKey = {
                                   {"A", KEY_A},
                                   {"B", KEY_B},
                                   {"C", KEY_C},
                                   {"D", KEY_D},
                                   {"E", KEY_E},
                                   {"F", KEY_F},
                                   {"G", KEY_G},
                                   {"H", KEY_H},
                                   {"I", KEY_I},
                                   {"J", KEY_J},
                                   {"K", KEY_K},
                                   {"L", KEY_L},
                                   {"M", KEY_M},
                                   {"N", KEY_N},
                                   {"O", KEY_O},
                                   {"P", KEY_P},
                                   {"Q", KEY_Q},
                                   {"R", KEY_R},
                                   {"S", KEY_S},
                                   {"T", KEY_T},
                                   {"U", KEY_U},
                                   {"V", KEY_V},
                                   {"W", KEY_W},
                                   {"X", KEY_X},
                                   {"Y", KEY_Y},
                                   {"Z", KEY_Z},
                                   {"Up", KEY_UP},
                                   {"Down", KEY_DOWN},
                                   {"Left", KEY_LEFT},
                                   {"Right", KEY_RIGHT},
                                   {"Space", KEY_SPACE},
                                   {"Escape", KEY_ESCAPE},
                                   {"Enter", KEY_ENTER},
                                   {"Tab", KEY_TAB},
                                   {"Backspace", KEY_BACKSPACE}};

    std::unordered_map<KeyboardKey, std::string> Input::KeyString = {
                          {KEY_A, "A"},
                          {KEY_B, "B"},
                          {KEY_C, "C"},
                          {KEY_D, "D"},
                          {KEY_E, "E"},
                          {KEY_F, "F"},
                          {KEY_G, "G"},
                          {KEY_H, "H"},
                          {KEY_I, "I"},
                          {KEY_J, "J"},
                          {KEY_K, "K"},
                          {KEY_L, "L"},
                          {KEY_M, "M"},
                          {KEY_N, "N"},
                          {KEY_O, "O"},
                          {KEY_P, "P"},
                          {KEY_Q, "Q"},
                          {KEY_R, "R"},
                          {KEY_S, "S"},
                          {KEY_T, "T"},
                          {KEY_U, "U"},
                          {KEY_V, "V"},
                          {KEY_W, "W"},
                          {KEY_X, "X"},
                          {KEY_Y, "Y"},
                          {KEY_Z, "Z"},
                          {KEY_UP, "Up"},
                          {KEY_DOWN, "Down"},
                          {KEY_LEFT, "Left"},
                          {KEY_RIGHT, "Right"},
                          {KEY_ESCAPE, "Escape"},
                          {KEY_ENTER, "Enter"},
                          {KEY_TAB, "Tab"},
                          {KEY_SPACE, "Space"},
                          {KEY_BACKSPACE, "Backspace"}};

    PlayerManager::PlayerManager() : m_pCurr(nullptr) {}

    PlayerManager::PlayerManager(std::unordered_map<std::string, PlayerInput>&& list) : m_pCurr(nullptr)
    {
        v_PlayerInput = list;
        _isChangingKey = false;
        _selectedKey = fox::SelectedKey::NONE;
        setCurrent(1);
    }

    const std::unordered_map<std::string, PlayerInput> &PlayerManager::getInputs()
    {
        return v_PlayerInput;
    }

    void PlayerManager::setChangingKey(bool state)
    {
        _isChangingKey = state;
    }

    bool PlayerManager::isKeyChanging() const
    {
        return _isChangingKey;
    }

    void PlayerManager::setSelectedKey(SelectedKey state)
    {
        _selectedKey = state;
    }

    SelectedKey PlayerManager::getSelectedKey() const
    {
        return _selectedKey;
    }

    void PlayerManager::ChangeSpecificKey(KeyboardKey new_key, SelectedKey key_to_change)
    {
        switch (key_to_change)
        {
            case fox::SelectedKey::KEY_UP:
                m_pCurr->m_Up = new_key;
                break;
            case fox::SelectedKey::KEY_DOWN:
                m_pCurr->m_Down = new_key;
                break;
            case fox::SelectedKey::KEY_LEFT:
                m_pCurr->m_Left = new_key;
                break;
            case fox::SelectedKey::KEY_RIGHT:
                m_pCurr->m_Right = new_key;
                break;
            case fox::SelectedKey::KEY_BOMB:
                m_pCurr->m_putBomb = new_key;
                break;
            default:
                break;
        }
    }

    void PlayerManager::ChangeSpecificButton(int new_button, SelectedKey key_to_change)
    {
        switch (key_to_change)
        {
            case fox::SelectedKey::KEY_GAMEPAD_UP:
                m_pCurr->m_Gamepad_Up = new_button;
                break;
            case fox::SelectedKey::KEY_GAMEPAD_DOWN:
                m_pCurr->m_Gamepad_Down = new_button;
                break;
            case fox::SelectedKey::KEY_GAMEPAD_LEFT:
                m_pCurr->m_Gamepad_Left = new_button;
                break;
            case fox::SelectedKey::KEY_GAMEPAD_RIGHT:
                m_pCurr->m_Gamepad_Right = new_button;
                break;
            case fox::SelectedKey::KEY_GAMEPAD_BOMB:
                m_pCurr->m_Gamepad_putBomb = new_button;
                break;
            default:
                break;
        }
    }

    const PlayerInput &PlayerManager::getCurrentInput()
    {
        return *m_pCurr;
    }

    const PlayerInput& PlayerManager::getInput(const std::string &str)
    {
        return v_PlayerInput[str];
    }

    void PlayerManager::setCurrent(int id)
    {
        if (id >= 5)
            id = 1;
        else if (id <= 0)
            id = 4;
        m_iCurrId = id;
        std::string str = "player" + std::to_string(id);
        m_pCurr = &v_PlayerInput[str];
    }

    int PlayerManager::getCurrentId()
    {
        return m_iCurrId;
    }

    void PlayerManager::setPlayerNames(std::vector<std::string> &playerNames)
    {
        v_PlayerNames = playerNames;
    }

    const std::vector<std::string>& PlayerManager::getPlayerNames() const
    {
        return v_PlayerNames;
    }

    const std::string& PlayerManager::getPlayerNameAtIndex(int index) const
    {
        return v_PlayerNames.at(index);
    }

    const std::string& PlayerManager::getPlayerColorAtIndex(int index) const
    {
        std::string key = "player" + std::to_string(index);
        return v_SkinColor.at(key);
    }

    bool PlayerManager::isKeyFree(KeyboardKey key)
    {
        int x = 0;

        for (PlayerInput tmp = getInput("player" + std::to_string(x)); x < 5; x++) {
            if (tmp.m_Down == key)
                return (false);
            if (tmp.m_Left == key)
                return (false);
            if (tmp.m_Right == key)
                return (false);
            if (tmp.m_Up == key)
                return (false);
            if (tmp.m_putBomb == key)
                return (false);
            tmp = getInput("player" + std::to_string(x + 1));
        }
        return (true);
    }

    bool PlayerManager::isButtonFree(int button, int x)
    {
        PlayerInput pad = getInput("player" + std::to_string(x));

        if (pad.m_Gamepad_Down == button)
            return (false);
        if (pad.m_Gamepad_Left == button)
            return (false);
        if (pad.m_Gamepad_Right == button)
            return (false);
        if (pad.m_Gamepad_Up == button)
            return (false);
        if (pad.m_Gamepad_putBomb == button)
            return (false);
        return (true);
    }

    const std::unordered_map<std::string, int>& PlayerManager::getScores()
    {
        return v_PlayerScore;
    }

    int PlayerManager::getScore(const std::string& str)
    {
        return v_PlayerScore.at(str);
    }

    void PlayerManager::updateScore(std::unordered_map<std::string, int> &v_Score)
    {
        v_PlayerScore = v_Score;
    }

    void PlayerManager::updateSkin(std::string index, int color)
    {
        switch (color)
        {
        case 1:
            v_SkinColor[index] = "white";
            break;
        case 2:
            v_SkinColor[index] = "black";
            break;
        case 3:
            v_SkinColor[index] = "blue";
            break;
        case 4:
            v_SkinColor[index] = "pink";
            break;
        default:
            break;
        }
        std::cout << "New skin:" << v_SkinColor[index] << " at index " << index << "|| COLOR: " << color << std::endl;
    }

    void PlayerManager::incrementScore(const std::string &playerName, int nbr)
    {
        v_PlayerScore.at(playerName) += nbr;
    }
}