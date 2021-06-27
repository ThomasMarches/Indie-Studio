/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** OptionPauseScene.hpp
*/

#ifndef ECS_OPTIONPAUSESCENE_HPP
#define ECS_OPTIONPAUSESCENE_HPP

#include "Core/Scene.hpp"

class OptionPauseScene : public fox::Scene
{
    public:
        OptionPauseScene();
        explicit OptionPauseScene(const std::string& name);
        ~OptionPauseScene() override;

        void on_create(fox::Application& app) override;
        void on_enable(fox::Application& app) override;
        void on_destroy(fox::Application& app) override;
        void on_update(fox::Application& app) override;
        void on_disable(fox::Application& app) override;

    protected:
    private:
};


#endif//ECS_OPTIONPAUSESCENE_HPP
