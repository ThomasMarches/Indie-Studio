/*
** EPITECH PROJECT, 2021
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** SplashScreenScene
*/


#ifndef SPLASHSCREENSCENE_HPP_
#define SPLASHSCREENSCENE_HPP_

#include "Core/Scene.hpp"

class SplashScreenScene : public fox::Scene
{
    public:
        SplashScreenScene();
        SplashScreenScene(const std::string& name);
        ~SplashScreenScene();

        virtual void on_create(fox::Application& app) override;
        virtual void on_enable(fox::Application& app) override;
        void on_destroy(fox::Application& app) override;
        void on_update(fox::Application& app) override;
        void on_disable(fox::Application &app) override;

    protected:
    private:
};

#endif /* !SPLASHSCREENSCENE_HPP_ */
