/*
** EPITECH PROJECT, 2021
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** OptionScene
*/

#ifndef OPTIONSCENE_HPP_
#define OPTIONSCENE_HPP_

#include "Core/Scene.hpp"

class OptionScene  : public fox::Scene {
    public:
        OptionScene();
        explicit OptionScene(const std::string& name);
        ~OptionScene() override;

        void on_create(fox::Application& app) override;
        void on_enable(fox::Application& app) override;
        void on_destroy(fox::Application& app) override;
        void on_update(fox::Application& app) override;
        void on_disable(fox::Application& app) override;

    protected:
    private:
};

#endif /* !OPTIONSCENE_HPP_ */
