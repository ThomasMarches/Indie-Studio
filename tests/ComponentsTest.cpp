/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** ComponentsTest.cpp
*/

#include <gtest/gtest.h>
#include "../Fox/include/Components/Button.hpp"
#include "../Fox/include/Components/Transform.hpp"
#include "../Fox/include/Components/EntityName.hpp"
#include "../Fox/include/Components/Image.hpp"
#include "../Fox/include/Utils/Quat.hpp"

TEST(TransformComponent, ConstructorTest)
{
    quat q = quat(2, 2, 2, 2);
    fox::Transform comp = fox::Transform(Vec3(1, 1, 1), q, Vec3(1, 1, 1));

    EXPECT_EQ(comp.position, Vec3(1, 1, 1)) << "[GTEST]: fox::Transform constructor test failed.";
    EXPECT_EQ(comp.scale, Vec3(1, 1, 1)) << "[GTEST]: fox::Transform constructor test failed.";
    EXPECT_EQ(comp.rotation, q) << "[GTEST]: fox::Transform constructor test failed.";

}

TEST(TransformComponent, SetPositionTest)
{
    fox::Transform comp1;

    comp1.set_pos(Vec3(20, 20, 20));
    EXPECT_EQ(comp1.get_pos(), Vec3(20, 20, 20)) << "[GTEST]: fox::Transform component set_pos() & get_pos() test failed.";
    comp1.set_pos(10, 10, 10);
    EXPECT_EQ(comp1.get_pos(), Vec3(10, 10, 10)) << "[GTEST]: fox::Transform component set_pos() & get_pos() test failed.";
}

TEST(TransformComponent, SetPositionWithParentTest)
{
    quat q = quat(2, 2, 2, 2);
    fox::Transform comp2 = fox::Transform(Vec3(1, 1, 1), q, Vec3(1, 1, 1));
    fox::Transform parent = fox::Transform(Vec3(2, 2, 2));

    comp2.set_parent(parent);
    comp2.set_pos(Vec3(20, 20, 20));
    EXPECT_EQ(comp2.local_position, Vec3(20, 20, 20)) << "[GTEST]: fox::Transform component set_pos() & get_pos() test failed.";
    comp2.set_pos(10, 10, 10);
    EXPECT_EQ(comp2.local_position, Vec3(10, 10, 10)) << "[GTEST]: fox::Transform component set_pos() & get_pos() test failed.";
    EXPECT_EQ(comp2.get_pos(), Vec3(2, 2, 2)) << "[GTEST]: fox::Transform component set_pos() & get_pos() test failed.";
}

TEST(TransformComponent, SetParentTest)
{
    quat q = quat(2, 2, 2, 2);
    fox::Transform comp = fox::Transform(Vec3(1, 1, 1), q, Vec3(1, 1, 1));
    fox::Transform parent = fox::Transform(Vec3(2, 2, 2));

    comp.set_parent(parent);
    EXPECT_EQ(comp.get_parent().get_pos(), parent.get_pos()) << "[GTEST]: fox::Transform set_parent() test failed.";
    EXPECT_EQ(comp.get_parent().get_rot(), parent.get_rot()) << "[GTEST]: fox::Transform set_parent() test failed.";
    EXPECT_EQ(comp.get_parent().get_rot(), parent.get_rot()) << "[GTEST]: fox::Transform set_parent() test failed.";
}

TEST(TransformComponent, UpdatePositionTest)
{
    fox::Transform comp2 = fox::Transform(Vec3(1, 1, 1));
    fox::Transform parent = fox::Transform(Vec3(2, 2, 2));

    comp2.parent = &parent;
    comp2.update_position();
    EXPECT_EQ(comp2.get_pos(), Vec3(2, 2, 2)) << "[GTEST]: fox::Transform component update_position() test failed.";
}


TEST(EntityNameTest, GetTest)
{
    fox::EntityName name = fox::EntityName("Player");

    EXPECT_EQ(name.get(), "Player") << "[GTEST]: fox::EntityName component get() test failed.";
}

TEST(EntityTagTest, GetTest)
{
    fox::EntityTag tag = fox::EntityTag("Player");

    EXPECT_EQ(tag.get(), "Player") << "[GTEST]: fox::EntityTag component get() test failed.";
}