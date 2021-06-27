/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** MeshTest.cpp
*/

#include <gtest/gtest.h>
#include "../Fox/include/raylib-cpp/Mesh.hpp"
#include "../Fox/include/raylib-cpp/BoundingBox.hpp"

TEST(MeshTest, Export)
{
    ray::Mesh mesh = ray::Mesh(1, 1);

    EXPECT_FALSE(mesh.Export("testfiles.png")) << "[GTEST]: ray::Mesh Export() wrong obj extension test failed";
}

TEST(MeshTest, BoundingBoxOperator)
{
    ray::Mesh mesh = ray::Mesh(1, 1);

    mesh.vertices = NULL;
    ray::BoundingBox box = mesh.BoundingBox();
    EXPECT_EQ(box, ray::BoundingBox(Vec3(0, 0, 0), Vec3(0, 0, 0))) << "[GTEST]: ray::Mesh BoundingBox() with null vertices on ray::Mesh test failed";
}

TEST(MeshTest, OperatorEqual)
{
    ray::Mesh mesh = ray::Mesh(1, 1);
    ray::Mesh anotherOne = ray::Mesh(mesh);

    anotherOne = mesh;
    EXPECT_EQ(mesh.vertexCount, anotherOne.vertexCount) << "[GTEST]: ray::Mesh operator= test failed.";
    EXPECT_EQ(mesh.triangleCount, anotherOne.triangleCount) << "[GTEST]: ray::Mesh operator= test failed.";
    EXPECT_EQ(mesh.vertices, anotherOne.vertices) << "[GTEST]: ray::Mesh operator= test failed.";
    EXPECT_EQ(mesh.texcoords, anotherOne.texcoords) << "[GTEST]: ray::Mesh operator= test failed.";
    EXPECT_EQ(mesh.texcoords2, anotherOne.texcoords2) << "[GTEST]: ray::Mesh operator= test failed.";
    EXPECT_EQ(mesh.normals, anotherOne.normals) << "[GTEST]: ray::Mesh operator= test failed.";
    EXPECT_EQ(mesh.tangents, anotherOne.tangents) << "[GTEST]: ray::Mesh operator= test failed.";
    EXPECT_EQ(mesh.colors, anotherOne.colors) << "[GTEST]: ray::Mesh operator= test failed.";
    EXPECT_EQ(mesh.indices, anotherOne.indices) << "[GTEST]: ray::Mesh operator= test failed.";
    EXPECT_EQ(mesh.animVertices, anotherOne.animVertices) << "[GTEST]: ray::Mesh operator= test failed.";
    EXPECT_EQ(mesh.animNormals, anotherOne.animNormals) << "[GTEST]: ray::Mesh operator= test failed.";
    EXPECT_EQ(mesh.boneIds, anotherOne.boneIds) << "[GTEST]: ray::Mesh operator= test failed.";
    EXPECT_EQ(mesh.boneWeights, anotherOne.boneWeights) << "[GTEST]: ray::Mesh operator= test failed.";
    EXPECT_EQ(mesh.vaoId, anotherOne.vaoId) << "[GTEST]: ray::Mesh operator= test failed.";
    EXPECT_EQ(mesh.vboId, anotherOne.vboId) << "[GTEST]: ray::Mesh operator= test failed.";
}