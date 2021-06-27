/*
** EPITECH PROJECT, 2021
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** PowerUp.hpp header
*/

#ifndef POWER_UP_HPP_
#define POWER_UP_HPP_

#define NUMBER_OF_BOMB_BASE 1
#define SPEED_UP 1

class PowerUp
{
    public:
        PowerUp()
        {
            _bombNumberUp = 0;
            _bombRangeUp = 0;
            _numberOfBomb = 0;
            _speedUp = 0;
        }

        void setBombRangeUp(int range)
        {
            _bombRangeUp = range;
        }

        void setBombNumberUp(int number)
        {
            _bombNumberUp = number;
        }

        void setSpeedUp(float speed)
        {
            _speedUp = speed;
        }

        int getBombRangeUp() const
        {
            return _bombRangeUp;
        }

        int getBombNumberUp() const
        {
            return _bombNumberUp;
        }

        int getNumberOfBomb() const
        {
            return _numberOfBomb;
        }

        bool increaseNumberOfBomb()
        {
            if (_numberOfBomb >= getBombNumberUp() + NUMBER_OF_BOMB_BASE)
                return false;
            _numberOfBomb++;
            return true;
        }

        void decreaseNumberOfBomb()
        {
            _numberOfBomb--;
        }

        float getSpeedUp() const
        {
            return _speedUp;
        }

        void resetPowerUpValues()
        {
            _bombNumberUp = 0;
            _bombRangeUp = 0;
            _numberOfBomb = 0;
            _speedUp = 0;
        }
    private:
        int _bombRangeUp;
        int _numberOfBomb;
        int _bombNumberUp;
        float _speedUp;
};

#endif // POWER_UP_HPP_