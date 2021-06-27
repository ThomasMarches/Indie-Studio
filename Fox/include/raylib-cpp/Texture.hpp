/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Texture.hpp
*/

#ifndef RAYLIB_TEXTURE_HPP_
#define RAYLIB_TEXTURE_HPP_

#include <string>
#include "raylib.hpp"
#include "raylib-cpp/Color.hpp"
#include "Utils/Vec3.hpp"
#include "Utils/Vec2.hpp"

namespace ray {
    class Texture : public ::Texture
    {
    private:
        Color m_oColor;
    public:
        Texture(const ::Texture& texture);
        Texture(const ::Image& image);
        Texture(int width, int height, const std::string& title);
        Texture(const std::string& fileName);
        Texture(const ::Image& image, int layout);
        ~Texture();

        void Unload();
        Vec2 GetSize() const;
        void LoadFromImage(const ::Image& image);
        void Load(const std::string &filepath);
        void LoadCubemap(const ::Image& image, int layoutType);
        Texture &Update(const void *pixels);
        Texture &SetFilter(int filterMode);
        Texture &SetWrap(int wrapMode);
        Texture& UpdateRec(::Rectangle rec, const void *pixels);
        ::Image GetData() const;
        void set(const ::Texture& texture);

        void SetColor(Color color);
        Color GetColor() const;
        Color& GetColor();

        Texture &Draw();
        Texture& Draw(int posX, int posY);
        Texture& Draw(Vec2 position);
        Texture& Draw(int posX, int posY, Color tint);
        Texture& Draw(Vec2 position, Color tint);
        Texture& Draw(Vec2 position, float rotation, float scale = 1.0f,
            Color tint = {255, 255, 255, 255});
        Texture& Draw(::Rectangle sourceRec, Vec2 position = {0, 0},
            Color tint = {255, 255, 255, 255});
        Texture& Draw(Vec2 tiling, Vec2 offset, ::Rectangle quad,
            Color tint = {255, 255, 255, 255});
        Texture& Draw(::Rectangle sourceRec, ::Rectangle destRec,
            Vec2 origin = {0, 0}, float rotation = 0,
            Color tint = {255, 255, 255, 255});
        Texture& Draw(Vec3 position, float width, float height, float length,
            Color tint = {255, 255, 255, 255});
        Texture& DrawTiled(::Rectangle sourceRec, ::Rectangle destRec,
            Vec2 origin = {0, 0}, float rotation = 0, float scale = 1,
            Color tint = {255, 255, 255, 255});
        Texture& DrawPoly(Vec2 center, Vec2 *points,
            Vec2 *texcoords, int pointsCount,
            Color tint = {255, 255, 255, 255});

    };

// Create the Texture aliases.
typedef Texture Texture2D;
typedef Texture TextureCubemap;

}  // namespace ray

#endif  // RAYLIB_TEXTURE_HPP_