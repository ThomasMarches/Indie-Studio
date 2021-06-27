/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Mesh.cpp
*/

#include "raylib-cpp/Mesh.hpp"

namespace ray
{
   Mesh::Mesh(const ::Mesh& mesh)
   {
        set(mesh);
    }

    Mesh::Mesh(int VertexCount, int TriangleCount)
    {
        vertexCount = VertexCount;
        triangleCount = TriangleCount;
        vboId = NULL;
    }

    /**
     * Generate polygonal mesh
     */
    ::Mesh Mesh::Poly(int sides, float radius)
    {
        return ::GenMeshPoly(sides, radius);
    }

    /**
     * Generate plane mesh (with subdivisions)
     */
    ::Mesh Mesh::Plane(float width, float length, int resX, int resZ)
    {
        return ::GenMeshPlane(width, length, resX, resZ);
    }

    /**
     * Generate cuboid mesh
     */
    ::Mesh Mesh::Cube(float width, float height, float length)
    {
        return ::GenMeshCube(width, height, length);
    }

    /**
     * Generate sphere mesh (standard sphere)
     */
    ::Mesh Mesh::Sphere(float radius, int rings, int slices)
    {
        return ::GenMeshSphere(radius, rings, slices);
    }

    /**
     * Generate half-sphere mesh (no bottom cap)
     */
    ::Mesh Mesh::HemiSphere(float radius, int rings, int slices)
    {
        return ::GenMeshHemiSphere(radius, rings, slices);
    }

    /**
     * Generate cylinder mesh
     */
    ::Mesh Mesh::Cylinder(float radius, float height, int slices)
    {
        return ::GenMeshCylinder(radius, height, slices);
    }

    /**
     * Generate torus mesh
     */
    ::Mesh Mesh::Torus(float radius, float size, int radSeg, int sides)
    {
        return ::GenMeshTorus(radius, size, radSeg, sides);
    }

    /**
     * Generate trefoil knot mesh
     */
    ::Mesh Mesh::Knot(float radius, float size, int radSeg, int sides)
    {
        return ::GenMeshKnot(radius, size, radSeg, sides);
    }

    /**
     * Generate heightmap mesh from image data
     */
    ::Mesh Mesh::Heightmap(const ::Image& heightmap, ::Vector3 size)
    {
        return ::GenMeshHeightmap(heightmap, size);
    }

    /**
     * Generate cubes-based map mesh from image data
     */
    ::Mesh Mesh::Cubicmap(const ::Image& cubicmap, ::Vector3 cubeSize)
    {
        return ::GenMeshCubicmap(cubicmap, cubeSize);
    }

    Mesh& Mesh::operator=(const ::Mesh& mesh)
    {
        set(mesh);
        return *this;
    }

    Mesh::~Mesh()
    {
        Unload();
    }

    /**
     * Upload mesh vertex data to GPU (VRAM)
     */
    void Mesh::Upload(bool dynamic)
    {
        ::UploadMesh(this, dynamic);
    }

    /**
     * Upload mesh vertex data to GPU (VRAM)
     */
    void Mesh::UpdateBuffer(int index, void *data, int dataSize, int offset)
    {
        ::UpdateMeshBuffer(*this, index, data, dataSize, offset);
    }

    void Mesh::Draw(const ::Material& material, const ::Matrix& transform)
    {
        ::DrawMesh(*this, material, transform);
    }

    void Mesh::DrawInstanced(const ::Material& material, ::Matrix* transforms, int instances)
    {
        ::DrawMeshInstanced(*this, material, transforms, instances);
    }

    /**
     * Export mesh data to file
     */
    bool Mesh::Export(const std::string& fileName)
    {
        // TODO(RobLoach): Switch to an exception when failed.
        return ExportMesh(*this, fileName.c_str());
    }

    /**
     * Unload mesh from memory (RAM and/or VRAM)
     */
    void Mesh::Unload()
    {
        if (vboId != NULL)
        {
            ::UnloadMesh(*this);
            vboId = NULL;
        }
    }

    /**
     * Compute mesh bounding box limits
     */
    ray::BoundingBox Mesh::BoundingBox() const
    {
        return ::MeshBoundingBox(*this);
    }

    /**
     * Compute mesh tangents
     */
    Mesh& Mesh::Tangents()
    {
        ::MeshTangents(this);
        return *this;
    }

    /**
     * Compute mesh binormals (aka bitangent)
     */
    Mesh& Mesh::Binormals()
    {
        ::MeshBinormals(this);
        return *this;
    }

    /**
     * Load model from generated mesh
     */
    ray::Model Mesh::LoadModelFrom() const
    {
        return ::LoadModelFromMesh(*this);
    }

    void Mesh::set(const ::Mesh& mesh)
    {
        vertexCount = mesh.vertexCount;
        triangleCount = mesh.triangleCount;
        vertices = mesh.vertices;
        texcoords = mesh.texcoords;
        texcoords2 = mesh.texcoords2;
        normals = mesh.normals;
        tangents = mesh.tangents;
        colors = mesh.colors;
        indices = mesh.indices;
        animVertices = mesh.animVertices;
        animNormals = mesh.animNormals;
        boneIds = mesh.boneIds;
        boneWeights = mesh.boneWeights;
        vaoId = mesh.vaoId;
        vboId = mesh.vboId;
    }

} // namespace ray