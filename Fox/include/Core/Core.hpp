/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Core.hpp
*/

#ifndef FOX_CORE_HPP_
#define FOX_CORE_HPP_

#ifdef FOX_PLATFORM_WINDOWS
    #ifdef FOX_BUILD_LIB
        #define FOX_API __declspec(dllexport)
    #else
        #define FOX_API __declspec(dllimport)
    #endif
#endif

#ifdef FOX_PLATFORM_LINUX
    #ifdef FOX_BUILD_LIB
        #define FOX_API __attribute__((visibility("default")))
    #else
        #define FOX_API
    #endif
#endif

#endif /* !FOX_CORE_HPP_ */
