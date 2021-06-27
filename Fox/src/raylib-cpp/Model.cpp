/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Model.cpp
*/

#include "raylib-cpp/Model.hpp"

namespace ray
{
    Model::Model(const ::Model& model) {
        set(model);
    }

    Model::Model(const std::string& fileName) {
        set(::LoadModel(fileName.c_str()));
    }

    Model::~Model() {
        Unload();
    }

    Model& Model::operator=(const ::Model& model)
    {
        set(model);
        return *this;
    }

    /**
    * Unload model (including meshes) from memory (RAM and/or VRAM)
    */
    void Model::Unload()
    {
        if (meshes != NULL || materials != NULL) {
            ::UnloadModel(*this);
            meshes = NULL;
            materials = NULL;
        }
    }

    /**
    * Unload model (but not meshes) from memory (RAM and/or VRAM)
    */
    Model& Model::UnloadKeepMeshes()
    {
        ::UnloadModelKeepMeshes(*this);
        return *this;
    }

    /**
    * Set material for a mesh
    */
    Model& Model::SetMeshMaterial(int meshId, int materialId) {
        ::SetModelMeshMaterial(this, meshId, materialId);
        return *this;
    }

    /**
    * Get collision info between ray and model
    */
    RayHitInfo Model::GetCollision(const ::Ray& ray) const
    {
        return ::GetCollisionRayModel(ray, *this);
    }

    /**
    * Update model animation pose
    */
    Model& Model::UpdateAnimation(const ::ModelAnimation& anim, int frame)
    {
        ::UpdateModelAnimation(*this, anim, frame);
        return *this;
    }

    /**
    * Check model animation skeleton match
    */
    bool Model::IsModelAnimationValid(const ::ModelAnimation& anim) const
    {
        return ::IsModelAnimationValid(*this, anim);
    }

    /**
    * Draw a model (with texture if set)
    */
    Model& Model::Draw(Vec3 position, float scale, ::Color tint)
    {
        ::DrawModel(*this, position, scale, tint);
        return *this;
    }

    /**
    * Draw a model with extended parameters
    */
    Model& Model::Draw(Vec3 position, Vec3 rotationAxis,
    float rotationAngle, Vec3 scale, ::Color tint)
    {
        ::DrawModelEx(*this, position, rotationAxis, rotationAngle, scale, tint);
        return *this;
    }

    /**
    * Draw a model wires (with texture if set)
    */
    Model& Model::DrawWires(Vec3 position, float scale, ::Color tint)
    {
        ::DrawModelWires(*this, position, scale, tint);
        return *this;
    }

    /**
    * Draw a model wires (with texture if set) with extended parameters
    */
    Model& Model::DrawWires(Vec3 position, Vec3 rotationAxis,
        float rotationAngle, Vec3 scale, ::Color tint)
    {
        ::DrawModelWiresEx(*this, position, rotationAxis, rotationAngle, scale, tint);
        return *this;
    }

    void Model::set(const ::Model& model)
    {
        transform = model.transform;
        meshCount = model.meshCount;
        materialCount = model.materialCount;
        meshes = model.meshes;
        materials = model.materials;
        meshMaterial = model.meshMaterial;
        boneCount = model.boneCount;
        bones = model.bones;
        bindPose = model.bindPose;
    }

} // namespace ray