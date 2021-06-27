/*
** EPITECH PROJECT, 2021
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** MapController
*/

#ifndef MAPCONTROLLER_HPP
    #define MAPCONTROLLER_HPP

    #include <vector>
    #include "ScriptableBehaviour.hpp"

    class MapController : public ScriptableBehaviour
            {
        private:
            std::vector<EntityId> bombs;
            std::vector<EntityId> blocks;
            std::vector<std::vector<int>> grid;
            int width;
            int heigth;
            float cell_size;
            Vec3 origin = Vec3(7, 0, 6);
            bool is_generate = false;
        public:
            std::vector<EntityId> get_bombs() const;
            std::vector<EntityId> get_blocks() const;
            void add_bomb(EntityId);
            void add_block(EntityId);
            void remove_bomb(EntityId);
            void remove_block(EntityId);

            Vec2 find_grid_pos_from_id(EntityId);

            void set_cell_size(float size);
            void set_heigth(int size);
            void set_width(int size);
            void set_origin(const Vec3& value);
            Vec3 get_world_pos(int x, int y);
            const std::vector<std::vector<int>>& get_grid() const;

            void generate();
    };

#endif