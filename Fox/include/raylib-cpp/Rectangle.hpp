/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Rectangle.hpp
*/

#ifndef RAYLIB_RECTANGLE_HPP_
#define RAYLIB_RECTANGLE_HPP_

#include <string>
#include "raylib.hpp"
#include "Utils/Vec3.hpp"
#include "Utils/Vec2.hpp"
#include "Color.hpp"

namespace ray {
    class Rectangle : public ::Rectangle {
    public:
        Rectangle(const ::Rectangle& vec);
        Rectangle(float x, float y, float width, float height, ray::Color color);
        Rectangle(float x, float y, float width, float height);
        Rectangle(float x, float y, float width);
        Rectangle(float x, float y);
        Rectangle(float x);
        Rectangle();
        Rectangle(Vec2 position, Vec2 size);
        Rectangle(Vec2 size);
        Rectangle& operator=(const ::Rectangle& rect);
        ::Vector4 ToVector4();
        virtual Rectangle& Draw();
        Rectangle& Draw(Vec2 origin, float rotation, ::Color color);
        Rectangle& DrawGradientV(::Color color1, ::Color color2);
        Rectangle& DrawGradientH(::Color color1, ::Color color2);
        Rectangle& DrawGradient(::Color col1, ::Color col2, ::Color col3, ::Color col4);
        Rectangle& DrawLines(::Color color);
        Rectangle& DrawLines(::Color color, int lineThick);
        Rectangle& DrawRounded(float roundness, int segments, ::Color color);
        Rectangle& DrawRoundedLines(float roundness, int segments, int lineThick, ::Color color);
        bool CheckCollision(::Rectangle rec2) const;
        ::Rectangle GetCollision(::Rectangle rec2) const;
        bool CheckCollision(Vec2 point) const;
        bool CheckCollision(Vec2 center, float radius);
        Vec2 GetSize();
        Rectangle& SetSize(float newWidth, float newHeight);
        Rectangle& SetSize(const Vec2& size);
        Vec2 GetPosition();
        Rectangle& SetPosition(float newX, float newY);
        Rectangle& SetPosition(const Vec2& position);
        void set(const ::Rectangle& rect);
        void setColor(ray::Color color);
        ray::Color getColor() const;
    private:
        ray::Color _color;
    };
}  // namespace ray

#endif  // RAYLIB_RECTANGLE_HPP_