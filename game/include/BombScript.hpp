/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** BombScript.hpp
*/

#ifndef BOMB_SCRIPT_HPP
#define BOMB_SCRIPT_HPP

#include "ScriptableBehaviour.hpp"

class BombScript : public ScriptableBehaviour
{
public:
    const std::string playerName;
    BombScript(const std::string &player, int rangeUp);
    virtual void on_create() override;
    void createPowerUp(Vec3 position);
    virtual void on_update() override;
    virtual void on_destroy() override;
private:
    bool is_destroyed = false;
    int _rangeUp;
};

#endif //BOMB_SCRIPT_HPP
