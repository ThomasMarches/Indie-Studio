/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Button.hpp
*/

#ifndef FOX_BUTTON_HPP_
#define FOX_BUTTON_HPP_

#include "raylib-cpp/Texture.hpp"
#include "Core/Event.hpp"

namespace fox
{
    enum class BtnState
    {
        NORMAL,
        HOVER,
        PRESSED,
        DISABLE
    };

    class Button
    {
    public:

        /**
         * @brief Constructor
         * @param fileName the filepath to the texture
         */
        Button(const std::string& fileName) : m_oSprite(fileName), onClick()
                                              , m_oState(BtnState::NORMAL), m_oPrevState(BtnState::DISABLE) {}

        /**
         * @brief Constructor
         * @param fileName the filepath to the texture
         * @param cb the function for the on_click event
         */
        Button(const std::string& fileName, std::function<void()> cb) : Button(fileName)
        {
            onClick.subscribe(std::move(cb));
        }

        /**
         * @brief Copy Constructor
         * @param other the r-value
         */
        Button(Button&& other)
        : m_oSprite(std::move(other.m_oSprite))
        , onClick(std::move(other.onClick))
        , m_oState(std::move(other.m_oState))
        , m_oPrevState(std::move(other.m_oPrevState))
        {
        }

        Button& operator=(Button&& rhs)
        {
            m_oSprite = std::move(rhs.m_oSprite);
            onClick = std::move(rhs.onClick);
            m_oState = std::move(rhs.m_oState);
            m_oPrevState = std::move(rhs.m_oPrevState);
            return *this;
        }

        /**
         * @brief Notify that the button have been click
         */
        void click()
        {
            onClick.notifiy();
        }

        /**
         * @brief Get the texture of the button
         * @return the texture of the button
         */
        ray::Texture& sprite()
        {
            return m_oSprite;
        }

        /**
         * @brief Get the current state
         * @return the current state
         */
        BtnState state()
        {
            return m_oState;
        }

        /**
         * @brief Get the previous state
         * @return the previous state
         */
        BtnState prev_state()
        {
            return m_oPrevState;
        }

        /**
         * @brief Set the current state
         * @param s the state
         */
        void set_state(BtnState s)
        {
            m_oPrevState = m_oState;
            m_oState = s;
        }


    private:
        ray::Texture m_oSprite;
        EventNotifier<void()> onClick;

        BtnState m_oState;
        BtnState m_oPrevState;
    };
}
#endif