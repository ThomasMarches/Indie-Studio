/*
** EPITECH PROJECT, 2021
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** InputBox.hpp header
*/

#include "raylib-cpp/Rectangle.hpp"

#ifndef RAYLIB_INPUT_BOX_HPP
#define RAYLIB_INPUT_BOX_HPP

namespace ray {
    class InputBox : public Rectangle {
    public:
        InputBox(float x, float y, float width, float height, ray::Color color, int charLength);
        bool isMouseOnBox() const;
        void UpdateBox();
        int getLength() const;
        int getIndex() const;
        void setLength(int length);
        std::string getContent() const;
        void setContent(const std::string &content);
        void setFramesCounter(int framesCounter);
        int getFramesCounter() const;
        InputBox& Draw() override;
    private:
        int _maxLength;
        int _framesCounter;
        std::string _content;
    };
}

#endif // RAYLIB_INPUT_BOX_HPP