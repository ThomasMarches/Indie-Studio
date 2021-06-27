/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Image.cpp
*/

#include "raylib-cpp/Image.hpp"

namespace ray
{
    Image::Image(const ::Image& image)
    {
        set(image);
    }

    Image::Image(const std::string& fileName)
    {
        Load(fileName);
    }

    Image::~Image() {}

    void Image::Load(const std::string& fileName)
    {
        set(::LoadImage(fileName.c_str()));
    }

    void Image::set(const ::Image& image)
    {
        data = image.data;
        width = image.width;
        height = image.height;
        mipmaps = image.mipmaps;
        format = image.format;
    }

    void Image::Unload()
    {
        if (data != NULL) {
            ::UnloadImage(*this);
            data = NULL;
        }
    }
} // namespace ray