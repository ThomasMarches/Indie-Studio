/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Music.cpp
*/

#include "raylib-cpp/Music.hpp"

namespace ray
{

    Music::Music(const ::Music& Music)
    {
        set(Music);
    }

    Music::Music(const std::string& fileName)
    {
        set(::LoadMusicStream(fileName.c_str()));
    }

    Music::~Music()
    {
        Unload();
    }

    void Music::Unload()
    {
        if (stream.buffer != NULL)
            ::UnloadMusicStream(*this);
    }

    Music& Music::operator=(const ::Music& music)
    {
        set(music);
        return *this;
    }

    void Music::set(const ::Music &Music)
    {
        ctxType = Music.ctxType;
        ctxData = Music.ctxData;
        looping = Music.looping;
        sampleCount = Music.sampleCount;
        stream = Music.stream;
    }

    Music& Music::Play()
    {
        ::PlayMusicStream(*this);
        return *this;
    }

    Music& Music::Update()
    {
        ::UpdateMusicStream(*this);
        return *this;
    }

    Music& Music::Stop()
    {
        ::StopMusicStream(*this);
        return *this;
    }

    Music& Music::Pause()
    {
        ::PauseMusicStream(*this);
        return *this;
    }

    Music& Music::Resume()
    {
        ::ResumeMusicStream(*this);
        return *this;
    }

    bool Music::IsPlaying() const
    {
        return ::IsMusicPlaying(*this);
    }

    Music& Music::SetVolume(float volume)
    {
        ::SetMusicVolume(*this, volume);
        return *this;
    }

    float Music::GetTimePlayed() const
    {
        return ::GetMusicTimePlayed(*this);
    }

} // namespace ray