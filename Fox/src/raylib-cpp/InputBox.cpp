/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** InputBox.cpp
*/

#include "raylib-cpp/InputBox.hpp"

namespace ray
{
    InputBox::InputBox(float x, float y, float width, float height, ray::Color color, int charLength) : Rectangle(x, y, width, height, color) {
        _maxLength = charLength;
        _framesCounter = 0;
        _content = "";
    }

    bool InputBox::isMouseOnBox() const
    {
        return ::CheckCollisionPointRec(::GetMousePosition(), Rectangle(x, y, width, height));
    }

    void InputBox::UpdateBox()
    {
        if (isMouseOnBox()) {
            std::string tmp = getContent();
            int key = ::GetCharPressed();

            if ((key >= 32) && (key <= 125) && (tmp.size() < getLength()))
               tmp += (char) key;

            if (IsKeyPressed(KEY_BACKSPACE) && tmp.size() > 0)
                tmp.erase(tmp.end() - 1);
            setContent(tmp);
            ::SetMouseCursor(MOUSE_CURSOR_IBEAM);
            setFramesCounter(getFramesCounter() + 1);
        } else {
            ::SetMouseCursor(MOUSE_CURSOR_DEFAULT);
            setFramesCounter(0);
        }
    }

    void InputBox::setLength(int length)
    {
        _maxLength = length;
    }

    void InputBox::setFramesCounter(int framesCounter)
    {
        _framesCounter = framesCounter;
    }

    int InputBox::getFramesCounter() const
    {
        return (_framesCounter);
    }

    int InputBox::getLength() const
    {
        return (_maxLength);
    }

    int InputBox::getIndex() const
    {
        return (_content.size());
    }

    void InputBox::setContent(const std::string &content)
    {
        _content = content;
    }

    std::string InputBox::getContent() const
    {
        return (_content);
    }

    InputBox &InputBox::Draw()
    {
        ::DrawRectangle(static_cast<int>(x), static_cast<int>(y), static_cast<int>(width),
            static_cast<int>(height), getColor());
        if (isMouseOnBox())
            ::DrawRectangleLines(x, y, width, height, ray::Color(0, 191, 255));
        else
            ::DrawRectangleLines(x, y, width, height, ray::Color(230, 41, 55, 255));
        ::DrawText(getContent().c_str(), x + 5, y + 15, 30, ray::Color(0, 191, 255));
        if (isMouseOnBox())
            if (getIndex() < getLength())
                if (((getFramesCounter() / 20) % 2) == 0 && getIndex() < 8)
                    DrawText("_", x + 8 + MeasureText(getContent().c_str(), 30), y + 17, 30, ray::Color(0, 191, 255));
        return *this;
    }
}