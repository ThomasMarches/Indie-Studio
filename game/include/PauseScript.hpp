/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** PauseScript.hpp
*/

#ifndef PAUSE_SCRIPT_HPP
#define PAUSE_SCRIPT_HPP

#include <vector>
#include "ScriptableBehaviour.hpp"

class PauseScript : public ScriptableBehaviour
{
    std::vector<EntityId> m_vEntities;
public:
    PauseScript(bool& bIsPaused);
    virtual void on_create() override;
    virtual void on_update() override;
    virtual void on_destroy() override;

    bool& m_bIsPaused;
};
#endif //BOMB_SCRIPT_HPP
