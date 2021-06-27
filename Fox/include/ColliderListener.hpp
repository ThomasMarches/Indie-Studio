/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** ColliderListener.hpp
*/

#ifndef ECS_COLLIDERLISTENER_HPP
#define ECS_COLLIDERLISTENER_HPP


#include "reactphysics3d/engine/EventListener.h"

class ColliderListener : public reactphysics3d::EventListener {

    // Override the onContact() method
    void onContact(const CollisionCallback::CallbackData& callbackData) override;
};


#endif //ECS_COLLIDERLISTENER_HPP
