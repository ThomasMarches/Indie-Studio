/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** EndScene.hpp
*/

#ifndef ENDSCENE_HPP_
#define ENDSCENE_HPP_

#include "Core/Scene.hpp"

class EndScene : public fox::Scene
{
    public:
        EndScene();
        EndScene(const std::string& name);
        ~EndScene();

        virtual void on_create(fox::Application& app) override;
        virtual void on_enable(fox::Application& app) override;
        void on_destroy(fox::Application& app) override;
        void on_update(fox::Application& app) override;
        void on_disable(fox::Application &app) override;
        void createPodium(fox::Application &app);
        void createOverallScoreboard(fox::Application &app);
        void updateOverallScoreboard(fox::Application &app);
        int getScoreAtIndex(int index);
        const std::string &getNameAtIndex(int index);
    protected:
    private:
        static std::vector<Vec3> PodiumVec3;
        std::unordered_map<int, int> v_ScoreAim;
        std::vector<std::string> v_Names;
        int overallScoreboardHeight;
};

#endif /* !ENDSCENE_HPP_ */