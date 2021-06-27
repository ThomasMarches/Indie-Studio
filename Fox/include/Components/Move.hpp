/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Move.hpp
*/

#ifndef ECS_MOVE_HPP
#define ECS_MOVE_HPP


#include <Utils/Vec3.hpp>

class Move
{
public:
    explicit Move(float speed) : m_fSpeed(speed) {}
    Vec3 m_oVelocity;
    float m_fSpeed;
};


#endif //ECS_MOVE_HPP
