/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Mesh.hpp
*/

#ifndef RAYLIB_MESH_HPP_
#define RAYLIB_MESH_HPP_

#include <string>
#include <vector>
#include "raylib.hpp"
#include "BoundingBox.hpp"
#include "Model.hpp"

namespace ray {
    class Mesh : public ::Mesh {
    public:
        Mesh(const ::Mesh& mesh);
        Mesh(int VertexCount, int TriangleCount);
        ::Mesh Poly(int sides, float radius);
        ::Mesh Plane(float width, float length, int resX, int resZ);
        ::Mesh Cube(float width, float height, float length);
        ::Mesh Sphere(float radius, int rings, int slices);
        ::Mesh HemiSphere(float radius, int rings, int slices);
        ::Mesh Cylinder(float radius, float height, int slices);
        ::Mesh Torus(float radius, float size, int radSeg, int sides);
        ::Mesh Knot(float radius, float size, int radSeg, int sides);
        ::Mesh Heightmap(const ::Image& heightmap, ::Vector3 size);
        ::Mesh Cubicmap(const ::Image& cubicmap, ::Vector3 cubeSize);
        Mesh& operator=(const ::Mesh& mesh);
        ~Mesh();
        void Upload(bool dynamic = false);
        void UpdateBuffer(int index, void *data, int dataSize, int offset = 0);
        void Draw(const ::Material& material, const ::Matrix& transform);
        void DrawInstanced(const ::Material& material, ::Matrix* transforms, int instances);
        bool Export(const std::string& fileName);
        void Unload();
        ray::BoundingBox BoundingBox() const;
        Mesh& Tangents();
        Mesh& Binormals();
        ray::Model LoadModelFrom() const;
        void set(const ::Mesh& mesh);
    };
}  // namespace ray

#endif  // RAYLIB_MESH_HPP_