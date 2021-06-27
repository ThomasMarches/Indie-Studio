/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** FireScript.hpp
*/

#ifndef FIRE_SCRIPT_HPP
#define FIRE_SCRIPT_HPP

#include "ScriptableBehaviour.hpp"

class FireScript : public ScriptableBehaviour
{
    public:
        FireScript(Vec3 position);
        virtual void on_create() override;
        virtual void on_update() override;
        virtual void on_destroy() override;
        Vec3 getPosition() const;
    private:
        Vec3 _position;
};
#endif //FIRE_SCRIPT_HPP
