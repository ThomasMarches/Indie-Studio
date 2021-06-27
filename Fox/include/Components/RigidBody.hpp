/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** RigidBody.hpp
*/

#ifndef ECS_RIGIDBODY_HPP
#define ECS_RIGIDBODY_HPP

#include "reactphysics3d/reactphysics3d.h"
#include <Core/Scene.hpp>
#include <Components/Transform.hpp>

namespace fox
{
    class RigidBody
    {
    public:

        /**
         * @brief Constructor
         * @param scene reference to the scene
         */
        RigidBody(fox::Scene& scene);

        /**
         * @brief Destructor
         */
        ~RigidBody();

        /**
         * @brief Get the rigidbody of the reactphysic3d library
         * @return the rigidbody of the reactphysic3d library
         */
        reactphysics3d::RigidBody* get_rb();

    private:
        reactphysics3d::RigidBody* m_rigidbody;
    };
}
#endif //ECS_RIGIDBODY_HPP
