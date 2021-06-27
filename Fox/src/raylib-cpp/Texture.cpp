/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Texture.cpp
*/

#include "raylib-cpp/Texture.hpp"

namespace ray
{

    Texture::Texture(const ::Texture& texture)
    {
        set(texture);
        m_oColor = ray::Color(255, 255, 255, 255);
    }

    Texture::Texture(const ::Image& image)
    {
        set(::LoadTextureFromImage(image));
        m_oColor = ray::Color(255, 255, 255, 255);
    }

    Texture::Texture(const std::string& fileName)
    {
        Load(fileName);
        m_oColor = ray::Color(255, 255, 255, 255);
    }

    Texture::Texture(const ::Image& image, int layout)
    {
        LoadCubemap(image, layout);
        m_oColor = ray::Color(255, 255, 255, 255);
    }

    Texture::~Texture()
    {
        Unload();
    }

    void Texture::LoadCubemap(const ::Image& image, int layoutType)
    {
        set(::LoadTextureCubemap(image, layoutType));
    }

    void Texture::Unload()
    {
        ::UnloadTexture(*this);
    }

    void Texture::set(const ::Texture &texture)
    {
        id = texture.id;
        width = texture.width;
        height = texture.height;
        mipmaps = texture.mipmaps;
        format = texture.format;
    }

    Vec2 Texture::GetSize() const
    {
        return {static_cast<float>(width), static_cast<float>(height)};
    }

    void Texture::LoadFromImage(const ::Image& image)
    {
        set(::LoadTextureFromImage(image));
    }

    void Texture::Load(const std::string &filepath)
    {
        set(::LoadTexture(filepath.c_str()));
    }

    Texture &Texture::Update(const void *pixels)
    {
        ::UpdateTexture(*this, pixels);
        return *this;
    }

    Texture& Texture::SetFilter(int filterMode)
    {
        ::SetTextureFilter(*this, filterMode);
        return *this;
    }

    Texture& Texture::SetWrap(int wrapMode)
    {
        ::SetTextureWrap(*this, wrapMode);
        return *this;
    }

    Texture& Texture::UpdateRec(::Rectangle rec, const void *pixels)
    {
        UpdateTextureRec(*this, rec, pixels);
        return *this;
    }

    ::Image Texture::GetData() const {
        return ::GetTextureData(*this);
    }

    void Texture::SetColor(Color color)
    {
        m_oColor = color;
    }

    Color Texture::GetColor() const
    {
        return m_oColor;
    }

    Color& Texture::GetColor()
    {
        return m_oColor;
    }

    Texture &Texture::Draw()
    {
        return Draw(0, 0);
    }

    Texture& Texture::Draw(int posX, int posY)
    {
        ::DrawTexture(*this, posX, posY, m_oColor);
        return *this;
    }

    Texture& Texture::Draw(Vec2 position)
    {
        ::DrawTextureV(*this, position, m_oColor);
        return *this;
    }

    Texture& Texture::Draw(int posX, int posY, Color tint)
    {
        ::DrawTexture(*this, posX, posY, tint);
        return *this;
    }

    Texture& Texture::Draw(Vec2 position, Color tint)
    {
        ::DrawTextureV(*this, position, tint);
        return *this;
    }

    Texture& Texture::Draw(Vec2 position, float rotation, float scale, Color tint)
    {
        ::DrawTextureEx(*this, position, rotation, scale, tint);
        return *this;
    }

    Texture& Texture::Draw(::Rectangle sourceRec, Vec2 position, Color tint)
    {
        ::DrawTextureRec(*this, sourceRec, position, tint);
        return *this;
    }

    Texture& Texture::Draw(Vec2 tiling, Vec2 offset, ::Rectangle quad,
        Color tint)
    {
        ::DrawTextureQuad(*this, tiling, offset, quad, tint);
        return *this;
    }

    Texture& Texture::Draw(::Rectangle sourceRec, ::Rectangle destRec, Vec2 origin,
        float rotation, Color tint)
    {
        ::DrawTexturePro(*this, sourceRec, destRec, origin, rotation, m_oColor);
        return *this;
    }

    Texture& Texture::Draw(Vec3 position, float width, float height,
        float length, Color tint)
    {
        ::DrawCubeTexture(*this, position, width, height, length, tint);
        return *this;
    }

    Texture& Texture::DrawTiled(::Rectangle sourceRec, ::Rectangle destRec,
        Vec2 origin, float rotation, float scale, Color tint)
    {
        ::DrawTextureTiled(*this, sourceRec, destRec, origin, rotation, scale, tint);
        return *this;
    }

    Texture& Texture::DrawPoly(Vec2 center, Vec2 *points,
        Vec2 *texcoords, int pointsCount, Color tint)
    {
        ::DrawTexturePoly(*this, center, points, texcoords, pointsCount, tint);
        return *this;
    }

} // namespace ray