/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Gamepad.hpp
*/

#ifndef RAYLIB_GAMEPAD_HPP_
#define RAYLIB_GAMEPAD_HPP_

#include <string>
#include "raylib.hpp"

namespace ray {
    class Gamepad {
    public:
        Gamepad(int gamepadNumber = 0);

        Gamepad& operator=(const Gamepad& gamepad);
        bool operator==(const Gamepad& gamepad) const;
        Gamepad& operator=(int gamepadNumber);
        int GetPadNumber() const;
        bool IsAvailable() const;
        bool IsAvailable(int number);
        bool IsName(const std::string& name) const;
        std::string GetName() const;
        operator std::string() const;
        bool IsButtonPressed(int button) const;
        bool IsButtonDown(int button) const;
        bool IsButtonReleased(int button) const;
        bool IsButtonUp(int button) const;
        int GetPressedButtonOnSpecificPad() const;
        int GetButtonPressed() const;
        int GetAxisCount() const;
        float GetAxisMovement(int axis) const;
        void set(int gamepadNumber);

    private:
        int number;
    };
}  // namespace ray

#endif  // RAYLIB_GAMEPAD_HPP_