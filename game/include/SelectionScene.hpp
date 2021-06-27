/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** SelectionScene.hpp
*/

#ifndef SELECTIONSCENE_HPP_
#define SELECTIONSCENE_HPP_

#include "Core/Scene.hpp"

class SelectionScene  : public fox::Scene {
    public:
        SelectionScene();
        explicit SelectionScene(const std::string& name);
        ~SelectionScene() override;

        void on_create(fox::Application& app) override;
        void on_enable(fox::Application& app) override;
        void on_destroy(fox::Application& app) override;
        void on_update(fox::Application& app) override;
        void on_disable(fox::Application &app) override;

    protected:
    private:
};

#endif /* !SELECTIONSCENE_HPP_ */
