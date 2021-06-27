/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Window.hpp
*/

#ifndef RAYLIB_WINDOW_HPP_
#define RAYLIB_WINDOW_HPP_

#include <string>
#include "raylib.hpp"
#include "Utils/Vec3.hpp"
#include "Utils/Vec2.hpp"
#include "Color.hpp"

namespace ray {
    class Window {
    public:
        Window();
        Window(int width, int height, const std::string& title);
        ~Window();

        void Init(int width, int height, const std::string& title);
        bool ShouldClose() const;
        void Close();
        bool IsCursorOnScreen() const;
        void ShowCursor();
        void HideCursor();
        bool IsReady();
        bool IsFullscreen() const;
        bool IsHidden() const;
        bool IsMinimized() const;
        bool IsMaximized() const;
        bool IsFocused() const;
        bool IsResized() const;
        bool IsState(unsigned int flag) const;
        Window& SetState(unsigned int flag);
        Window& ClearState(unsigned int flag);
        Window& ClearBackground(const ::Color& color = ray::Color(0, 0, 0, 255));
        Window& ToggleFullscreen();
        Window& SetFullscreen(bool fullscreen);
        Window& Maximize();
        Window& Minimize();
        Window& Restore();
        Window& SetIcon(const ::Image& image);
        Window& SetTitle(const std::string& title);
        Window& SetPosition(int x, int y);
        Window& SetPosition(const Vec2& position);
        Window& SetMonitor(int monitor);
        Window& SetMinSize(int width, int height);
        Window& SetSize(int width, int height);
        Window& SetSize(const Vec2& size);
        Vec2 GetSize();
        void* GetHandle() const;
        Window& BeginDrawing();
        Window& EndDrawing();
        int GetWidth() const;
        int GetHeight() const;
        Vec2 GetPosition() const;
        Vec2 GetScaleDPI() const;
        Window& SetTargetFPS(int fps);
        int GetFPS() const;
        float GetFrameTime() const;
        double GetTime() const;
        static void TakeAScreenshot();
    };
}  // namespace ray

#endif  // RAYLIB_WINDOW_HPP_