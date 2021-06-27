/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Ray.hpp
*/

#ifndef RAYLIB_RAY_HPP_
#define RAYLIB_RAY_HPP_

#include <string>
#include "raylib.hpp"
#include "raylib-cpp/Color.hpp"
#include "Utils/Vec3.hpp"
#include "Utils/Vec2.hpp"

namespace ray
{
    class Ray : public ::Ray {
    public:
        Ray(const ::Ray& ray);
        Ray(Vec3 Position, Vec3 Direction);
        Ray(Vec2 mousePosition, ::Camera camera);
        Ray& operator=(const ::Ray& ray);
        Ray& Draw(::Color color);
        bool CheckCollisionSphere(Vec3 center, float radius) const;
        bool CheckCollisionSphere(Vec3 center, float radius, Vec3 *collisionPoint) const;
        bool CheckCollision(const ::BoundingBox& box) const;
        RayHitInfo GetCollision(const ::Model& model) const;
        RayHitInfo GetCollisionTriangle(Vec3 p1, Vec3 p2, Vec3 p3) const;
        RayHitInfo GetCollisionGround(float groundHeight) const;
        void set(const ::Ray& ray);
    };
}  // namespace ray

#endif  // RAYLIB_RAY_HPP_