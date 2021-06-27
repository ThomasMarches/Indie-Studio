/*
** EPITECH PROJECT, 2021
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** MenuScene
*/

#ifndef MENUSCENE_HPP_
#define MENUSCENE_HPP_

#include "Core/Scene.hpp"

class MenuScene : public fox::Scene {
    public:
        MenuScene();
        MenuScene(const std::string& name);
        ~MenuScene();

        virtual void on_create(fox::Application& app) override;
        virtual void on_enable(fox::Application& app) override;
        void on_destroy(fox::Application& app) override;
        void on_update(fox::Application& app) override;
        void on_disable(fox::Application& app) override;

    protected:
    private:
};

#endif /* !MENUSCENE_HPP_ */
