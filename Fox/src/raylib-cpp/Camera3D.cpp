/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Camera3D.cpp
*/

#include "raylib-cpp/Camera3D.hpp"

namespace ray
{
    Camera3D::Camera3D(const ::Camera3D& camera)
    {
        set(camera);
    }

    Camera3D::Camera3D(Vec3 positionValue, Vec3 targetValue, Vec3 upValue,
        float fovyValue, int projectionValue)
    {
        position = positionValue;
        target = targetValue;
        up = upValue;
        fovy = fovyValue;
        projection = projectionValue;
    }

    Camera3D& Camera3D::operator=(const ::Camera3D& camera)
    {
        set(camera);
        return *this;
    }

    /**
     * Initializes 3D mode with custom camera (3D)
     */
    Camera3D& Camera3D::BeginMode()
    {
        ::BeginMode3D(*this);
        return *this;
    }

    /**
     * Ends 3D mode and returns to default 2D orthographic mode
     */
    Camera3D& Camera3D::EndMode()
    {
        ::EndMode3D();
        return *this;
    }

    /**
     * Set camera mode (multiple camera modes available)
     */
    Camera3D& Camera3D::SetMode(int mode)
    {
        ::SetCameraMode(*this, mode);
        return *this;
    }

    /**
     * Set camera alt key to combine with mouse movement (free camera)
     */
    Camera3D& Camera3D::SetAltControl(int altKey)
    {
        ::SetCameraAltControl(altKey);
        return *this;
    }

    /**
     * Set camera smooth zoom key to combine with mouse (free camera)
     */
    Camera3D& Camera3D::SetSmoothZoomControl(int szKey)
    {
        ::SetCameraSmoothZoomControl(szKey);
        return *this;
    }

    /**
     * Set camera move controls (1st person and 3rd person cameras)
     */
    Camera3D& Camera3D::SetMoveControls(int frontKey, int backKey, int rightKey, int leftKey,
        int upKey, int downKey)
    {
        ::SetCameraMoveControls(frontKey, backKey, rightKey, leftKey, upKey, downKey);
        return *this;
    }

    /**
     * Update camera position for selected mode
     */
    Camera3D& Camera3D::Update()
    {
        ::UpdateCamera(this);
        return *this;
    }

    /**
     * Returns a ray trace from mouse position
     */
    Ray Camera3D::GetMouseRay(Vec2 mousePosition) const
    {
        return ::GetMouseRay(mousePosition, *this);
    }

    /**
     * Returns the screen space position for a 3d world space position
     */
    Vec2 Camera3D::GetWorldToScreen(Vec3 position) const
    {
        Vector2 v = ::GetWorldToScreen(position, *this);
        return Vec2(v.x, v.y);
    }

    /**
     * Draw a billboard texture.
     */
    Camera3D& Camera3D::DrawBillboard(const ::Texture2D& texture, Vec3 center,
        float size, ::Color tint)
    {
        ::DrawBillboard(*this, texture, center, size, tint);
        return *this;
    }

    /**
     * Draw a billboard texture defined by source.
     */
    Camera3D& Camera3D::DrawBillboard(const ::Texture2D& texture, ::Rectangle sourceRec,
        Vec3 center, Vec2 size, ::Color tint)
    {
        // ::DrawBillboardRec(*this, texture, sourceRec, center, size, tint);
        return *this;
    }

    void Camera3D::set(const ::Camera3D& camera)
    {
        position = camera.position;
        target = camera.target;
        up = camera.up;
        fovy = camera.fovy;
        projection = camera.projection;
    }
} // namespace ray