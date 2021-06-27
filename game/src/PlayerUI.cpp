/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** PlayerUI.cpp
*/

#include <Components.hpp>
#include <Components/Score.hpp>
#include "PlayerUI.hpp"
#include "raylib-cpp/Color.hpp"

PlayerUI::PlayerUI(const std::string& strName, int id, Vec3 position, bool player)
        : ui_position(position), m_strName(strName), player_number(id), isPlayer(player)
{
}

void PlayerUI::on_create()
{
    std::string filePath = "assets/game-ui/";
    Vec3 text_pos = ui_position;

    if (player_number > 1) {
        text_pos += Vec3(-40, 130, 0);
        filePath += get_app().get_player_manager().getPlayerColorAtIndex(player_number + 1) + "-ui-reversed.png";
    } else {
        text_pos += Vec3(80, 130, 0);
        filePath += get_app().get_player_manager().getPlayerColorAtIndex(player_number + 1) + "-ui.png";
    }
    player_ui = get_world().new_entity()
            .add<fox::Transform>(ui_position, Vec3(0.75, 0.75, 0))
            .add<fox::Image>(filePath);
    player_ui_text = get_world().new_entity()
            .add<fox::Transform>(Vec3(text_pos.x + ((200 - ray::Text::GetTextWidth(m_strName, 20)) / 2), text_pos.y, text_pos.z))
            .add<ray::Text>(m_strName, ray::Color(0, 191, 255));
    player_score_ui = get_world().new_entity()
            .add<fox::Transform>(Vec3(text_pos.x + ((200 - ray::Text::GetTextWidth("0", 20)) / 2), text_pos.y - 60, text_pos.z))
            .add<ray::Text>("0", ray::Color(0, 121, 241, 255));
}

void PlayerUI::on_update()
{
    Vec3 text_pos = ui_position;

    if (player_number > 1)
        text_pos += Vec3(-40, 130, 0);
    else
        text_pos += Vec3(80, 130, 0);

    if (isPlayer)
        player_score_ui.get<ray::Text>()->SetString(std::to_string(get_app().get_player_manager().getScore("player" + std::to_string(player_number))));
    else
        player_score_ui.get<ray::Text>()->SetString(std::to_string(get_app().get_player_manager().getScore("ia_" + std::to_string(player_number - (get_app().get_player_manager().getPlayerNames().size() - 1)))));
    player_score_ui.get<fox::Transform>()->set_pos(Vec3(text_pos.x + ((200 - ray::Text::GetTextWidth(player_score_ui.get<ray::Text>()->GetString(), 20)) / 2), text_pos.y - 60, text_pos.z));
}

void PlayerUI::on_destroy() {}