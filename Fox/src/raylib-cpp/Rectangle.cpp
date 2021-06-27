/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Rectangle.cpp
*/

#include "raylib-cpp/Rectangle.hpp"

namespace ray
{

    Rectangle::Rectangle(const ::Rectangle& vec)
    {
        set(vec);
    }

    Rectangle::Rectangle(float x, float y, float width, float height) : ::Rectangle{x, y, width, height} {}
    Rectangle::Rectangle(float x, float y, float width, float height, ray::Color color) : ::Rectangle{x, y, width, height}
    {
        _color = color;
    }
    Rectangle::Rectangle(float x, float y, float width) : ::Rectangle{x, y, width, 0} {}
    Rectangle::Rectangle(float x, float y) : ::Rectangle{x, y, 0, 0} {}
    Rectangle::Rectangle(float x) : ::Rectangle{x, 0, 0, 0} {}
    Rectangle::Rectangle() : ::Rectangle{0, 0, 0, 0} {}
    Rectangle::Rectangle(Vec2 position, Vec2 size) : ::Rectangle{position.x, position.y, size.x, size.y} {}
    Rectangle::Rectangle(Vec2 size) : ::Rectangle{0, 0, size.x, size.y} {}

    Rectangle& Rectangle::operator=(const ::Rectangle& rect)
    {
        set(rect);
        return *this;
    }

    void Rectangle::setColor(ray::Color color)
    {
        _color = color;
    }

    ray::Color Rectangle::getColor() const
    {
        return _color;
    }

    ::Vector4 Rectangle::ToVector4()
    {
        return {x, y, width, height};
    }

    /**
     * Draw a color-filled rectangle
     */
    Rectangle& Rectangle::Draw()
    {
        ::DrawRectangle(static_cast<int>(x), static_cast<int>(y), static_cast<int>(width),
            static_cast<int>(height), _color);
        return *this;
    }

    Rectangle& Rectangle::Draw(Vec2 origin, float rotation, ::Color color)
    {
        ::DrawRectanglePro(*this, origin, rotation, color);
        return *this;
    }

    Rectangle& Rectangle::DrawGradientV(::Color color1, ::Color color2)
    {
        ::DrawRectangleGradientV(static_cast<int>(x), static_cast<int>(y), static_cast<int>(width),
            static_cast<int>(height), color1, color2);
        return *this;
    }

    Rectangle& Rectangle::DrawGradientH(::Color color1, ::Color color2)
    {
        ::DrawRectangleGradientH(static_cast<int>(x), static_cast<int>(y), static_cast<int>(width),
            static_cast<int>(height), color1, color2);
        return *this;
    }

    Rectangle& Rectangle::DrawGradient(::Color col1, ::Color col2, ::Color col3, ::Color col4)
    {
        ::DrawRectangleGradientEx(*this, col1, col2, col3, col4);
        return *this;
    }

    Rectangle& Rectangle::DrawLines(::Color color)
    {
        ::DrawRectangleLines(static_cast<int>(x), static_cast<int>(y), static_cast<int>(width),
            static_cast<int>(height), color);
        return *this;
    }

    Rectangle& Rectangle::DrawLines(::Color color, int lineThick)
    {
        ::DrawRectangleLinesEx(*this, lineThick, color);
        return *this;
    }

    Rectangle& Rectangle::DrawRounded(float roundness, int segments, ::Color color)
    {
        ::DrawRectangleRounded(*this, roundness, segments, color);
        return *this;
    }

    Rectangle& Rectangle::DrawRoundedLines(float roundness, int segments, int lineThick,
            ::Color color)
            {
        ::DrawRectangleRoundedLines(*this, roundness, segments, lineThick, color);
        return *this;
    }

    /**
     * Check collision between two rectangles
     */
    bool Rectangle::CheckCollision(::Rectangle rec2) const
    {
        return ::CheckCollisionRecs(*this, rec2);
    }

    /**
     * Get collision rectangle for two rectangles collision
     */
    ::Rectangle Rectangle::GetCollision(::Rectangle rec2) const
    {
        return ::GetCollisionRec(*this, rec2);
    }

    /**
     * Check if point is inside rectangle
     */
    bool Rectangle::CheckCollision(Vec2 point) const
    {
        return ::CheckCollisionPointRec(point, *this);
    }

    /**
     * Check collision between circle and rectangle
     */
    bool Rectangle::CheckCollision(Vec2 center, float radius)
    {
        return ::CheckCollisionCircleRec(center, radius, *this);
    }

    Vec2 Rectangle::GetSize() {
        return {width, height};
    }

    Rectangle& Rectangle::SetSize(float newWidth, float newHeight)
    {
        width = newWidth;
        height = newHeight;
        return *this;
    }

    Rectangle& Rectangle::SetSize(const Vec2& size)
    {
        return SetSize(size.x, size.y);
    }

    Vec2 Rectangle::GetPosition() {
        return {x, y};
    }

    Rectangle& Rectangle::SetPosition(float newX, float newY)
    {
        x = newX;
        y = newY;
        return *this;
    }

    Rectangle& Rectangle::SetPosition(const Vec2& position)
    {
        return SetPosition(position.x, position.y);
    }

    void Rectangle::set(const ::Rectangle& rect)
    {
        x = rect.x;
        y = rect.y;
        width = rect.width;
        height = rect.height;
    }
} // namespace ray