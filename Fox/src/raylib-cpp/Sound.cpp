/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Sound.cpp
*/

#include "raylib-cpp/Sound.hpp"

namespace ray {

    Sound::Sound(const ::Sound& vec) {
        set(vec);
    }

    Sound::Sound(const std::string& fileName) {
        set(LoadSound(fileName.c_str()));
    }

    Sound::Sound(const ::Wave& wave) {
        set(LoadSoundFromWave(wave));
    }

    Sound::~Sound() {
        Unload();
    }

    /**
     * Unload sound
     */
    void Sound::Unload() {
        ::UnloadSound(*this);
    }

    /**
     * Play a sound
     */
    Sound& Sound::Play() {
        ::PlaySound(*this);
        return *this;
    }

    /**
     * Stop playing a sound
     */
    Sound& Sound::Stop() {
        ::StopSound(*this);
        return *this;
    }

    /**
     * Pause a sound
     */
    Sound& Sound::Pause() {
        ::PauseSound(*this);
        return *this;
    }

    /**
     * Resume a paused sound
     */
    Sound& Sound::Resume() {
        ::ResumeSound(*this);
        return *this;
    }

    /**
     * Check if a sound is currently playing
     */
    bool Sound::IsPlaying() const {
        return ::IsSoundPlaying(*this);
    }

    /**
     * Set volume for a sound (1.0 is max level)
     */
    Sound& Sound::SetVolume(float volume) {
        ::SetSoundVolume(*this, volume);
        return *this;
    }

    /**
     * Set pitch for a sound (1.0 is base level)
     */
    Sound& Sound::SetPitch(float pitch) {
        ::SetSoundPitch(*this, pitch);
        return *this;
    }

    void Sound::set(const ::Sound& sound) {
        sampleCount = sound.sampleCount;
        stream = sound.stream;
    }
}