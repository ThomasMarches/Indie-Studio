/*
** EPITECH PROJECT, 2021
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Sound.hpp header
*/

#ifndef RAYLIB_SOUND_HPP_
#define RAYLIB_SOUND_HPP_

#include "raylib-cpp.hpp"

namespace ray {
class Sound : public ::Sound {
    public:
        Sound(const ::Sound& vec);
        Sound(const std::string& fileName);
        Sound(const ::Wave& wave);
        ~Sound();

        void Unload();
        Sound& Play();
        Sound& Stop();
        Sound& Pause();
        Sound& Resume();
        bool IsPlaying() const;
        Sound& SetVolume(float volume);
        Sound& SetPitch(float pitch);
        void set(const ::Sound& sound);
    };
}  // namespace ray

#endif // RAYLIB_SOUND_HPP_