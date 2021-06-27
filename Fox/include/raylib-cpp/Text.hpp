/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Text.hpp
*/

#ifndef RAYLIB_TEXT_HPP_
#define RAYLIB_TEXT_HPP_

#include <string>
#include "raylib.hpp"
#include "raylib-cpp/Color.hpp"

namespace ray
{
    class Text {
    public:
        Text(const std::string& text);
        Text(const std::string& text, Color color);
        void Draw(int x, int y);

        Text& SetString(const std::string& strString);
        Text& SetColor(Color color);
        Text& SetFontSize(int iFontSize);

        const std::string& GetString() const;
        ray::Color GetColor() const;
        ray::Color& GetColor();
        int GetFontSize() const;
        static int GetTextWidth(const std::string &str, int FontSize);

    private:
        std::string m_strText;
        ray::Color m_oColor;
        int m_iFontSize;
    };
}  // namespace ray

#endif  // RAYLIB_TEXT_HPP_