/*
** EPITECH PROJECT, 2021
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** MapController
*/

#include <Components/Transform.hpp>
#include "MapController.hpp"

std::vector<EntityId> MapController::get_bombs() const
{
    return this->bombs;
}

std::vector<EntityId> MapController::get_blocks() const
{
    return this->blocks;
}

void MapController::add_bomb(EntityId var)
{
    if (is_generate) {
        Vec2 p = find_grid_pos_from_id(var);
        if (p.x == -1 && p.y == -1)
            return;
        grid[p.y][p.x] = 1;
    } else
        this->bombs.push_back(var);
}

void MapController::add_block(EntityId var)
{
    if (is_generate) {
        Vec2 p = find_grid_pos_from_id(var);
        if (p.x == -1 && p.y == -1)
            return;
        grid[p.y][p.x] = 2;
    } else
        this->blocks.push_back(var);
}

void MapController::remove_bomb(EntityId var)
{
    Vec2 p = find_grid_pos_from_id(var);
    if (p.x == -1 && p.y == -1)
        return;
    grid[p.y][p.x] = 0;
}

void MapController::remove_block(EntityId var)
{
    Vec2 p = find_grid_pos_from_id(var);
    if (p.x == -1 && p.y == -1)
        return;
    grid[p.y][p.x] = 0;
}

Vec2 MapController::find_grid_pos_from_id(EntityId id)
{
    fox::Transform& trans = get_world().get_component<fox::Transform>(id).value();
    Vec3 position = Vec3(static_cast<int>(trans.position.x + 8), 0, static_cast<int>(trans.position.z + 6));
    for (int i = 0; i < width; i++)
        for (int j = 0; j < heigth; j++)
            if (position.x == i && position.z == j)
                return Vec2(i, j);
    return Vec2(-1, -1);
}

void MapController::set_cell_size(float size)
{
    cell_size = size;
}

void MapController::set_heigth(int size)
{
    heigth = size + 5;
}

void MapController::set_width(int size)
{
    width = size + 5;
}

void MapController::set_origin(const Vec3& value)
{
    origin = value;
}

Vec3 MapController::get_world_pos(int x, int y)
{
    return Vec3(x, 0, y) * cell_size;
}

void MapController::generate()
{
    grid.resize(width);
    for (int i = 0; i < width; i++)
        grid[i].resize(heigth);
    for (int i = 0; i < width; i++)
        for (int j = 0; j < heigth; j++) {
            grid[i][j] = 0;
        }
    is_generate = true;
    for (auto it : bombs)
        add_bomb(it);
    for (auto it : blocks)
        add_block(it);
    bombs.clear();
    blocks.clear();
}

const std::vector<std::vector<int>> &MapController::get_grid() const
{
    return grid;
}
