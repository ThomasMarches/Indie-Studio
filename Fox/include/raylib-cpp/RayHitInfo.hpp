/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** RayHitInfo.hpp
*/

#ifndef RAYLIB_RAYHITINFO_HPP_
#define RAYLIB_RAYHITINFO_HPP_

#include <string>
#include "raylib.hpp"
#include "raylib-cpp/Color.hpp"
#include "Utils/Vec3.hpp"
#include "Utils/Vec2.hpp"

namespace ray
{
    class RayHitInfo : public ::RayHitInfo {
    public:
        RayHitInfo(const ::RayHitInfo& ray);
        RayHitInfo(bool Hit, float Distance, Vec3 Position, Vec3 Normal);
        RayHitInfo(const ::Ray& ray, const ::Mesh& mesh, const ::Matrix& transform);
        RayHitInfo(const ::Ray& ray, const ::Model& model);
        RayHitInfo(const ::Ray& ray, Vec3 p1, Vec3 p2, Vec3 p3);
        RayHitInfo(const ::Ray& ray, float groundHeight);
        RayHitInfo& operator=(const ::RayHitInfo& ray);
        void set(const ::RayHitInfo& ray);
    };
}  // namespace ray

#endif  // RAYLIB_RAYHITINFO_HPP_