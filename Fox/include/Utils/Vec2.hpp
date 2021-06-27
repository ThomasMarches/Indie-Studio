/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Vec2.hpp
*/

#ifndef FOX_VEC2_HPP_
#define FOX_VEC2_HPP_

#include <math.h>
#include "raylib.hpp"
#include "Vec3.hpp"

class Vec2 : public ::Vector2
{
public:
    Vec2() : ::Vector2{0, 0} {}
    Vec2(float x, float y) : ::Vector2{x, y} {}

    /**
     * @brief Set the X and Y value
     * @param x_ the new X value
     * @param y_ the new Y value
     */
    void set(float x_, float y_)
    {
        x = x_;
        y = y_;
    }

    operator ::Vector3() const
    {
        return ::Vector3{x, y, 0};
    }

    operator Vec3() const
    {
        return Vec3(x, y, 0);
    }

    Vec2 operator -() { return Vec2(-x, -y); }

    void operator += (const Vec2& v)
    {
        x += v.x;
        y += v.y;
    }

    void operator -= (const Vec2& v)
    {
        x -= v.x;
        y -= v.y;
    }

    void operator *= (float a)
    {
        x *= a;
        y *= a;
    }

    /**
     * @brief Get the length
     * @return the length
     */
    float Length() const
    {
        return sqrtf(x * x + y * y);
    }
};

#endif