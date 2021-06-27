/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Font.hpp
*/

#ifndef RAYLIB_FONT_HPP_
#define RAYLIB_FONT_HPP_

#include <string>
#include "raylib.hpp"
#include "Utils/Vec3.hpp"
#include "Utils/Vec2.hpp"
#include "Color.hpp"

namespace ray {
    class Font : public ::Font {
    public:
        Font();
        Font(const ::Font& font);
        Font(const std::string& fileName);
        Font(const std::string& fileName, int fontSize, int* fontChars, int charCount);
        Font(const ::Image& image, ::Color key, int firstChar);
        Font(const std::string& fileType, const unsigned char* fileData, int dataSize, int fontSize, int *fontChars, int charsCount);
        ~Font();
        void Unload();
        Font& operator=(const ::Font& font);
        Font& DrawText(const std::string& text, Vec2 position, float fontSize, float spacing, ::Color tint = ray::Color(255, 255, 255, 255));
        Font& DrawText(const std::string& text, ::Rectangle rec, float fontSize, float spacing, bool wordWrap = false, ::Color tint = ray::Color(255, 255, 255, 255));
        Font& DrawText(const std::string& text, ::Rectangle rec, float fontSize, float spacing, bool wordWrap, ::Color tint, int selectStart, int selectLength, ::Color selectText, ::Color selectBack);
        Font& DrawText(int codepoint, Vec2 position, float fontSize, ::Color tint = { 255, 255, 255, 255 });
        Vec2 MeasureText(const std::string& text, float fontSize, float spacing) const;
        int GetGlyphIndex(int character) const;
        ::Image ImageText(const std::string& text, float fontSize, float spacing, ::Color tint) const;
        void set(const ::Font& font);
    };
}  // namespace ray

#endif  // RAYLIB_FONT_HPP_