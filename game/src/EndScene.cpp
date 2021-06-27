/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** EndScene.cpp
*/

#include "raylib-cpp.hpp"
#include "FoxEngine.hpp"
#include "EndScene.hpp"
#include "raylib-cpp/Rectangle.hpp"
#include "../include/Core/SaveManager.hpp"

std::vector<Vec3> EndScene::PodiumVec3 =
        {
                Vec3(600, 395, 0),
                Vec3(435, 440, 0),
                Vec3(760, 475, 0),
                Vec3(1000, 450, 0),
        };

EndScene::EndScene() : fox::Scene(), overallScoreboardHeight(0) {}

EndScene::EndScene(const std::string& name) : fox::Scene(name), overallScoreboardHeight(0) {}

EndScene::~EndScene() {}

const std::string &EndScene::getNameAtIndex(int index)
{
    return v_Names.at(index);
}

int EndScene::getScoreAtIndex(int index)
{
    return v_ScoreAim.at(index);
}

void EndScene::updateOverallScoreboard(fox::Application &app)
{
    float mouse_move = fox::Input::mouse_wheel();
    std::vector<fox::Entity> v_Entities;
    std::vector<fox::Entity> v_ScoresEntity;
    fox::Entity e;
    Vec3 entity_position;
    float y_pos = 0;

    if (mouse_move < 0 && overallScoreboardHeight > 0) {
        overallScoreboardHeight -= 10;
    } else if (mouse_move > 0 && overallScoreboardHeight <= (app.get_save_manager().getSaveScores().size() - 20) * 20) {
        overallScoreboardHeight += 10;
    } else
        return;
    if (!(get_world().get_entities_with_tag("overall_scoreboard_names", v_Entities) && get_world().get_entities_with_tag("overall_scoreboard_scores", v_ScoresEntity)))
        return;
    v_Entities.insert(v_Entities.begin(), v_ScoresEntity.begin(), v_ScoresEntity.end());
    if (get_world().get_entity("scoreboard_scroll_nav", e)) {
        y_pos = 400 / app.get_save_manager().getSaveScores().size();
        e.get<fox::Transform>()->position.y = 165 + (y_pos * (overallScoreboardHeight / 9));
    }
    for (int x = 0; x < v_Entities.size(); x++) {
        e = v_Entities.at(x);
        entity_position = e.get<fox::Transform>()->position;
        if (mouse_move > 0)
            e.get<fox::Transform>()->position.y -= 10;
        else
            e.get<fox::Transform>()->position.y += 10;
        if (entity_position.y >= 160 && entity_position.y <= 560) {
            e.set_enable(true);
        } else
            e.set_enable(false);
    }
}

void EndScene::createOverallScoreboard(fox::Application &app)
{
    Vec3 text_position = Vec3(Vec3(55, 170, 0));
    std::unordered_map<int, playerInfo> v_OverallScore;

    for (int x = 0; x < app.get_player_manager().getPlayerNames().size(); x++)
        if (app.get_player_manager().getPlayerNameAtIndex(x) != "Player " + std::to_string(x + 1))
            app.get_save_manager().addPlayerIntoScore(app.get_player_manager().getPlayerNameAtIndex(x), app.get_player_manager().getScores().at("player" + std::to_string(x)));
    app.get_save_manager().updateScores();
    app.get_save_manager().saveScoreIntoFile();
    v_OverallScore = app.get_save_manager().getSaveScores();
    for (int x = 0; x < v_OverallScore.size(); x++) {
        fox::Entity e1 = get_world().new_entity("", "overall_scoreboard_names", true)
                .add<fox::Transform>(text_position + Vec3(0, 20 * x, 0))
                .add<ray::Text>(v_OverallScore.at(x).user_name, ray::Color(0, 0, 0, 255));
        e1.get<ray::Text>()->SetFontSize(15);
        fox::Entity e2 = get_world().new_entity("", "overall_scoreboard_scores", true)
                .add<fox::Transform>(text_position + Vec3(300 - ray::Text::GetTextWidth(std::to_string(v_OverallScore.at(x).score), 15), 20 * x, 0))
                .add<ray::Text>(std::to_string(v_OverallScore.at(x).score), ray::Color(0, 0, 0, 255));
        e2.get<ray::Text>()->SetFontSize(15);
        if (text_position.y + (20 * x) > 560) {
            e1.set_enable(false);
            e2.set_enable(false);
        }
    }
}

