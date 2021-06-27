/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Cube.cpp
*/

#include "raylib-cpp/Cube.hpp"

namespace ray
{
    Cube::Cube() : m_oColor(ray::Color(230, 41, 55, 255)), m_fLength(1)
    {
    }

    void Cube::Draw(float x, float y, float z)
    {
        DrawCube(Vec3(x, y, z), m_oSize.x, m_oSize.y, m_fLength, m_oColor);
    }

    void Cube::Draw(const Vec3& pos, const Vec3& scale)
    {
        DrawCubeV(pos, scale, m_oColor);
    }

    Cube& Cube::SetSize(const Vec2& size)
    {
        m_oSize = size;
        return *this;
    }

    Cube& Cube::SetSize(float w, float h)
    {
        m_oSize.x = w;
        m_oSize.y = h;
        return *this;
    }

    Cube& Cube::SetLength(float l)
    {
        m_fLength = l;
        return *this;
    }

    Cube& Cube::SetColor(Color c)
    {
        m_oColor = c;
        return *this;
    }

    Color Cube::GetColor() const
    {
        return m_oColor;
    }

    float Cube::GetLength() const
    {
        return m_fLength;
    }

    Vec2 Cube::GetSize() const
    {
        return m_oSize;
    }

    bool Cube::operator==(const Cube& cube) const
    {
        return (GetSize() == cube.GetSize() && GetLength() == cube.GetLength() && GetColor() == cube.GetColor());
    }

} // namespace ray