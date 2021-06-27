/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** TimerScript.hpp
*/

#ifndef ECS_TIMERSCRIPT_HPP
#define ECS_TIMERSCRIPT_HPP

#include "ScriptableBehaviour.hpp"

class TimerScript : public ScriptableBehaviour
{
    unsigned int minuts = 3;
    unsigned int seconds = 0;
    float time = 0;
public:
    virtual void on_create() override;
    virtual void on_update() override;
    virtual void on_destroy() override;
};


#endif //ECS_TIMERSCRIPT_HPP
