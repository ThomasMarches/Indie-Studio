/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Mouse.cpp
*/

#include "raylib-cpp/Mouse.hpp"

namespace ray
{
    bool Mouse::IsButtonPressed(int button)
    {
        return ::IsMouseButtonPressed(button);
    }

    /**
     * Detect if a mouse button is being pressed
     */
    bool Mouse::IsButtonDown(int button)
    {
        return ::IsMouseButtonDown(button);
    }

    /**
     * Detect if a mouse button has been released once
     */
    bool Mouse::IsButtonReleased(int button)
    {
        return ::IsMouseButtonReleased(button);
    }

    bool Mouse::IsButtonUp(int button)
    {
        return ::IsMouseButtonUp(button);
    }

    int Mouse::GetX()
    {
        return ::GetMouseX();
    }

    int Mouse::GetY()
    {
        return ::GetMouseY();
    }

    void Mouse::SetX(int x)
    {
        ::SetMousePosition(x, GetY());
    }

    void Mouse::SetY(int y)
    {
        ::SetMousePosition(GetX(), y);
    }

    Vec2 Mouse::GetPosition()
    {
        Vector2 v = ::GetMousePosition();
        return Vec2(v.x, v.y);
    }

    void Mouse::SetPosition(int x, int y)
    {
        ::SetMousePosition(x, y);
    }

    void Mouse::SetOffset(int offsetX, int offsetY)
    {
        ::SetMouseOffset(offsetX, offsetY);
    }

    void Mouse::SetScale(float scaleX, float scaleY)
    {
        ::SetMouseScale(scaleX, scaleY);
    }

    float Mouse::GetWheelMove()
    {
        return ::GetMouseWheelMove();
    }

    void Mouse::SetCursor(int cursor)
    {
        ::SetMouseCursor(cursor);
    }

    int Mouse::GetTouchX()
    {
        return ::GetTouchX();
    }

    int Mouse::GetTouchY()
    {
        return ::GetTouchY();
    }

    Vec2 Mouse::GetTouchPosition(int index)
    {
        Vector2 v = ::GetTouchPosition(index);
        return Vec2(v.x, v.y);
    }

} // namespace ray