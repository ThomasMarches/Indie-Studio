/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Ray.cpp
*/

#include "raylib-cpp/Ray.hpp"

namespace ray
{
    Ray::Ray(const ::Ray& ray)
    {
        set(ray);
    }

    Ray::Ray(Vec3 Position, Vec3 Direction)
    {
        position = Position;
        direction = Direction;
    }

    Ray::Ray(Vec2 mousePosition, ::Camera camera)
    {
        set(::GetMouseRay(mousePosition, camera));
    }

    Ray& Ray::operator=(const ::Ray& ray)
    {
        set(ray);
        return *this;
    }

    /**
     * Draw a ray line
     */
    Ray& Ray::Draw(::Color color)
    {
        DrawRay(*this, color);
        return *this;
    }

    /**
     * Detect collision between ray and sphere
     */
    bool Ray::CheckCollisionSphere(Vec3 center, float radius) const
    {
        return CheckCollisionRaySphere(*this, center, radius);
    }

    /**
     * Detect collision between ray and sphere, returns collision point
     */
    bool Ray::CheckCollisionSphere(Vec3 center, float radius, Vec3 *collisionPoint) const
    {
        return CheckCollisionRaySphereEx(*this, center, radius, collisionPoint);
    }

    /**
     * Detect collision between ray and box
     */
    bool Ray::CheckCollision(const ::BoundingBox& box) const
    {
        return CheckCollisionRayBox(*this, box);
    }

    /**
     * Get collision info between ray and model
     */
    RayHitInfo Ray::GetCollision(const ::Model& model) const
    {
        return GetCollisionRayModel(*this, model);
    }

    /**
     * Get collision info between ray and triangle
     */
    RayHitInfo Ray::GetCollisionTriangle(Vec3 p1, Vec3 p2, Vec3 p3) const
    {
        return GetCollisionRayTriangle(*this, p1, p2, p3);
    }

    /**
     * Get collision info between ray and ground plane (Y-normal plane)
     */
    RayHitInfo Ray::GetCollisionGround(float groundHeight) const
    {
        return GetCollisionRayGround(*this, groundHeight);
    }

    void Ray::set(const ::Ray& ray)
    {
        position = ray.position;
        direction = ray.direction;
    }

} // namespace ray