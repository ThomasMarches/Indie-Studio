/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Cube.hpp
*/

#ifndef RAYLIB_CUBE_HPP_
#define RAYLIB_CUBE_HPP_

#include <string>
#include "raylib.hpp"
#include "raylib-cpp/Color.hpp"
#include "Utils/Vec3.hpp"
#include "Utils/Vec2.hpp"

namespace ray
{
    class Cube
    {
    public:
        Cube();
        void Draw(float x, float y, float z);
        void Draw(const Vec3& pos, const Vec3& scale);
        Cube& SetSize(const Vec2& size);
        Cube& SetSize(float w, float h);
        Cube& SetLength(float l);
        Cube& SetColor(Color c);
        Color GetColor() const;
        float GetLength() const;
        Vec2 GetSize() const;
        bool operator==(const Cube& cube) const;

    private:
        Vec2 m_oSize;
        float m_fLength;
        Color m_oColor;
    };
}  // namespace ray

#endif  // RAYLIB_CUBE_HPP_