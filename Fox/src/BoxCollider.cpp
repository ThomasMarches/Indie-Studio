/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** BoxCollider.cpp
*/

#include <reactphysics3d/reactphysics3d.h>
#include "Components/BoxCollider.hpp"
#include "Core/Scene.hpp"
#include "Components/RigidBody.hpp"

BoxCollider::BoxCollider(fox::Scene &scene, Vec3 scale) : fox::Collider()
{
    shape = scene.get_world_common().createBoxShape(scale);
    assert(shape);
}

BoxCollider::~BoxCollider()
{
}

Vec3 BoxCollider::getHalfExtents() const
{
    return Vec3(shape->getHalfExtents().x, shape->getHalfExtents().y, shape->getHalfExtents().z);
}

void BoxCollider::setHalfExtents(const Vec3 &halfExtents)
{
    shape->setHalfExtents(halfExtents);
}

float BoxCollider::getVolume() const
{
    return shape->getVolume();
}

Vec3 BoxCollider::getCentroid() const
{
    return Vec3(shape->getCentroid().x, shape->getCentroid().y, shape->getCentroid().z);
}

reactphysics3d::BoxShape *BoxCollider::getReactShape() const
{
    return shape;
}

void BoxCollider::set_collider(reactphysics3d::Collider* c)
{
    collider = c;
}

reactphysics3d::Collider *BoxCollider::get_collider() const
{
    return collider;
}
