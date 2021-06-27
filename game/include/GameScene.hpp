/*
** EPITECH PROJECT, 2021
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** GameScene
*/

#ifndef GAMESCENE_HPP_
#define GAMESCENE_HPP_

#include "Core/Scene.hpp"
#include "Utils/Vec3.hpp"

class GameScene : public fox::Scene {
    public:
        GameScene();
        GameScene(const std::string& name);
        ~GameScene();

        virtual void on_create(fox::Application& app) override;
        virtual void on_enable(fox::Application& app) override;
        void on_destroy(fox::Application& app) override;
        void on_update(fox::Application& app) override;
        void on_disable(fox::Application& app) override;

        std::unordered_map<int, Vec3> IntToPlayerPosition;
        std::unordered_map<int, Vec3> IntToUIPosition;
    protected:
    private:
};

#endif /* !GAMESCENE_HPP_ */
