/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Collider.hpp
*/

#ifndef ECS_COLLIDER_HPP
#define ECS_COLLIDER_HPP

#include "../common.hpp"

class NativeScript;

namespace fox
{
    class Collider
    {
    public:
        virtual ~Collider() {}
        NativeScript* m_pScript;
        EntityId entity;
    };
}

#endif //ECS_COLLIDER_HPP
