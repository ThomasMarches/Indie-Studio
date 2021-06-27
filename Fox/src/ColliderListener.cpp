/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** ColliderListener.cpp
*/

#include <reactphysics3d/reactphysics3d.h>
#include <Components/Collider.hpp>
#include "ColliderListener.hpp"
#include "Components/NativeScript.hpp"


void ColliderListener::onContact(const reactphysics3d::CollisionCallback::CallbackData& callbackData)
{

    // For each contact pair
    for (std::uint32_t p = 0; p < callbackData.getNbContactPairs(); p++) {

        // Get the contact pair
        reactphysics3d::CollisionCallback::ContactPair contactPair = callbackData.getContactPair(p);

        fox::Collider* collider1 = static_cast<fox::Collider*>(contactPair.getCollider1()->getUserData());
        fox::Collider* collider2 = static_cast<fox::Collider*>(contactPair.getCollider2()->getUserData());
        if (contactPair.getEventType() == reactphysics3d::CollisionCallback::ContactPair::EventType::ContactStart
            && collider1->m_pScript)
            collider1->m_pScript->m_pInstance->on_collision_enter(*collider2);
        else if (contactPair.getEventType() == reactphysics3d::CollisionCallback::ContactPair::EventType::ContactStay
                 && collider1->m_pScript)
            collider1->m_pScript->m_pInstance->on_collision_stay(*collider2);
        else if (contactPair.getEventType() == reactphysics3d::CollisionCallback::ContactPair::EventType::ContactExit
                 && collider1->m_pScript)
            collider1->m_pScript->m_pInstance->on_collision_exit(*collider2);
    }
}