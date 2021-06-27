/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** MapScript.hpp
*/

#ifndef MAP_SCRIPT_HPP
#define MAP_SCRIPT_HPP

#include "ScriptableBehaviour.hpp"
#include "MapController.hpp"

class MapScript : public ScriptableBehaviour
{
    MapController *_controller;

public:
    virtual void on_create() override;
    virtual void on_update() override;
    virtual void on_destroy() override;
};
#endif //MAP_SCRIPT_HPP
