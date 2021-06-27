/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Material.cpp
*/

#include "raylib-cpp/Material.hpp"

namespace ray
{
    Material::Material(const ::Material& material)
    {
        set(material);
    }

    /**
     * Load default material (Supports: DIFFUSE, SPECULAR, NORMAL maps)
     */
    Material::Material()
    {
        set(LoadMaterialDefault());
    }

    Material::~Material()
    {
        Unload();
    }

    /**
     * Load materials from model file
     */
    std::vector<Material> Material::Load(const std::string& fileName)
    {
        int count = 0;

        ::Material* materials = ::LoadMaterials(fileName.c_str(), &count);
        return std::vector<Material>(materials, materials + count);
    }

    Material& Material::operator=(const ::Material& material)
    {
        set(material);
        return *this;
    }

    /**
     * Unload material from memory
     */
    void Material::Unload()
    {
        if (maps != NULL) {
            ::UnloadMaterial(*this);
            maps = NULL;
        }
    }

    /**
     * Set texture for a material map type (MAP_DIFFUSE, MAP_SPECULAR...)
     */
    Material& Material::SetTexture(int mapType, const ::Texture2D& texture)
    {
        ::SetMaterialTexture(this, mapType, texture);
        return *this;
    }

    void Material::set(const ::Material& material)
    {
        shader = material.shader;
        maps = material.maps;
        params[0] = material.params[0];
        params[1] = material.params[1];
        params[2] = material.params[2];
        params[3] = material.params[3];
    }
} // namespace ray