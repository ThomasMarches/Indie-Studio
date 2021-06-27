/*
** EPITECH PROJECT, 2021
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** BombScript
*/

#include <fstream>
#include <Components/RigidBody.hpp>
#include <DestructibleBlock.hpp>
#include "MapScript.hpp"
#include "Components.hpp"
#include "FileSystem.hpp"

void MapScript::on_create()
{
    fox::Entity map_controller;
    if (!get_world().get_entity("map_controller", map_controller))
        assert(false);
    _controller = map_controller.get<NativeScript>()->get<MapController>();
    assert(_controller);

    std::string line;
    auto map_width = 0;
    auto map_height = 0;
    std::string all = " 01";
    std::string secure = " 1111";
    std::string str = "";

    srand(time(0));
    for(size_t i = 0; i < 195; i++)
    {
        if ((i % 15) == 0 && i != 0) {
            str+='\n';
        }
        if (i < 15 || (i % 15) == 0 || (i % 15) == 14 || i > 180) {
            str+='2';
        } else if ((i >= 16 && i <= 18) || (i >= 26 && i <= 29)
            || i == 31 || i == 43 || i == 46 || i == 58
            || i == 136 || i == 148 || i == 151 || i == 163
            || (i >= 166 && i <= 168) || (i >= 176 && i <= 179)) {
            str+=' ';
        } else if (i >= 33 && i <= 44 && (str[i-15] == '0' || str[i-13] == '0')) {
            size_t pos = rand() % 5;
            str+= secure[pos];
        } else if (i >= 48 && i <= 59 && (str[i-14] == '0' || str[i-12] == '0')) {
            size_t pos = rand() % 5;
            str+= secure[pos];
        } else if (i >= 61 && i <= 73 && (str[i-13] == '0' || str[i-11] == '0')) {
            size_t pos = rand() % 5;
            str+= secure[pos];
        } else if (i >= 76 && i <= 88 && (str[i-12] == '0' || str[i-10] == '0')) {
            size_t pos = rand() % 5;
            str+= secure[pos];
        } else if (i >= 91 && i <= 103 && (str[i-11] == '0' || str[i-9] == '0')) {
            size_t pos = rand() % 5;
            str+= secure[pos];
        } else if (i >= 106 && i <= 118 && (str[i-10] == '0' || str[i-8] == '0')) {
            size_t pos = rand() % 5;
            str+= secure[pos];
        } else if (i >= 121 && i <= 133 && (str[i-9] == '0' || str[i-7] == '0')) {
            size_t pos = rand() % 5;
            str+= secure[pos];
        } else if (i >= 136 && i <= 148 && (str[i-8] == '0' || str[i-6] == '0')) {
            size_t pos = rand() % 5;
            str+= secure[pos];
        } else if (i >= 151 && i <= 163 && (str[i-7] == '0' || str[i-5] == '0')) {
            size_t pos = rand() % 5;
            str+= secure[pos];
        } else if (i >= 166 && i <= 178 && (str[i-6] == '0' || str[i-4] == '0')) {
            size_t pos = rand() % 5;
            str+= secure[pos];
        } else {
            size_t pos = rand() % 3;
            str+=all[pos];
        }
    }
    str+='\n';

    fox::file::WriteFile("game/config/map2.nts", str);
    std::fstream infile("game/config/map2.nts");

    _controller->set_cell_size(0.5f);
    while (std::getline(infile, line)) {
        map_width = 0;
        for (char& c :line) {
            map_width++;
            if (c == '0') {
                auto e = get_world().new_entity("", "indestructible_block", true)
                        .add<ray::Model>("assets/indestructible_block/rock.gltf")
                        .add<fox::RigidBody>(get_scene())
                        .add<BoxCollider>(get_scene(), Vec3(1.5, 1.5, 1.5))
                        .add<fox::Transform>(Vec3(float(map_width - 8), 1, float(map_height - 6)), Vec3(0.5, 0.5, 0.5));
                e.get<fox::RigidBody>()->get_rb()->setType(reactphysics3d::BodyType::STATIC);
            } else if (c == '1') {
                get_world().new_entity("", "destructible_block", true)
                        .add<NativeScript>()
                        .get<NativeScript>()->bind<DestructibleBlock>(&get_scene(), map_width, map_height);
            } else if (c == '2') {
                auto e = get_world().new_entity("", "wall", true)
                        .add<ray::Model>("assets/indestructible_block/wall.gltf")
                        .add<fox::RigidBody>(get_scene())
                        .add<BoxCollider>(get_scene(), Vec3(1.5, 1.5, 1.5))
                        .add<fox::Transform>(Vec3(float(map_width - 8), 1, float(map_height - 6)), Vec3(0.5, 0.5, 0.5));
                e.get<fox::RigidBody>()->get_rb()->setType(reactphysics3d::BodyType::STATIC);
            }
        }
        map_height++;
    }
    _controller->set_heigth(map_height);
    _controller->set_width(map_width);
    _controller->generate();
    for (auto i = 1; i != map_width; i++) {
        for (auto j = 0; j != map_height - 1; j++) {
            if (((i+j) % 2) == 0) {
                auto e = get_world().new_entity()
                        .add<ray::Model>("assets/grounds/light_green.gltf")
                        .add<fox::RigidBody>(get_scene())
                        .add<BoxCollider>(get_scene(), Vec3(1.5, 1.5, 1.5))
                        .add<fox::Transform>(Vec3(float(i - 7), 0, float(j - 6)), Vec3(0.5, 0.5, 0.5));
                e.get<fox::RigidBody>()->get_rb()->setType(reactphysics3d::BodyType::STATIC);
            } else {
                auto e = get_world().new_entity()
                        .add<ray::Model>("assets/grounds/dark_green.gltf")
                        .add<fox::RigidBody>(get_scene())
                        .add<BoxCollider>(get_scene(), Vec3(1.5, 1.5, 1.5))
                        .add<fox::Transform>(Vec3(float(i - 7), 0, float(j - 6)), Vec3(0.5, 0.5, 0.5));
                e.get<fox::RigidBody>()->get_rb()->setType(reactphysics3d::BodyType::STATIC);
            }
        }
    }

       auto e = get_world().new_entity()
   .add<ray::Model>("assets/grounds/grass.gltf")
   .add<fox::Transform>(Vec3(0, -0.7, 0), Vec3(1.2, 1.2, 1.2));
}

void MapScript::on_update() {}

void MapScript::on_destroy() {}
