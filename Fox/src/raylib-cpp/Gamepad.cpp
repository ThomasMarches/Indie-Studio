/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Gamepad.cpp
*/

#include "raylib-cpp/Gamepad.hpp"

namespace ray
{
    Gamepad::Gamepad(int gamepadNumber)
    {
        set(gamepadNumber);
    }

    bool Gamepad::operator==(const Gamepad& gamepad) const
    {
        return GetPadNumber() == gamepad.GetPadNumber();
    }

    Gamepad& Gamepad::operator=(const Gamepad& gamepad)
    {
        set(gamepad.number);
        return *this;
    }

    Gamepad& Gamepad::operator=(int gamepadNumber)
    {
        set(gamepadNumber);
        return *this;
    }

    int Gamepad::GetPadNumber() const
    {
        return number;
    }

    /**
     * Detect if a gamepad is available
     */
    bool Gamepad::IsAvailable() const
    {
        return ::IsGamepadAvailable(number);
    }

    /**
     * Detect if a gamepad is available
     */
    bool Gamepad::IsAvailable(int number)
    {
        return ::IsGamepadAvailable(number);
    }

    /**
     * Return gamepad internal name id
     */
    std::string Gamepad::GetName() const
    {
        return ::GetGamepadName(number);
    }

    /**
     * Detect if a gamepad button has been pressed once
     */
    bool Gamepad::IsButtonPressed(int button) const
    {
        return ::IsGamepadButtonPressed(number, button);
    }

    /**
     * Detect if a gamepad button is being pressed
     */
    bool Gamepad::IsButtonDown(int button) const
    {
        return ::IsGamepadButtonDown(number, button);
    }

    /**
     * Detect if a gamepad button has been released once
     */
    bool Gamepad::IsButtonReleased(int button) const
    {
        return ::IsGamepadButtonReleased(number, button);
    }

    /**
     * Detect if a gamepad button is NOT being pressed
     */
    bool Gamepad::IsButtonUp(int button) const
    {
        return ::IsGamepadButtonUp(number, button);
    }

    /**
     * Get the last gamepad button pressed
     */
    int Gamepad::GetButtonPressed() const
    {
        return ::GetGamepadButtonPressed();
    }

    /**
     * Return gamepad axis count for a gamepad
     */
    int Gamepad::GetAxisCount() const
    {
        return ::GetGamepadAxisCount(number);
    }

    /**
     * Return axis movement value for a gamepad axis
     */
    float Gamepad::GetAxisMovement(int axis) const
    {
        return ::GetGamepadAxisMovement(number, axis);
    }

    void Gamepad::set(int gamepadNumber)
    {
        number = gamepadNumber;
    }

    int Gamepad::GetPressedButtonOnSpecificPad() const
    {
        for (int x = 1; x != 9; x++) {
            if (IsButtonPressed(x) == 1) {
                return (x);
            }
        }
        return (0);
    }

} // namespace ray