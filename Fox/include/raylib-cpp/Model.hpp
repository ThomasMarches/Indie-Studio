/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Model.hpp
*/

#ifndef RAYLIB_MODEL_HPP_
#define RAYLIB_MODEL_HPP_

#include <string>
#include "raylib.hpp"
#include "Utils/Vec3.hpp"
#include "Utils/Vec2.hpp"

namespace ray {
    class Model : public ::Model {
    public:
        Model(const ::Model& model);
        Model(const std::string& fileName);
        ~Model();

        Model& operator=(const ::Model& model);
        void Unload();
        Model& UnloadKeepMeshes();
        Model& SetMeshMaterial(int meshId, int materialId);
        RayHitInfo GetCollision(const ::Ray& ray) const;
        Model& UpdateAnimation(const ::ModelAnimation& anim, int frame);
        bool IsModelAnimationValid(const ::ModelAnimation& anim) const;
        void set(const ::Model& model);

        Model& Draw(Vec3 position, float scale = 1.0f,
            ::Color tint = {255, 255, 255, 255});
        Model& Draw(Vec3 position, Vec3 rotationAxis, float rotationAngle = 0.0f,
            Vec3 scale = {1.0f, 1.0f, 1.0f}, ::Color tint = {255, 255, 255, 255});
        Model& DrawWires(Vec3 position, float scale = 1.0f, ::Color tint = {255, 255, 255, 255});
        Model& DrawWires(Vec3 position, Vec3 rotationAxis, float rotationAngle = 0.0f,
            Vec3 scale = {1.0f, 1.0f, 1.0f}, ::Color tint = {255, 255, 255, 255});

    };
}  // namespace ray

#endif  // RAYLIB_MODEL_HPP_