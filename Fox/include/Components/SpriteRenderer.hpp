/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** SpriteRenderer.hpp
*/

#ifndef FOX_SPRITE_RENDERER_HPP_
#define FOX_SPRITE_RENDERER_HPP_

#include <string>

namespace fox
{
    struct SpriteRenderer
    {
        SpriteRenderer(const std::string& strPath, const std::string& strId)
            : m_strPath(strPath), m_strId(strId)
        {
        }
        std::string m_strPath;
        std::string m_strId;
    };
}

#endif