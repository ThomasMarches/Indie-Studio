/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** RayHitInfo.cpp
*/

#include "raylib-cpp/RayHitInfo.hpp"

namespace ray
{
    RayHitInfo::RayHitInfo(const ::RayHitInfo& ray)
    {
        set(ray);
    }

    RayHitInfo::RayHitInfo(bool Hit, float Distance, Vec3 Position, Vec3 Normal)
    {
        hit = Hit;
        distance = Distance;
        position = Position;
        normal = Normal;
    }

    /**
     * Get collision info between ray and mesh
     */
    RayHitInfo::RayHitInfo(const ::Ray& ray, const ::Mesh& mesh, const ::Matrix& transform)
    {
        set(::GetCollisionRayMesh(ray, mesh, transform));
    }

    /**
     * Get collision info between ray and model
     */
    RayHitInfo::RayHitInfo(const ::Ray& ray, const ::Model& model)
    {
        set(::GetCollisionRayModel(ray, model));
    }

    /**
     * Get collision info between ray and triangle
     */
    RayHitInfo::RayHitInfo(const ::Ray& ray, Vec3 p1, Vec3 p2, Vec3 p3)
    {
        set(::GetCollisionRayTriangle(ray, p1, p2, p3));
    }

    /**
     * Get collision info between ray and ground plane (Y-normal plane)
     */
    RayHitInfo::RayHitInfo(const ::Ray& ray, float groundHeight)
    {
        set(::GetCollisionRayGround(ray, groundHeight));
    }

    RayHitInfo& RayHitInfo::operator=(const ::RayHitInfo& ray)
    {
        set(ray);
        return *this;
    }

    void RayHitInfo::set(const ::RayHitInfo& ray)
    {
        hit = ray.hit;
        distance = ray.distance;
        position = ray.position;
        normal = ray.normal;
    }

} // namespace ray