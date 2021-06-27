/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** SaveManager.cpp
*/

#include "Core/SaveManager.hpp"
#include "FileSystem.hpp"

SaveManager::SaveManager()
{
    std::string saveStr;
    std::string tmpStr;
    std::string search = "\n";
    int currPos = 0;
    int index = 0;
    int prevPos = 0;
    int pos = 0;
    playerInfo values;

    if (fox::file::ReadFile("game/save/score.txt", saveStr) == false)
        std::cerr << "Couldn't open save score file." << std::endl;
    for (int spacePos = 0; spacePos != std::string::npos;) {
        spacePos = saveStr.find(search, currPos);
        if (spacePos != std::string::npos) {
            currPos = spacePos;
            tmpStr = saveStr.substr(prevPos, currPos - prevPos);
            currPos++;
            prevPos = currPos;
            values.user_name = tmpStr.substr(0, tmpStr.find(" ", 0));
            values.score = std::atoi(tmpStr.substr(tmpStr.find(" ", 0)).c_str());
            v_SaveScores[index] = values;
            index++;
        }
    }
    if (prevPos == std::string::npos)
        return;
    tmpStr = saveStr.substr(prevPos,saveStr.length());
    pos = tmpStr.find(" ", 0);
    if (pos == std::string::npos)
        return;
    values.user_name = tmpStr.substr(0, pos);
    values.score = std::atoi(tmpStr.substr(pos).c_str());
    v_SaveScores[index] = values;
}

const std::unordered_map<int, playerInfo> &SaveManager::getSaveScores() const
{
    return v_SaveScores;
}

void SaveManager::setSaveScores(const std::unordered_map<int, playerInfo> &scores)
{
    v_SaveScores = scores;
}

void SaveManager::addPlayerIntoScore(const std::string &username, int score)
{
    playerInfo new_user;
    int x = 0;

    std::cout << username << " : " << score << std::endl;
    for (std::unordered_map<int, playerInfo>::iterator it = v_SaveScores.begin(); it != v_SaveScores.end(); it++, x++) {
        if (it->second.user_name == username && score > it->second.score) {
            v_SaveScores.erase(it->first);
            new_user.score = score;
            new_user.user_name = username;
            v_SaveScores.insert({it->first, new_user});
            updateScores();
            return;
        }  else if (it->second.user_name == username)
            return;
    }
    new_user.score = score;
    new_user.user_name = username;
    v_SaveScores.insert({v_SaveScores.size(), new_user});
    updateScores();
}

void SaveManager::updateScores()
{
    std::unordered_map<int, playerInfo> finalValue;
    int save_idx = 0;
    int save = 0;

    for (int x = 0, stop = v_SaveScores.size(); x < stop; x++) {
        for (std::unordered_map<int, playerInfo>::iterator it = v_SaveScores.begin(); it != v_SaveScores.end(); it++) {
            if (it->second.score >= save) {
                save = it->second.score;
                save_idx = it->first;
            }
        }
        finalValue[x] = v_SaveScores[save_idx];
        v_SaveScores.erase(save_idx);
        save = 0;
    }
    setSaveScores(finalValue);
}

void SaveManager::saveScoreIntoFile()
{
    std::string userName;
    std::string score;
    std::string out_str;

    for (int x = v_SaveScores.size(), counter = 0; counter < x; counter++) {
        userName = v_SaveScores.at(counter).user_name;
        score = std::to_string(v_SaveScores.at(counter).score);
        out_str += userName + " " + score + "\n";
    }
    if (fox::file::WriteFile("game/save/score.txt", out_str) == false)
        std::cerr << "Couldn't open save score file." << std::endl;
}