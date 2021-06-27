/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** HowToPlaySceneTest.cpp
*/

#include <gtest/gtest.h>
#include "../game/include/HowToPlayScene.hpp"

TEST(HowToPlaySceneTest, GetText)
{
    HowToPlayScene scene;
    HowToPlayScene anotherScene("HowToPlay Scene");

    EXPECT_EQ(scene.get_how_to_play_text_index(0), 6) << "[GTEST]: HowToPlaySence getText() subfunction failed.";
    EXPECT_EQ(scene.get_how_to_play_text_index(1), 0) << "[GTEST]: HowToPlaySence getText() subfunction failed.";
    EXPECT_EQ(scene.get_how_to_play_text_index(0), MAX_HOW_TO_PLAY_INDEX - 1) << "[GTEST]: HowToPlaySence getText() subfunction failed.";
    EXPECT_EQ(scene.get_how_to_play_text_index(0), MAX_HOW_TO_PLAY_INDEX - 2) << "[GTEST]: HowToPlaySence getText() subfunction failed.";
    EXPECT_EQ(scene.get_how_to_play_text_index(0), MAX_HOW_TO_PLAY_INDEX - 3) << "[GTEST]: HowToPlaySence getText() subfunction failed.";
    EXPECT_EQ(scene.get_how_to_play_text_index(0), 3) << "[GTEST]: HowToPlaySence getText() subfunction failed.";
    EXPECT_EQ(scene.get_how_to_play_text_index(0), 2) << "[GTEST]: HowToPlaySence getText() subfunction failed.";
    EXPECT_EQ(scene.get_how_to_play_text_index(0), 1) << "[GTEST]: HowToPlaySence getText() subfunction failed.";
    EXPECT_EQ(scene.get_how_to_play_text_index(1), 2) << "[GTEST]: HowToPlaySence getText() subfunction failed.";
    EXPECT_EQ(scene.get_how_to_play_text_index(1), 3) << "[GTEST]: HowToPlaySence getText() subfunction failed.";
    EXPECT_EQ(scene.get_how_to_play_text_index(1), 4) << "[GTEST]: HowToPlaySence getText() subfunction failed.";
    EXPECT_EQ(scene.get_how_to_play_text_index(1), 5) << "[GTEST]: HowToPlaySence getText() subfunction failed.";
    EXPECT_EQ(scene.get_how_to_play_text_index(1), 6) << "[GTEST]: HowToPlaySence getText() subfunction failed.";
    EXPECT_EQ(scene.get_how_to_play_text_index(1), 0) << "[GTEST]: HowToPlaySence getText() subfunction failed.";
    EXPECT_EQ(scene.get_how_to_play_text_index(1), 1) << "[GTEST]: HowToPlaySence getText() subfunction failed.";
}

TEST(HowToPlaySceneTest, GetImage)
{
    HowToPlayScene anotherScene("HowToPlay Scene");

    EXPECT_EQ(anotherScene.get_how_to_play_image(0), "assets/how_to_play/htp7.png") << "[GTEST]: HowToPlaySence getImage() subfunction failed.";
    EXPECT_EQ(anotherScene.get_how_to_play_image(0), "assets/how_to_play/htp6.png") << "[GTEST]: HowToPlaySence getImage() subfunction failed.";
    EXPECT_EQ(anotherScene.get_how_to_play_image(0), "assets/how_to_play/htp5.png") << "[GTEST]: HowToPlaySence getImage() subfunction failed.";
    EXPECT_EQ(anotherScene.get_how_to_play_image(0), "assets/how_to_play/htp4.png") << "[GTEST]: HowToPlaySence getImage() subfunction failed.";
    EXPECT_EQ(anotherScene.get_how_to_play_image(0), "assets/how_to_play/htp3.png") << "[GTEST]: HowToPlaySence getImage() subfunction failed.";
    EXPECT_EQ(anotherScene.get_how_to_play_image(0), "assets/how_to_play/htp2.png") << "[GTEST]: HowToPlaySence getImage() subfunction failed.";
    EXPECT_EQ(anotherScene.get_how_to_play_image(0), "assets/how_to_play/htp1.png") << "[GTEST]: HowToPlaySence getImage() subfunction failed.";
    EXPECT_EQ(anotherScene.get_how_to_play_image(1), "assets/how_to_play/htp2.png") << "[GTEST]: HowToPlaySence getImage() subfunction failed.";
    EXPECT_EQ(anotherScene.get_how_to_play_image(1), "assets/how_to_play/htp3.png") << "[GTEST]: HowToPlaySence getImage() subfunction failed.";
    EXPECT_EQ(anotherScene.get_how_to_play_image(1), "assets/how_to_play/htp4.png") << "[GTEST]: HowToPlaySence getImage() subfunction failed.";
    EXPECT_EQ(anotherScene.get_how_to_play_image(1), "assets/how_to_play/htp5.png") << "[GTEST]: HowToPlaySence getImage() subfunction failed.";
    EXPECT_EQ(anotherScene.get_how_to_play_image(1), "assets/how_to_play/htp6.png") << "[GTEST]: HowToPlaySence getImage() subfunction failed.";
    EXPECT_EQ(anotherScene.get_how_to_play_image(1), "assets/how_to_play/htp7.png") << "[GTEST]: HowToPlaySence getImage() subfunction failed.";
    EXPECT_EQ(anotherScene.get_how_to_play_image(1), "assets/how_to_play/htp1.png") << "[GTEST]: HowToPlaySence getImage() subfunction failed.";
}
