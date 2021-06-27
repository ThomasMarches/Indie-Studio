/*
** EPITECH PROJECT, 2021
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** HowToPlayScene
*/

#ifndef HOWTOPLAYSCENE_HPP_
#define HOWTOPLAYSCENE_HPP_

constexpr int MAX_HOW_TO_PLAY_INDEX = 7;

#include "Core/Scene.hpp"

class HowToPlayScene : public fox::Scene {
    public:
        HowToPlayScene();
        HowToPlayScene(const std::string& name);
        ~HowToPlayScene();

        virtual void on_create(fox::Application& app) override;
        virtual void on_enable(fox::Application& app) override;
        void on_destroy(fox::Application& app) override;
        void on_update(fox::Application& app) override;
        std::string get_how_to_play_image(bool choice);
        int get_how_to_play_text_index(bool choice);
        void on_disable(fox::Application& app) override;

    protected:
    private:
};

#endif /* !HOWTOPLAYSCENE_HPP_ */
