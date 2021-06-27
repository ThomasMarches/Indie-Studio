/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** FireScript.cpp
*/

#include "FireScript.hpp"
#include "Components.hpp"

FireScript::FireScript(Vec3 position) : _position(position) {}

Vec3 FireScript::getPosition() const
{
    return _position;
}

void FireScript::on_create()
{
    add_component<Animator>();
    add_component<ray::Model>("assets/bomb/fire.gltf");
    add_component<fox::Transform>(getPosition());
    get_component<Animator>()->add_anim("e")
        .loop(true)
        .signal(2, [this]{get_component<Animator>()->switch_to("exp");})
    .add<Vec3>()
            .apply(get_component<fox::Transform>()->scale)
            .then(0, Vec3(1, 1, 1))
            .then(1, Vec3(2, 1.3, 1.3))
            .then(2, Vec3(0.5, 0.5, 0.5));
    get_component<Animator>()->add_anim("exp")
        .signal(2, [this]{ destroy(); })
    .add<Vec3>()
            .apply(get_component<fox::Transform>()->scale)
            .then(0, Vec3(0.5, 0.5, 0.5))
            .then(1, Vec3(1, 1, 1))
            .then(2, Vec3(0.5, 0.5, 0.5));
}

void FireScript::on_update() {}

void FireScript::on_destroy() {}
