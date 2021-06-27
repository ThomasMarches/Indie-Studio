/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** DestructibleBlock.hpp
*/

#ifndef ECS_DESTRUCTIBLEBLOCK_HPP
#define ECS_DESTRUCTIBLEBLOCK_HPP

#include "ScriptableBehaviour.hpp"

class DestructibleBlock : public ScriptableBehaviour
{

public:
    DestructibleBlock(fox::Scene* scene, int width, int height);
    virtual void on_create() override;

private:
    int map_width = 0;
    int map_height = 0;
    fox::Scene* scene = nullptr;
};


#endif //ECS_DESTRUCTIBLEBLOCK_HPP
