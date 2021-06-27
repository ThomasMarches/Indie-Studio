/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Mouse.hpp
*/

#ifndef RAYLIB_MOUSE_HPP_
#define RAYLIB_MOUSE_HPP_

#include <string>
#include "raylib.hpp"
#include "Utils/Vec3.hpp"
#include "Utils/Vec2.hpp"

namespace ray {
    class Mouse {
    public:
        bool IsButtonPressed(int button);
        bool IsButtonDown(int button);
        bool IsButtonReleased(int button);
        bool IsButtonUp(int button);
        int GetX();
        int GetY();
        void SetX(int x);
        void SetY(int y);
        Vec2 GetPosition();
        void SetPosition(int x, int y);
        void SetOffset(int offsetX, int offsetY);
        void SetScale(float scaleX, float scaleY);
        float GetWheelMove();
        void SetCursor(int cursor);
        int GetTouchX();
        int GetTouchY();
        Vec2 GetTouchPosition(int index);
    };
}  // namespace ray

#endif  // RAYLIB_MOUSE_HPP_