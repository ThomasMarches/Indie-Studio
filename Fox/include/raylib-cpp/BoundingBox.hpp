/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** BoundingBox.hpp
*/

#ifndef RAYLIB_BOUNDINGBOX_HPP_
#define RAYLIB_BOUNDINGBOX_HPP_

#include <string>
#include "raylib.hpp"
#include "raylib-cpp/Color.hpp"
#include "Utils/Vec3.hpp"
#include "Utils/Vec2.hpp"

namespace ray
{
    class BoundingBox : public ::BoundingBox {
    public:
        BoundingBox(const ::BoundingBox& box);
        BoundingBox(const ::Mesh& mesh);
        BoundingBox(Vec3 minMax);
        BoundingBox(Vec3 Min, Vec3 Max);
        BoundingBox& operator=(const ::BoundingBox& box);
        bool operator==(const BoundingBox& box) const;
        BoundingBox& Draw(::Color color = {255, 255, 255, 255});
        bool CheckCollision(const ::BoundingBox& box2) const;
        bool CheckCollision(Vec3 center, float radius) const;
        bool CheckCollision(const ::Ray& ray) const;
        void set(const ::BoundingBox& box);
    };
}  // namespace ray

#endif  // RAYLIB_BOUNDINGBOX_HPP_