void EndScene::createPodium(fox::Application &app)
{
    std::unordered_map<std::string, int> scores = app.get_player_manager().getScores();
    int x = 0;
    int save = 0;
    int index = 0;
    int textSize = 0;

    for (int cntr = 0; cntr < 4; cntr++) {
        for (int counter = 0; counter < 4; counter++, x++) {
            if (counter > app.get_player_manager().getPlayerNames().size() - 1) {
                if (scores.at("ia_" + std::to_string(counter - app.get_player_manager().getPlayerNames().size() + 1)) >= save) {
                    save = scores.at("ia_" + std::to_string(counter - app.get_player_manager().getPlayerNames().size() + 1));
                    index = x;
                }
            } else {
                if (scores.at("player" + std::to_string(counter)) >= save) {
                    save = scores.at("player" + std::to_string(counter));
                    index = x;
                }
            }
        }
        if (index > app.get_player_manager().getPlayerNames().size() - 1) {
            get_world().new_entity()
                    .add<fox::Transform>(PodiumVec3.at(cntr))
                    .add<ray::Text>("IA " + std::to_string(index - app.get_player_manager().getPlayerNames().size() + 1), ray::Color(0, 0, 0, 255))
                    .get<ray::Text>()->SetFontSize(25);
            get_world().new_entity("score" + std::to_string(cntr))
                    .add<fox::Transform>(PodiumVec3.at(cntr) + Vec3((ray::Text::GetTextWidth("IA X", 25) - ray::Text::GetTextWidth("0", 25)) / 2, -30, 0))
                    .add<ray::Text>("0", ray::Color(0, 0, 0, 255))
                    .get<ray::Text>()->SetFontSize(25);
            get_world().new_entity("player_image" + std::to_string(cntr))
                    .add<fox::Transform>(PodiumVec3.at(cntr) + Vec3(0, -600, 0))
                    .add<fox::Image>("assets/selection_screen/" + app.get_player_manager().getPlayerColorAtIndex(index + 1) + ".png");
            v_ScoreAim[cntr] = save;
            v_Names.push_back("IA " + std::to_string(index - app.get_player_manager().getPlayerNames().size() + 1));
            scores["ia_" + std::to_string(index - app.get_player_manager().getPlayerNames().size() + 1)] = -1;
        } else {
            get_world().new_entity()
                    .add<fox::Transform>(PodiumVec3.at(cntr))
                    .add<ray::Text>(app.get_player_manager().getPlayerNameAtIndex(index), ray::Color(0, 0, 0, 255))
                    .get<ray::Text>()->SetFontSize(25);
            get_world().new_entity("score" + std::to_string(cntr))
                    .add<fox::Transform>(PodiumVec3.at(cntr) + Vec3((ray::Text::GetTextWidth(app.get_player_manager().getPlayerNameAtIndex(index), 25) - ray::Text::GetTextWidth("0", 25)) / 2, -30, 0))
                    .add<ray::Text>("0", ray::Color(0, 0, 0, 255))
                    .get<ray::Text>()->SetFontSize(25);
            get_world().new_entity("player_image" + std::to_string(cntr))
                    .add<fox::Transform>(PodiumVec3.at(cntr) + Vec3(0, -600, 0))
                    .add<fox::Image>("assets/selection_screen/" + app.get_player_manager().getPlayerColorAtIndex(index + 1) + ".png");
            v_ScoreAim[cntr] = save;
            v_Names.push_back(app.get_player_manager().getPlayerNameAtIndex(index));
            scores["player" + std::to_string(index)] = -1;
        }
        index = 0;
        save = 0;
        x = 0;
    }
}

void EndScene::on_create(fox::Application& app) { }

