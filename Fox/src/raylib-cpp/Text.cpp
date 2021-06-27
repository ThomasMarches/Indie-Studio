/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Text.cpp
*/

#include "raylib-cpp/Text.hpp"
#include "raylib-cpp/Color.hpp"

namespace ray
{
    Text::Text(const std::string& text) : m_strText(text), m_iFontSize(20), m_oColor(ray::Color(200, 200, 200, 200))
    {
    }

    Text::Text(const std::string& text, Color color) : m_strText(text), m_iFontSize(20), m_oColor(color)
    {
    }

    void Text::Draw(int x, int y)
    {
        ::DrawText(m_strText.c_str(), x, y, m_iFontSize, m_oColor);
    }

    Text& Text::SetString(const std::string& strString)
    {
        m_strText = strString;
        return *this;
    }

    Text& Text::SetColor(Color c)
    {
        m_oColor = c;
        return *this;
    }

    Text& Text::SetFontSize(int iFontSize)
    {
        m_iFontSize = iFontSize;
        return *this;
    }

    const std::string& Text::GetString() const
    {
        return m_strText;
    }

    ray::Color Text::GetColor() const
    {
        return m_oColor;
    }

    ray::Color& Text::GetColor()
    {
        return m_oColor;
    }

    int Text::GetFontSize() const
    {
        return m_iFontSize;
    }

    int Text::GetTextWidth(const std::string &str, int FontSize)
    {
        return MeasureText(str.c_str(), FontSize);
    }
} // namespace ray