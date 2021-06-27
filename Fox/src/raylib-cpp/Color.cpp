/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Color.cpp
*/

#include "raylib-cpp/Color.hpp"

namespace ray
{
    Color::Color() : ::Color{0, 0, 0, 255} {};

    Color::Color(const ::Color& color)
    {
        set(color);
    }

    Color::Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) : ::Color{red, green, blue, alpha} {};

    Color::~Color() {}


    void Color::set(const ::Color& color)
    {
        r = color.r;
        g = color.g;
        b = color.b;
        a = color.a;
    }

    Color& Color::operator=(const ::Color& color)
    {
        set(color);
        return *this;
    }

    bool Color::operator==(const Color& color) const
    {
        return (a == color.a && b == color.b && g == color.g && r == color.r);
    }

    Color& Color::DrawPixel(Vec2 pos)
    {
        ::DrawPixelV(pos, *this);
        return *this;
    }

    Color& Color::DrawLine(int startPosX, int startPosY, int endPosX, int endPosY)
    {
        ::DrawLine(startPosX, startPosY, endPosX, endPosY, *this);
        return *this;
    }

    Color& Color::DrawLine(Vec2 startPos, Vec2 endPos)
    {
        ::DrawLineV(startPos, endPos, *this);
        return *this;
    }

    Color& Color::DrawLine(Vec2 startPos, Vec2 endPos, float thick)
    {
        ::DrawLineEx(startPos, endPos, thick, *this);
        return *this;
    }

    Color& Color::DrawLineBezier(Vec2 startPos, Vec2 endPos, float thick)
    {
        ::DrawLineBezier(startPos, endPos, thick, *this);
        return *this;
    }

    Color& Color::DrawLineStrip(Vec2 *points, int numPoints) {
        ::DrawLineStrip(points, numPoints, *this);
        return *this;
    }

    Color& Color::DrawText(const std::string& text, int posX, int posY, int fontSize)
    {
        ::DrawText(text.c_str(), posX, posY, fontSize, *this);
        return *this;
    }

    Color& Color::DrawText(const ::Font& font, const std::string& text, Vec2 position,
        float fontSize, float spacing)
    {
        ::DrawTextEx(font, text.c_str(), position, fontSize, spacing, *this);
        return *this;
    }

    Color& Color::DrawText(const ::Font& font, const std::string& text,
        ::Rectangle rec, float fontSize, float spacing, bool wordWrap)
    {
        ::DrawTextRec(font, text.c_str(), rec, fontSize, spacing, wordWrap, *this);
        return *this;
    }

    Color& Color::DrawRectangle(int posX, int posY, int width, int height)
    {
        ::DrawRectangle(posX, posY, width, height, *this);
        return *this;
    }

    Color& Color::DrawRectangle(Vec2 position, Vec2 size)
    {
        ::DrawRectangleV(position, size, *this);
        return *this;
    }

    Color& Color::DrawRectangle(::Rectangle rec)
    {
        ::DrawRectangleRec(rec, *this);
        return *this;
    }

    Color& Color::DrawRectangle(::Rectangle rec, Vec2 origin, float rotation)
    {
        ::DrawRectanglePro(rec, origin, rotation, *this);
        return *this;
    }

    Color& Color::DrawRectangleLines(int posX, int posY, int width, int height)
    {
        ::DrawRectangleLines(posX, posY, width, height, *this);
        return *this;
    }

    Color& Color::DrawRectangleLines(::Rectangle rec, int lineThick)
    {
        ::DrawRectangleLinesEx(rec, lineThick, *this);
        return *this;
    }


} // namespace ray