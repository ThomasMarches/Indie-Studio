/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** PlayerUI.hpp
*/

#ifndef ECS_PLAYERUI_HPP
#define ECS_PLAYERUI_HPP

#include "ScriptableBehaviour.hpp"

class PlayerUI : public ScriptableBehaviour
{
    Vec3 ui_position;
    fox::Entity player_score_ui;
    fox::Entity player_ui_text;
    fox::Entity player_ui;
    std::string m_strName;
    fox::Entity player_entity;
    int player_number;
    bool isPlayer;

public:
    PlayerUI(const std::string& strName, int id, Vec3 position, bool player);
    virtual void on_create() override;
    virtual void on_update() override;
    virtual void on_destroy() override;
};


#endif //ECS_PLAYERUI_HPP
