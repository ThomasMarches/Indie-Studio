/*
** EPITECH PROJECT, 2021
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** AI
*/

#ifndef ECS_AISCRIPT_HPP
    #define ECS_AISCRIPT_HPP

    #include <iostream>
    #include <vector>
    #include <Components/Score.hpp>
    #include "Components/Move.hpp"
    #include "ScriptableBehaviour.hpp"
    #include "MapController.hpp"

    #define WIDTH_MAP 15
    #define HEIGHT_MAP 13

    class AIScript : public ScriptableBehaviour {
        private:
            MapController *_controller;
            std::string _skinFilepath;
            Move *_move;
            int _x_bot;
            int _y_bot;
            std::vector<int> _path;
            std::vector<std::vector<int> > _map;
            float _timer;
            float _go_away;

            float _timer_respawn;

    public:
            virtual void on_create() override;
            virtual void on_update() override;
            AIScript(int x, int y, const std::string &);
            std::vector<std::vector<int> > get_map();
            void move_bot_safe();
            void set_map();
            int find_safe_path(int, int);
            int is_danger();
            int get_x_bot();
            int get_y_bot();
            void set_x_bot(int);
            void set_y_bot(int);
            void set_new_goal();
            void set_goal();
            void drop_bomb();
            virtual void on_destroy() override {}
    };

#endif
