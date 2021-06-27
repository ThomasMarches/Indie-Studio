/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** BoxCollider.hpp
*/

#ifndef ECS_BOXCOLLIDER_HPP
#define ECS_BOXCOLLIDER_HPP

#include <Utils/Vec3.hpp>
#include "Collider.hpp"

namespace fox
{
    class Scene;
    class RigidBody;
}

namespace reactphysics3d
{
    class BoxShape;
    class Collider;
}

class BoxCollider : public fox::Collider
{
public:
    BoxCollider(fox::Scene& scene, Vec3 scale = Vec3(1, 1, 1));
    ~BoxCollider();

    /// Return the half-extents of the box
    Vec3 getHalfExtents() const;

    /// Set the half-extents of the box
    void setHalfExtents(const Vec3& halfExtents);

    /// Compute and return the volume of the collision shape
    float getVolume() const;

    /// Return the centroid of the polyhedron
    Vec3 getCentroid() const;
    reactphysics3d::BoxShape* getReactShape() const;
    void set_collider(reactphysics3d::Collider*);
    reactphysics3d::Collider* get_collider() const;

private:
    reactphysics3d::BoxShape* shape;
    reactphysics3d::Collider* collider = nullptr;
};


#endif //ECS_BOXCOLLIDER_HPP
