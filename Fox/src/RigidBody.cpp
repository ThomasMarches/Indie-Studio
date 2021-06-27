/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** RigidBody.cpp
*/

#include <Components/Transform.hpp>
#include <reactphysics3d/decimal.h>
#include <reactphysics3d/components/RigidBodyComponents.h>
#include <reactphysics3d/collision/Collider.h>
#include "Components/RigidBody.hpp"

namespace fox
{
    RigidBody::RigidBody(fox::Scene& scene)
    {
        m_rigidbody = scene.get_world_physic().createRigidBody(Transform());
        assert(m_rigidbody);
    }

    RigidBody::~RigidBody()
    {
    }

    reactphysics3d::RigidBody *RigidBody::get_rb()
    {
        return m_rigidbody;
    }
}