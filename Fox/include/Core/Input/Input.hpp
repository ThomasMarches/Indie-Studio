/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Input.hpp
*/

#ifndef FOX_INPUT_HPP_
#define FOX_INPUT_HPP_

#include <unordered_map>
#include "Utils/Vec2.hpp"

namespace fox
{
	class Input
	{
	public:
        /**
         * @brief Detect if a key is pressed/released
         * @param key the key
         * @return true if the key is pressed/released otherwise false
         */
		static bool get_key(KeyboardKey key)
        {
            return ::IsKeyDown(key);
        }

        /**
         * @brief Detect if a key is released
         * @param key the key
         * @return true if the key is released otherwise false
         */
		static bool get_key_up(KeyboardKey key)
        {
            return ::IsKeyReleased(key);
        }

        /**
         * @brief Detect if a key is pressed
         * @param key the key
         * @return true if the key is pressed otherwise false
         */
        static bool get_key_down(KeyboardKey key)
        {
            bool is_pressed = ::IsKeyPressed(key);
            bool is_valid = is_pressed && !m_vStates[key];
            m_vStates[key] = is_pressed;
            return is_valid;
        }

        /**
         * @brief Detect if a mouse button is pressed/released
         * @param button the mouse button
         * @return true if the mouse button is pressed/released otherwise false
         */
        static bool get_mouse_btn(MouseButton button)
        {
            return ::IsMouseButtonDown(button);
        }

        /**
         * @brief Detect if a mouse button is released
         * @param button the mouse button
         * @return true if the mouse button is released otherwise false
         */
        static bool get_mouse_btn_up(MouseButton button)
        {
            return ::IsMouseButtonReleased(button);
        }

        /**
         * @brief Detect if a mouse button is pressed
         * @param button the mouse button
         * @return true if the mouse button is pressed otherwise false
         */
        static bool get_mouse_btn_down(MouseButton button)
        {
            return ::IsMouseButtonPressed(button);
        }

        /**
         * @brief Get the mouse position
         * @return X and Y position of the mouse
         */
        static Vec2 mouse_pos()
        {
            Vector2 v = ::GetMousePosition();
            return Vec2(v.x, v.y);
        }

        /**
         * @brief Returns mouse wheel movement Y
         * @return mouse wheel movement Y
         */
        static float mouse_wheel()
        {
            return ::GetMouseWheelMove();
        }

        /**
         * @brief Get key pressed
         * @return pressed key
         */
        static int get_pressed_key()
        {
            return ::GetKeyPressed();
        }

        /**
         * @brief Get the last gamepad button pressed
         * @return the last gamepad button pressed
         */
        static int get_pressed_button()
        {
            return ::GetGamepadButtonPressed();
        }

        /**
         * @brief Convert @KeyboardKey to string
         * @param key the key to convert
         * @return the string value of the enum
         */
        static std::string key_to_string(KeyboardKey key)
        {
            return KeyString[key];
        }

        /**
         * @brief Convert string to @KeyboardKey
         * @param str the string to convert
         * @return the enum value of the string
         */
        static KeyboardKey string_to_key(const std::string& str)
        {
            return StringKey[str];
        }

        /**
         * @brief Convert index to the filepath of the image
         * @param value the index
         * @return the filepath of the image
         */
        static std::string button_to_image(int value)
        {
            return IntString[value];
        }

    private:
        static std::unordered_map<std::string, KeyboardKey> StringKey;
        static std::unordered_map<KeyboardKey, std::string> KeyString;
        static std::unordered_map<int, std::string> IntString;
        static std::unordered_map<KeyboardKey, bool> m_vStates;
	};
}

#endif