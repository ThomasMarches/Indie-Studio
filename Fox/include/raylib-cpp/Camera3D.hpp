/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Camera3D.hpp
*/

#ifndef RAYLIB_CAMERA3D_HPP_
#define RAYLIB_CAMERA3D_HPP_

#include <string>
#include "raylib.hpp"
#include "Utils/Vec3.hpp"
#include "Utils/Vec2.hpp"

namespace ray {
    class Camera3D : public ::Camera3D {
    public:
        Camera3D(const ::Camera3D& camera);
        Camera3D(Vec3 positionValue, Vec3 targetValue, Vec3 upValue,
            float fovyValue = 0, int projectionValue = 0);

        Camera3D& operator=(const ::Camera3D& camera);
        Camera3D& BeginMode();
        Camera3D& EndMode();
        Camera3D& SetMode(int mode);
        Camera3D& SetAltControl(int altKey);
        Camera3D& SetSmoothZoomControl(int szKey);
        Camera3D& SetMoveControls(int frontKey, int backKey, int rightKey, int leftKey,
            int upKey, int downKey);
        Camera3D& Update();
        Ray GetMouseRay(Vec2 mousePosition) const;
        Vec2 GetWorldToScreen(Vec3 position) const;
        Camera3D& DrawBillboard(const ::Texture2D& texture, Vec3 center,
            float size, ::Color tint = {255, 255, 255, 255});
        Camera3D& DrawBillboard(const ::Texture2D& texture, ::Rectangle sourceRec,
            Vec3 center, Vec2 size, ::Color tint = {255, 255, 255, 255});
        void set(const ::Camera3D& camera);
    };
} // namespace ray

#endif  // RAYLIB_CAMERA3D_HPP_