void EndScene::on_enable(fox::Application& app)
{
    app.PlaySound("MusicEffect", "assets/sounds/end.ogg", 1, 1);

    auto rec = m_oWorld.new_entity();
    rec
            .add<fox::Transform>(Vec3(30, 100, 0))
            .add<ray::Rectangle>(30, 100, 350, 500, ray::Color(255, 255, 255, 150));

    auto rec1 = m_oWorld.new_entity();
    rec1
            .add<fox::Transform>(Vec3(35, 105, 0))
            .add<ray::Rectangle>(35, 105, 340, 490, ray::Color(0, 0, 0, 80));

    auto scoreboard_txt = m_oWorld.new_entity();
    scoreboard_txt
            .add<ray::Text>("Overall scoreboard", ray::Color(0, 0, 0, 255))
            .add<fox::Transform>(Vec3(55, 120, 0));
    scoreboard_txt.get<ray::Text>()->SetFontSize(30);

    auto scoreboard_scroll_nav = m_oWorld.new_entity("scoreboard_scroll_nav");
    scoreboard_scroll_nav
            .add<fox::Transform>(Vec3(375, 165, 0))
            .add<ray::Rectangle>(375, 165, 5, 20, ray::Color(0, 0, 0, 220));

    auto wallpaper = m_oWorld.new_entity();
    wallpaper
            .add<ray::Texture>("assets/green_wallpaper.png")
            .add<fox::Transform>(Vec3(0, 0, 0));

    // HEADER

    auto main_header = m_oWorld.new_entity();
    main_header
            .add<ray::Texture>("assets/rectangle.png")
            .add<fox::Transform>(Vec3(0, 0, 0));
    main_header.get<fox::Transform>()->scale = Vec3(2.2, 1, 0);

    auto main_image = m_oWorld.new_entity();
    main_image
            .add<fox::Image>("assets/blue_score.png")
            .add<fox::Transform>();
    main_image.get<fox::Transform>()->set_parent(main_header.get<fox::Transform>().value());
    main_image.get<fox::Transform>()->set_pos(9, 9, 0);

    auto main_txt = m_oWorld.new_entity();
    main_txt
            .add<ray::Text>("Scoreboard")
            .add<fox::Transform>();
    main_txt.get<fox::Transform>()->set_parent(main_header.get<fox::Transform>().value());
    main_txt.get<fox::Transform>()->set_pos(540, 15, 0);
    main_txt.get<ray::Text>()->SetColor(ray::Color(0, 191, 255)).SetFontSize(40);

    // QUIT BUTTON

    auto quit_button = m_oWorld.new_entity("quit_btn");
    quit_button
            .add<fox::Transform>(Vec3(1210, 655, 0))
            .add<Animator>()
            .add<fox::Button>("assets/menu/exit.png", [this, &app]{
              app.PlaySound("GroupEffect", "assets/sounds/click.ogg", 1, 1);
              app.quit();
            });
    quit_button.get<Animator>()->add_anim("Normal")
            .add<Vec3>()
            .apply(quit_button.get<fox::Transform>()->scale)
            .then(0, Vec3(1.2, 1.2, 1.2))
            .then(1, Vec3(1.2, 1.2, 1.2));
    quit_button.get<Animator>()->add_anim("Hover")
            .signal(0, [&app, this] { app.PlaySound("GroupEffect", "assets/sounds/hover.ogg", 0.02, 1); })
            .add<Vec3>()
            .apply(quit_button.get<fox::Transform>()->scale)
            .then(0, Vec3(1.25, 1.25, 1.25))
            .then(1, Vec3(1.25, 1.25, 1.25));
    quit_button.get<fox::Button>()->sprite().SetColor(ray::Color(0, 191, 255));

    auto quit_text = m_oWorld.new_entity("quit_text", false);
    quit_text
            .add<ray::Text>("Exit the game")
            .add<fox::Transform>(Vec3(600, 680, 0));
    quit_text.get<ray::Text>()->SetColor(ray::Color(0, 191, 255));



    auto banner = m_oWorld.new_entity("Banner");
    banner
            .add<ray::Texture>("assets/rectangle.png")
            .add<fox::Transform>(Vec3(0, 655, 0));
    banner.get<fox::Transform>()->scale = Vec3(3, 1, 0);

    auto scoreboard = m_oWorld.new_entity();
    scoreboard
            .add<ray::Texture>("assets/ranking.png")
            .add<fox::Transform>(Vec3(400, 125, 0));

    createOverallScoreboard(app);
    createPodium(app);
}

