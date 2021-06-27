/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Window.cpp
*/

#include "raylib-cpp/Window.hpp"

namespace ray
{
    Window::Window() {}
    Window::Window(int width, int height, const std::string &title)
    {
        Init(width, height, title);
    }

    Window::~Window()
    {
        Close();
    }

    void Window::Init(int width, int height, const std::string &title)
    {
        InitWindow(width, height, title.c_str());
    }

    bool Window::ShouldClose() const
    {
        return WindowShouldClose();
    }

    void Window::Close()
    {
        CloseWindow();
    }

    bool Window::IsCursorOnScreen() const
    {
        return IsCursorOnScreen();
    }

    void Window::ShowCursor()
    {
        ShowCursor();
    }

    void Window::HideCursor()
    {
        HideCursor();
    }

    bool Window::IsReady()
    {
        return IsWindowReady();
    }

    bool Window::IsFullscreen() const
    {
        return IsWindowFullscreen();
    }

    bool Window::IsHidden() const
    {
        return IsWindowHidden();
    }

    bool Window::IsMinimized() const
    {
        return IsWindowMinimized();
    }

    bool Window::IsMaximized() const
    {
        return IsWindowMaximized();
    }

    bool Window::IsFocused() const
    {
        return IsWindowFocused();
    }

    bool Window::IsResized() const
    {
        return IsWindowResized();
    }

    bool Window::IsState(unsigned int flag) const
    {
        return IsWindowState(flag);
    }

    Window &Window::SetState(unsigned int flag)
    {
        SetWindowState(flag);
        return *this;
    }

    Window &Window::ClearState(unsigned int flag)
    {
        ::ClearWindowState(flag);
        return *this;
    }

    Window &Window::ClearBackground(const ::Color &color)
    {
        ::ClearBackground(color);
        return *this;
    }

    Window &Window::ToggleFullscreen()
    {
        ::ToggleFullscreen();
        return *this;
    }

    Window &Window::SetFullscreen(bool fullscreen)
    {
        if (fullscreen)
        {
            if (!IsFullscreen())
            {
                ToggleFullscreen();
            }
        }
        else
        {
            if (IsFullscreen())
            {
                ToggleFullscreen();
            }
        }

        return *this;
    }

    Window &Window::Maximize()
    {
        MaximizeWindow();
        return *this;
    }

    Window &Window::Minimize()
    {
        MinimizeWindow();
        return *this;
    }

    Window &Window::Restore()
    {
        RestoreWindow();
        return *this;
    }

    Window &Window::SetIcon(const ::Image &image)
    {
        SetWindowIcon(image);
        return *this;
    }

    Window &Window::SetTitle(const std::string &title)
    {
        SetWindowTitle(title.c_str());
        return *this;
    }

    Window &Window::SetPosition(int x, int y)
    {
        SetWindowPosition(x, y);
        return *this;
    }

    Window &Window::SetPosition(const Vec2 &position)
    {
        return SetPosition(static_cast<int>(position.x), static_cast<int>(position.y));
    }

    Window &Window::SetMonitor(int monitor)
    {
        SetWindowMonitor(monitor);
        return *this;
    }

    Window &Window::SetMinSize(int width, int height)
    {
        SetWindowMinSize(width, height);
        return *this;
    }

    Window &Window::SetSize(int width, int height)
    {
        SetWindowSize(width, height);
        return *this;
    }

    Window &Window::SetSize(const Vec2 &size)
    {
        return SetSize(static_cast<int>(size.x), static_cast<int>(size.y));
    }

    Vec2 Window::GetSize()
    {
        return {static_cast<float>(GetWidth()), static_cast<float>(GetHeight())};
    }

    void *Window::GetHandle() const
    {
        return GetWindowHandle();
    }

    Window &Window::BeginDrawing()
    {
        ::BeginDrawing();
        return *this;
    }

    Window &Window::EndDrawing()
    {
        ::EndDrawing();
        return *this;
    }

    int Window::GetWidth() const
    {
        return GetScreenWidth();
    }

    int Window::GetHeight() const
    {
        return GetScreenHeight();
    }

    Vec2 Window::GetPosition() const
    {
        Vector2 v = GetWindowPosition();
        return Vec2(v.x, v.y);
    }

    Vec2 Window::GetScaleDPI() const
    {
        Vector2 v = GetWindowScaleDPI();
        return Vec2(v.x, v.y);
    }

    Window &Window::SetTargetFPS(int fps)
    {
        ::SetTargetFPS(fps);
        return *this;
    }

    int Window::GetFPS() const
    {
        return ::GetFPS();
    }

    float Window::GetFrameTime() const
    {
        return ::GetFrameTime();
    }

    double Window::GetTime() const
    {
        return ::GetTime();
    }

    void Window::TakeAScreenshot()
    {
        bool fileExist = true;
        std::string filePath = "Screenshots/";
        int fileNumber = 0;
        char **dir_files = NULL;

        dir_files = GetDirectoryFiles(filePath.c_str(), &fileNumber);
        if (!FileExists("Screenshots/screenshot1.png"))
            fileNumber -= 2;
        TakeScreenshot(std::string(filePath + "screenshot" + std::to_string(fileNumber) + ".png").c_str());
    }

} // namespace ray