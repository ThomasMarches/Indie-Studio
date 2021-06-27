/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Image.hpp
*/

#ifndef FOX_IMAGE_HPP_
#define FOX_IMAGE_HPP_

#include "raylib-cpp/Texture.hpp"
#include "Core/Event.hpp"

namespace fox
{
    class Image
    {
    public:
        /**
         * @brief Constructor
         * @param fileName the filepath to the texture
         */
        Image(const std::string& fileName) : m_oSprite(fileName) {}

        /**
         * @brief Get the texture of the image
         * @return the texture of the image
         */
        ray::Texture& sprite()
        {
            return m_oSprite;
        }

    private:
        ray::Texture m_oSprite;
    };
}
#endif