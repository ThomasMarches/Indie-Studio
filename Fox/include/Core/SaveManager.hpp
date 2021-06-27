/*
** EPITECH PROJECT, 2021
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** SaveManager.hpp header
*/

#ifndef SAVE_MANAGER_HPP_
#define SAVE_MANAGER_HPP_

#include <unordered_map>
#include <iostream>

struct playerInfo
{
    int score;
    std::string user_name;
};

class SaveManager
{
    public:
        SaveManager();
        void setSaveScores(const std::unordered_map<int, playerInfo> &scores);
        const std::unordered_map<int, playerInfo> &getSaveScores() const;
        void updateScores();
        void addPlayerIntoScore(const std::string &username, int score);
        void saveScoreIntoFile();
    private:
        std::unordered_map<int, playerInfo> v_SaveScores;
};

#endif // SAVE_MANAGER_HPP_