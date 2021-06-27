/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Music.hpp
*/

#ifndef RAYLIB_MUSIC_HPP_
#define RAYLIB_MUSIC_HPP_

#include <string>
#include "raylib.hpp"

namespace ray {
    class Music : public ::Music {
    public:
        Music(const ::Music& Music);
        Music(const std::string& fileName);
        ~Music();

        void Unload();
        Music& operator=(const ::Music& music);
        Music &Play();
        Music &Update();
        Music &Stop();
        Music &Pause();
        Music &Resume();
        Music &SetVolume(float volume);
        bool IsPlaying() const;
        float GetTimePlayed() const;
        void set(const ::Music& Music);
    };
}  // namespace ray

#endif  // RAYLIB_MUSIC_HPP_