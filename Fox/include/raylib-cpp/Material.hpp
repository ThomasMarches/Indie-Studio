/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Material.hpp
*/

#ifndef RAYLIB_MATERIAL_HPP_
#define RAYLIB_MATERIAL_HPP_

#include <string>
#include "raylib.hpp"
#include <vector>

namespace ray {
    class Material : public ::Material {
    public:
        Material(const ::Material& material);
        Material();
        ~Material();
        std::vector<Material> Load(const std::string& fileName);
        Material& operator=(const ::Material& material);
        void Unload();
        Material& SetTexture(int mapType, const ::Texture2D& texture);
        void set(const ::Material& material);
    };
}// namespace ray

#endif  // RAYLIB_MATERIAL_HPP_