/*
** EPITECH PROJECT, 2021
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** PlayerManager.hpp header
*/

#ifndef PLAYER_MANAGER_HPP
#define PLAYER_MANAGER_HPP

#include <unordered_map>
#include "Components/PlayerInput.h"
#include "raylib-cpp/Keyboard.hpp"
#include "raylib-cpp/Gamepad.hpp"
#include <vector>

namespace fox
{
    enum class SelectedKey
    {
        KEY_UP,
        KEY_DOWN,
        KEY_LEFT,
        KEY_RIGHT,
        KEY_BOMB,
        KEY_GAMEPAD_UP,
        KEY_GAMEPAD_DOWN,
        KEY_GAMEPAD_LEFT,
        KEY_GAMEPAD_RIGHT,
        KEY_GAMEPAD_BOMB,
        NONE
    };

    class PlayerManager
    {
        public:
            PlayerManager();
            explicit PlayerManager(std::unordered_map<std::string, PlayerInput>&& list);
            const std::unordered_map<std::string, PlayerInput>& getInputs();
            const std::unordered_map<std::string, int>& getScores();
            const PlayerInput& getCurrentInput();
            void setCurrent(int id);
            const PlayerInput& getInput(const std::string& str);
            int getScore(const std::string& str);
            int getCurrentId();
            void setChangingKey(bool state);
            bool isKeyChanging() const;
            void setSelectedKey(SelectedKey state);
            SelectedKey getSelectedKey() const;
            void updateScore(std::unordered_map<std::string, int> &v_Score);
            void updateSkin(std::string index, int color);
            void incrementScore(const std::string &playerName, int nbr);
            const std::vector<std::string>& getPlayerNames() const;
            const std::string & getPlayerNameAtIndex(int index) const;
            const std::string & getPlayerColorAtIndex(int index) const;
            void setPlayerNames(std::vector<std::string> &playerNames);
            void ChangeSpecificKey(KeyboardKey new_key, SelectedKey key_to_change); // KEYBOARD
            void ChangeSpecificButton(int new_button, SelectedKey key_to_change); // GAMEPAD
            bool isKeyFree(KeyboardKey key); // KEYBOARD
            bool isButtonFree(int button, int x); // GAMEPAD
        private:
            std::unordered_map<std::string, PlayerInput> v_PlayerInput;
            std::unordered_map<std::string, int> v_PlayerScore;
            std::unordered_map<std::string, std::string> v_SkinColor;
            std::vector<std::string> v_PlayerNames;
            bool _isChangingKey;
            SelectedKey _selectedKey;
            PlayerInput* m_pCurr;
            int m_iCurrId;
    };
}

#endif // PLAYER_MANAGER_HPP