void EndScene::on_destroy(fox::Application& app) { }
void EndScene::on_update(fox::Application& app)
{
    static int score1 = 0;
    static int score2 = 0;
    static int score3 = 0;
    static int score4 = 0;
    int index = 3;
    fox::Entity e;
    fox::Entity e2;
    Vec2 v_back;
    ray::Rectangle rec;
    ray::Mouse mouse;

    updateOverallScoreboard(app);
    for (int x = 3; x >= 0; x--) {
        if (get_world().get_entity("player_image" + std::to_string(x), e)) {
            switch (x)
            {
                case 0:
                    if (e.get<fox::Transform>()->position.y < 235 && index == 0)
                        e.get<fox::Transform>()->position.y += 3;
                    else if (index == 0 && score1 >= getScoreAtIndex(0))
                        index--;
                    break;
                case 1:
                    if (e.get<fox::Transform>()->position.y < 280 && index == 1)
                        e.get<fox::Transform>()->position.y += 3;
                    else if (index == 1  && score2 >= getScoreAtIndex(1))
                        index--;
                    break;
                case 2:
                    if (e.get<fox::Transform>()->position.y < 315 && index == 2)
                        e.get<fox::Transform>()->position.y += 3;
                    else if (index == 2 && score3 >= getScoreAtIndex(2))
                        index--;
                    break;
                case 3:
                    if (e.get<fox::Transform>()->position.y < 290 && index == 3)
                        e.get<fox::Transform>()->position.y += 3;
                    else if (index == 3 && score4 >= getScoreAtIndex(3))
                        index--;
                    break;
                default:
                    break;
            }
        }
        if (get_world().get_entity("score" + std::to_string(x), e)) {
            switch (x)
            {
                case 0:
                    if (std::atoi(e.get<ray::Text>()->GetString().c_str()) < getScoreAtIndex(0) && index == 0) {
                        score1 += 5;
                        e.get<ray::Text>()->SetString(std::to_string(score1));
                        e.get<fox::Transform>()->position = (PodiumVec3.at(x) + Vec3((ray::Text::GetTextWidth(getNameAtIndex(x), 25) - ray::Text::GetTextWidth(std::to_string(score1), 25)) / 2, -30, 0));
                    }
                    break;
                case 1:
                    if (std::atoi(e.get<ray::Text>()->GetString().c_str()) < getScoreAtIndex(1) && index == 1) {
                        score2 += 5;
                        e.get<ray::Text>()->SetString(std::to_string(score2));
                        e.get<fox::Transform>()->position = (PodiumVec3.at(x) + Vec3((ray::Text::GetTextWidth(getNameAtIndex(x), 25) - ray::Text::GetTextWidth(std::to_string(score2), 25)) / 2, -30, 0));
                    }
                    break;
                case 2:
                    if (std::atoi(e.get<ray::Text>()->GetString().c_str()) < getScoreAtIndex(2) && index == 2) {
                        score3 += 5;
                        e.get<ray::Text>()->SetString(std::to_string(score3));
                        e.get<fox::Transform>()->position = (PodiumVec3.at(x) + Vec3((ray::Text::GetTextWidth(getNameAtIndex(x), 25) - ray::Text::GetTextWidth(std::to_string(score3), 25)) / 2, -30, 0));
                    }
                    break;
                case 3:
                    if (std::atoi(e.get<ray::Text>()->GetString().c_str()) < getScoreAtIndex(3) && index == 3) {
                        score4 += 5;
                        e.get<ray::Text>()->SetString(std::to_string(score4));
                        e.get<fox::Transform>()->position = (PodiumVec3.at(x) + Vec3((ray::Text::GetTextWidth(getNameAtIndex(x), 25) - ray::Text::GetTextWidth(std::to_string(score4), 25)) / 2, -30, 0));
                    }
                    break;
                default:
                    break;
            }
        }
    }

    if (get_world().get_entity("go_back_to_menu", e)) {
        v_back = e.get<fox::Button>()->sprite().GetSize();
        rec = ray::Rectangle(e.get<fox::Transform>()->position.x, e.get<fox::Transform>()->position.y, (v_back.x / 10), (v_back.y / 10));
        if (rec.CheckCollision(mouse.GetPosition())) {
            if (get_world().get_entity("back_text", e2)) {
                e2.set_enable(true);
            }
        } else {
            if (get_world().get_entity("back_text", e2)) {
                e2.set_enable(false);
            }
        }
    }
    if (get_world().get_entity("replay_btn", e)) {
        v_back = e.get<fox::Button>()->sprite().GetSize();
        rec = ray::Rectangle(e.get<fox::Transform>()->position.x, e.get<fox::Transform>()->position.y, (v_back.x / 3), (v_back.y / 3));
        if (rec.CheckCollision(mouse.GetPosition())) {
            if (get_world().get_entity("replay_text", e2)) {
                e2.set_enable(true);
            }
        } else {
            if (get_world().get_entity("replay_text", e2)) {
                e2.set_enable(false);
            }
        }
    }

}

void EndScene::on_disable(fox::Application& app)
{
    app.StopSound("assets/sounds/end.ogg");
}