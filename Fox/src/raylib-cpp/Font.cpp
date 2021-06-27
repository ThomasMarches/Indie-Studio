/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Font.cpp
*/

#include "raylib-cpp/Font.hpp"

namespace ray
{
    Font::Font()
    {
        set(::GetFontDefault());
    }

    Font::Font(const ::Font& font)
    {
        set(font);
    }

    Font::Font(const std::string& fileName)
    {
        set(::LoadFont(fileName.c_str()));
    }

    Font::Font(const std::string& fileName, int fontSize, int* fontChars, int charCount)
    {
        set(::LoadFontEx(fileName.c_str(), fontSize, fontChars, charCount));
    }

    Font::Font(const ::Image& image, ::Color key, int firstChar)
    {
        set(::LoadFontFromImage(image, key, firstChar));
    }

    Font::Font(const std::string& fileType, const unsigned char* fileData, int dataSize, int fontSize, int *fontChars, int charsCount)
    {
        set(::LoadFontFromMemory(fileType.c_str(), fileData, dataSize, fontSize, fontChars, charsCount));
    }

    Font::~Font()
    {
        Unload();
    }

    void Font::Unload()
    {
        UnloadFont(*this);
    }

    Font& Font::operator=(const ::Font& font)
    {
        set(font);
        return *this;
    }

    /**
     * Draw text using font and additional parameters.
     */
    Font& Font::DrawText(const std::string& text, Vec2 position, float fontSize, float spacing, ::Color tint)
    {
        ::DrawTextEx(*this, text.c_str(), position,  fontSize,  spacing,  tint);
        return *this;
    }

    Font& Font::DrawText(const std::string& text, ::Rectangle rec, float fontSize, float spacing, bool wordWrap, ::Color tint)
    {
        ::DrawTextRec(*this, text.c_str(), rec,  fontSize,  spacing,  wordWrap,  tint);
        return *this;
    }

    /**
     * Draw text using font inside rectangle limits with support for text selection.
     */
    Font& Font::DrawText(const std::string& text, ::Rectangle rec, float fontSize, float spacing, bool wordWrap, ::Color tint, int selectStart, int selectLength, ::Color selectText, ::Color selectBack)
    {
        ::DrawTextRecEx(*this, text.c_str(), rec, fontSize, spacing, wordWrap, tint, selectStart,  selectLength, selectText, selectBack);
        return *this;
    }

    /**
     * Draw one character (codepoint)
     */
    Font& Font::DrawText(int codepoint, Vec2 position, float fontSize, ::Color tint)
    {
        ::DrawTextCodepoint(*this, codepoint, position, fontSize, tint);
        return *this;
    }

    /**
     * Measure string size for Font
     */
    Vec2 Font::MeasureText(const std::string& text, float fontSize, float spacing) const
    {
        Vector2 v = ::MeasureTextEx(*this, text.c_str(), fontSize, spacing);
        return Vec2(v.x, v.y);
    }

    /**
     * Get index position for a unicode character on font
     */
    int Font::GetGlyphIndex(int character) const
    {
        return ::GetGlyphIndex(*this, character);
    }

    /**
     * Create an image from text (custom sprite font)
     */
    ::Image Font::ImageText(const std::string& text, float fontSize, float spacing, ::Color tint) const 
    {
        return ::ImageTextEx(*this, text.c_str(), fontSize, spacing, tint);
    }

    void Font::set(const ::Font& font)
    {
        baseSize = font.baseSize;
        charsCount = font.charsCount;
        charsPadding = font.charsPadding;
        texture = font.texture;
        recs = font.recs;
        chars = font.chars;
    }
} // namespace ray