/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** TimerScript.cpp
*/

#include <Components.hpp>
#include "TimerScript.hpp"

void TimerScript::on_create()
{
    add_component<ray::Text>("03:00", ray::Color(255, 109, 194, 255));
    add_component<fox::Transform>(Vec3((1280 - ray::Text::GetTextWidth("03:00", 40)) / 2, 20, 0));
    get_component<ray::Text>()->SetFontSize(40);
    time = 0;
}

void TimerScript::on_update()
{
    time += Time::delta_time / 3;
    if (time >= 1) {
        time = 0;

        std::string timerString;

        if (minuts == 0 && seconds == 0)
            get_app().switch_to("End");
        else if (minuts > 0 && seconds == 0) {
            seconds = 59;
            minuts--;
        } else if (minuts >= 0 && seconds > 0)
            seconds--;
        if (seconds < 10)
            timerString = "0" + std::to_string(minuts) + ":0" + std::to_string(seconds);
        else
            timerString = "0" + std::to_string(minuts) + ":" + std::to_string(seconds);
        get_component<ray::Text>()->SetString(timerString);
    }
}

void TimerScript::on_destroy() {}
