/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** BoundingBox.cpp
*/

#include "raylib-cpp/BoundingBox.hpp"

namespace ray
{
    BoundingBox::BoundingBox(const ::BoundingBox& box)
    {
        set(box);
    }

    /**
     * Compute mesh bounding box limits
     */
    BoundingBox::BoundingBox(const ::Mesh& mesh)
    {
        set(::MeshBoundingBox(mesh));
    }

    BoundingBox::BoundingBox(Vec3 minMax)
    {
        min = minMax;
        max = minMax;
    }

    BoundingBox::BoundingBox(Vec3 Min, Vec3 Max)
    {
        min = Min;
        max = Max;
    }

    BoundingBox& BoundingBox::operator=(const ::BoundingBox& box)
    {
        set(box);
        return *this;
    }


    bool BoundingBox::operator==(const BoundingBox& box) const
    {
        return (max.x == box.max.x && max.y == box.max.y &&
        max.z == box.max.z &&
        min.x == box.min.x &&
        min.y == box.min.y &&
        min.z == box.min.z);
    }

    /**
     * Draw a bounding box with wires
     */
    BoundingBox& BoundingBox::Draw(::Color color)
    {
        DrawBoundingBox(*this, color);
        return *this;
    }

    /**
     * Detect collision between two boxes
     */
    bool BoundingBox::CheckCollision(const ::BoundingBox& box2) const
    {
        return CheckCollisionBoxes(*this, box2);
    }

    /**
     * Detect collision between box and sphere
     */
    bool BoundingBox::CheckCollision(Vec3 center, float radius) const
    {
        return CheckCollisionBoxSphere(*this, center, radius);
    }

    /**
     * Detect collision between ray and bounding box
     */
    bool BoundingBox::CheckCollision(const ::Ray& ray) const
    {
        return CheckCollisionRayBox(ray, *this);
    }

    void BoundingBox::set(const ::BoundingBox& box)
    {
        min = box.min;
        max = box.max;
    }

} // namespace ray