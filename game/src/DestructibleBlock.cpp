/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** DestructibleBlock.cpp
*/

#include <Components.hpp>
#include "DestructibleBlock.hpp"
#include "Components/RigidBody.hpp"
#include "Components/BoxCollider.hpp"

DestructibleBlock::DestructibleBlock(fox::Scene* s, int width, int height)
{
    map_width = width;
    map_height = height;
    scene = s;
}

void DestructibleBlock::on_create()
{
    add_component<ray::Model>("assets/destructible_block/wood.gltf");
    add_component<fox::Health>();
    add_component<fox::RigidBody>(*scene);
    add_component<BoxCollider>(*scene, Vec3(1.5, 1.5, 1.5));
    add_component<fox::Transform>(Vec3(float(map_width - 8), 1, float(map_height - 6)), Vec3(0.5, 0.5, 0.5));
    get_component<fox::RigidBody>()->get_rb()->setType(reactphysics3d::BodyType::STATIC);
    get_component<fox::Health>()->subscribe_died([&]{ destroy(); });
}