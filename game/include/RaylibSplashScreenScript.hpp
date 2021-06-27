/*
** EPITECH PROJECT, 2021
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** RaylibSplashScreenScript.hpp header
*/

#ifndef RAYLIB_SPLASH_SCREEN_SCRIPT_HPP
#define RAYLIB_SPLASH_SCREEN_SCRIPT_HPP

#include "ScriptableBehaviour.hpp"
#include "raylib.hpp"
#include <raylib-cpp/Rectangle.hpp>

class RaylibSplashScreenScript : public ScriptableBehaviour
{
    public:
        RaylibSplashScreenScript()
        {
            framesCounter = 0;
            lettersCount = 0;
            topSideRecWidth = 20;
            leftSideRecHeight = 20;
            bottomSideRecWidth = 20;
            rightSideRecHeight = 20;
            state = 0;
            alpha = 1.0f;
            screenWidth = 1280;
            screenHeight = 720;
            logoPositionX = screenWidth / 2 - 128;
            logoPositionY = screenHeight / 2 - 128;
        }

        void draw()
        {
            switch (state)
            {
                case 0:
                    if ((framesCounter / 15) % 2)
                        state0.set_enable(true);
                    else
                        state0.set_enable(false);
                    break;
                case 1:
                    state1.get<ray::Rectangle>()->SetSize(topSideRecWidth, 16);
                    state2.get<ray::Rectangle>()->SetSize(16, leftSideRecHeight);
                    break;
                case 2:
                    state0.get<ray::Rectangle>()->SetSize(topSideRecWidth, 16);
                    state1.get<ray::Rectangle>()->SetSize(16, leftSideRecHeight);

                    state2.get<ray::Rectangle>()->SetSize(16, rightSideRecHeight);
                    state3.get<ray::Rectangle>()->SetSize(bottomSideRecWidth, 16);
                    break;
                case 3:
                    state0.get<ray::Rectangle>()->setColor(Fade(ray::Color(255, 255, 255, 255), alpha));
                    state0.get<ray::Rectangle>()->SetSize(topSideRecWidth, 16);

                    state1.get<ray::Rectangle>()->setColor(Fade(ray::Color(255, 255, 255, 255), alpha));
                    state1.get<ray::Rectangle>()->SetSize(16, leftSideRecHeight - 32);

                    state2.get<ray::Rectangle>()->setColor(Fade(ray::Color(255, 255, 255, 255), alpha));
                    state2.get<ray::Rectangle>()->SetSize(16, rightSideRecHeight - 32);

                    state3.get<ray::Rectangle>()->setColor(Fade(ray::Color(255, 255, 255, 255), alpha));
                    state3.get<ray::Rectangle>()->SetSize(bottomSideRecWidth, 16);

                    state4.get<ray::Rectangle>()->setColor(Fade(ray::Color(0, 0, 0, 255), alpha));
                    state4.get<ray::Rectangle>()->SetSize(224, 224);

                    state5.get<ray::Text>()->SetColor(Fade(ray::Color(255, 255, 255, 255), alpha));
                    state5.get<ray::Text>()->SetString(TextSubtext("raylib", 0, lettersCount));
                    break;
                default:
                    break;
            }
        }

        virtual void on_create() override
        {
            state0 = new_entity().add<ray::Rectangle>(logoPositionX, logoPositionY, 16, 16, ray::Color(255, 255, 255, 255));
            state1 = new_entity("", "", false).add<ray::Rectangle>(logoPositionX, logoPositionY, topSideRecWidth, 16, ray::Color(255, 255, 255, 255));
            state2 = new_entity("", "", false).add<ray::Rectangle>(logoPositionX, logoPositionY, 16, leftSideRecHeight, ray::Color(255, 255, 255, 255));
            state3 = new_entity("", "", false).add<ray::Rectangle>(logoPositionX, logoPositionY + 240, bottomSideRecWidth, 16, ray::Color(255, 255, 255, 255));
            state4 = new_entity("", "", false).add<ray::Rectangle>(screenWidth/2 - 112, screenHeight/2 - 112);
            state5 = new_entity("", "", false).add<ray::Text>("").add<fox::Transform>(Vec2(screenWidth/2 - 44, screenHeight/2 + 48));
            state5.get<ray::Text>()->SetFontSize(50);
        }

        virtual void on_update() override
        {
            static int update = 0;

            if (update != 2) {
                update++;
                return;
            }
            update = 0;
            switch (state)
            {
            case 0:
                framesCounter++;

                if (framesCounter == 120)
                {
                    state0.set_enable(false);
                    state1.set_enable(true);
                    state2.set_enable(true);
                    state = 1;
                    framesCounter = 0;      // Reset counter... will be used later...
                }
                break;
            case 1:
                topSideRecWidth += 4;
                leftSideRecHeight += 4;

                if (topSideRecWidth == 256) {
                    state = 2;
                    state0.set_enable(true);
                    state3.set_enable(true);
                    state2.get<ray::Rectangle>()->SetPosition(logoPositionX + 240, logoPositionY);
                }
                break;
            case 2:
                bottomSideRecWidth += 4;
                rightSideRecHeight += 4;

                if (bottomSideRecWidth == 256) {
                    state = 3;

                    state1.get<ray::Rectangle>()->SetPosition(logoPositionX, logoPositionY + 16);
                    state2.get<ray::Rectangle>()->SetPosition(logoPositionX + 240, logoPositionY + 16);
                    state5.set_enable(true);
                }
                break;
            case 3:
                framesCounter++;

                if (framesCounter / 12)       // Every 12 frames, one more letter!
                {
                    lettersCount++;
                    framesCounter = 0;
                }

                if (lettersCount >= 10)     // When all letters have appeared, just fade out everything
                {
                    alpha -= 0.02f;

                    if (alpha <= 0.0f)
                    {
                        alpha = 0.0f;
                        state = 4;
                    }
                }
                break;
            default:
                break;
            }
            draw();
        }

        virtual void on_destroy() override {}
    private:
        int framesCounter;
        int lettersCount;
        int topSideRecWidth;
        int leftSideRecHeight;
        int bottomSideRecWidth;
        int rightSideRecHeight;
        int state;
        float alpha;
        int screenWidth;
        int screenHeight;
        int logoPositionX;
        int logoPositionY;

        fox::Entity state0;
        fox::Entity state1;
        fox::Entity state2;
        fox::Entity state3;
        fox::Entity state4;
        fox::Entity state5;
};

#endif // RAYLIB_SPLASH_SCREEN_SCRIPT_HPP