/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Color.hpp
*/

#ifndef RAYLIB_COLOR_HPP_
#define RAYLIB_COLOR_HPP_

#include <string>
#include "raylib.hpp"
#include "Utils/Vec3.hpp"
#include "Utils/Vec2.hpp"

namespace ray {
    class Color : public ::Color {
    public:
        Color();
        Color(const ::Color& color);
        Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 255);
        ~Color();
        Color& operator=(const ::Color& color);
        bool operator==(const Color& color) const;
        Color& DrawPixel(Vec2 pos);
        Color& DrawLine(int startPosX, int startPosY, int endPosX, int endPosY);
        Color& DrawLine(Vec2 startPos, Vec2 endPos);
        Color& DrawLine(Vec2 startPos, Vec2 endPos, float thick);
        Color& DrawLineBezier(Vec2 startPos, Vec2 endPos, float thick);
        Color& DrawLineStrip(Vec2 *points, int numPoints);
        Color& DrawText(const std::string& text, int posX, int posY, int fontSize);
        Color& DrawText(const ::Font& font, const std::string& text, Vec2 position,
            float fontSize, float spacing);
        Color& DrawText(const ::Font& font, const std::string& text, ::Rectangle rec,
            float fontSize, float spacing, bool wordWrap = false);
        Color& DrawRectangle(int posX, int posY, int width, int height);
        Color& DrawRectangle(Vec2 position, Vec2 size);
        Color& DrawRectangle(::Rectangle rec);
        Color& DrawRectangle(::Rectangle rec, Vec2 origin, float rotation);
        Color& DrawRectangleLines(int posX, int posY, int width, int height);
        Color& DrawRectangleLines(::Rectangle rec, int lineThick);
        void set(const ::Color& color);
    };
} // namespace ray

#endif  // RAYLIB_COLOR_HPP_