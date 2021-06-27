/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Score.hpp
*/

#ifndef FOX_SCORE_HPP_
#define FOX_SCORE_HPP_

#include "Core/Event.hpp"

namespace fox
{
    class Score
    {
    public:
        Score(int score)
        {
            _score = score;
        }

        void setScore(int score)
        {
            _score = score;
        }

        int getScore() const
        {
            return _score;
        }

        void incrementScore(int score)
        {
            _score += score;
        }

        void decrementScore(int score)
        {
            _score -= score;
        }
    private:
        int _score;
    };
}
#endif