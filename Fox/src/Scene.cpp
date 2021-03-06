/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Scene.cpp
*/

#include "Core/Scene.hpp"
#include "Components.hpp"
#include "raylib-cpp.hpp"
#include "Core/Application.hpp"
#include "Core/Input/Input.hpp"
#include <Components/RigidBody.hpp>
#include <reactphysics3d/reactphysics3d.h>
#include <Components/BoxCollider.hpp>
#include "raylib-cpp/Rectangle.hpp"
#include "raylib-cpp/InputBox.hpp"
#include "Components/NativeScript.hpp"

namespace fox
{
    Scene::Scene()
    {
        m_PhysicsCommon = new_scope<reactphysics3d::PhysicsCommon>();
        m_World = m_PhysicsCommon->createPhysicsWorld();
        m_World->setIsDebugRenderingEnabled(false);
    }

    Scene::Scene(const std::string& strName): m_strName(strName)
    {
        get_world().add_phase(game::OnStart);
        get_world().add_phase(game::CameraBegin);
        get_world().add_phase(game::CameraDraw);
        get_world().add_phase(ecs::OnSceneEnable);
        get_world().add_phase(ecs::OnSceneDisable);
        get_world().add_phase(ecs::PostFixUpdate);
        get_world().add_phase(ecs::PreFixUpdate);
        get_world().add_phase(ecs::OnNativeScriptInit);

        m_PhysicsCommon = new_scope<reactphysics3d::PhysicsCommon>();
        m_World = m_PhysicsCommon->createPhysicsWorld();
        m_World->setEventListener(&m_oListener);
    }

    Scene::~Scene() { }

    void Scene::enable(Application& app)
    {
        m_pApp = &app;
        on_enable(app);
        m_oWorld.run_phase(game::OnStart);
    }
    void Scene::on_enable(Application& app) { }

    void Scene::disable(Application& app)
    {
        on_disable(app);

        if (!m_bIsPaused)
            get_world().clear_entities();
    }
    void Scene::on_disable(Application& app) { }

    void Scene::update(Application& app)
    {
        m_oWorld.run_phase(ecs::PreUpdate);
        on_update(app);
        m_oWorld.run_phase(ecs::OnUpdate);
        m_oWorld.run_phase(ecs::OnValidate);
        m_oWorld.run_phase(ecs::PostUpdate);
        m_oWorld.run_phase(ecs::PreStore);
        m_oWorld.deleted_entities();
    }

    void Scene::fix_update()
    {
        m_oWorld.run_phase(ecs::PreFixUpdate);
        m_World->update(timeStep);
        m_oWorld.run_phase(ecs::PostFixUpdate);
    }

    void Scene::draw()
    {
        m_oWorld.run_phase(game::CameraBegin);
        m_oWorld.run_phase(ecs::OnStore);
    }

    void Scene::init_systems()
    {
        get_world().system<NativeScript>().kind(ecs::OnUpdate)
                .force_update(true)
                .each([](Entity e, NativeScript& script)
                      {
                          script.m_pInstance->on_update();
                      });
        get_world().system<NativeScript>().kind(ecs::OnRemove)
                .each([](Entity e, NativeScript& script)
                      {
                          script.m_pInstance->on_destroy();
                          script.DestroyScript(&script);
                      });
        get_world().system<NativeScript>().kind(ecs::OnAdd)
                .each([this](Entity e, NativeScript& script)
                      {
                          script.m_pWorld = e.get_world();
                          script.m_Id = e.get_id();
                      });

        get_world().system<NativeScript>().kind(ecs::OnNativeScriptInit)
                .each([this](Entity e, NativeScript& script)
                      {
                          if (!script.m_pInstance) {
                              script.m_pInstance = script.InstantiateScript();
                              assert(script.m_pInstance);
                              script.m_pInstance->set_entity(e.get_id());
                              script.m_pInstance->set_world(*e.get_world());
                              script.m_pInstance->set_scene(*this);
                              script.m_pInstance->set_app(*m_pApp);
                              script.m_pInstance->on_create();
                          }
                      });
        get_world().system<NativeScript, BoxCollider>()
                .kind(ecs::OnAdd)
                .each([](Entity e, NativeScript& script, BoxCollider& shape)
                      {
                          shape.m_pScript = &script;
                      });
        get_world().system<BoxCollider>()
                .kind(ecs::OnAdd)
                .each([](Entity e, BoxCollider& shape)
                      {
                          shape.entity = e.get_id();
                      });

        get_world().system<Animator>().each([](Entity e, Animator& anim) { anim.run(); });

        get_world().system<fox::Button, Animator>().each([](Entity e, fox::Button& btn, Animator& anim)
        {
            if (btn.state() == btn.prev_state())
                return;
            switch (btn.state())
            {
                case fox::BtnState::NORMAL:
                    anim.switch_to("Normal");
                    break;
                case fox::BtnState::HOVER:
                    anim.switch_to("Hover");
                    break;
                case fox::BtnState::PRESSED:
                    anim.switch_to("Pressed");
                    break;
                case fox::BtnState::DISABLE:
                    anim.switch_to("Disable");
                    break;
                default:
                    anim.switch_to("Normal");
                    break;
            }
        });

        get_world().system<fox::Transform>().kind(fox::ecs::PreUpdate)
            .each([](Entity e, fox::Transform& transform)
        {
            transform.update_position();
        });

        get_world().system<ray::Model, fox::Transform>().kind(fox::game::CameraDraw)
            .each([](Entity e, ray::Model& model, fox::Transform& transform)
        {
            model.Draw(transform.position, transform.rotation.normalized().getAxis(), 0, transform.scale);
        });

        get_world().system<ray::Camera3D>().kind(fox::game::CameraBegin)
            .each([](Entity e, ray::Camera3D& camera)
        {
            // camera.Update();
            camera.BeginMode();
            e.get_world()->run_phase(fox::game::CameraDraw);
            camera.EndMode();
        });

        get_world().system<ray::Cube, fox::Transform>().kind(fox::game::CameraDraw)
            .each([](Entity e, ray::Cube& cube, fox::Transform& transform)
        {
            cube.Draw(transform.position, transform.scale);
        });

        get_world().system<ray::Texture, fox::Transform>().kind(fox::ecs::OnStore)
            .each([](Entity e, ray::Texture& texture, fox::Transform& transform)
                  {
                      ray::Rectangle sourceRec = { 0.0f, 0.0f, (float)texture.width, (float)texture.height };
                      ray::Rectangle destRec = { transform.position.x, transform.position.y, texture.width * transform.scale.x, texture.height * transform.scale.y };
                      texture.Draw(sourceRec, destRec, Vec2(), transform.rotation.GetAngle());
                  });

        get_world().system<ray::Rectangle, fox::Transform>().kind(fox::ecs::PreStore)
            .each([](Entity e, ray::Rectangle& rec, fox::Transform& transform)
        {
            rec.SetPosition(transform.position.x, transform.position.y);
        });

        get_world().system<ray::Rectangle>().kind(fox::ecs::OnStore)
                .each([](Entity e, ray::Rectangle& rec)
                      {
                        rec.Draw();
                      });

        get_world().system<fox::Button, fox::Transform>().kind(ecs::OnStore)
            .each([](Entity e, fox::Button& btn, fox::Transform& transform)
        {
            ray::Rectangle sourceRec = { 0.0f, 0.0f, (float)btn.sprite().width, (float)btn.sprite().height };
            ray::Rectangle destRec = { transform.position.x, transform.position.y, btn.sprite().width * transform.scale.x, btn.sprite().height * transform.scale.y };
            bool btnClick = false;
            if (CheckCollisionPointRec(fox::Input::mouse_pos(), destRec))
            {
                btn.set_state(fox::BtnState::HOVER);
                if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
                    btnClick = true;
            } else {
                btn.set_state(fox::BtnState::NORMAL);
            }

            if (btnClick)
            {
                btn.click();
                btn.set_state(fox::BtnState::PRESSED);
            }
            btn.sprite().Draw(sourceRec, destRec, Vec2(), transform.rotation.GetAngle());
        });

        get_world().system<fox::Image, fox::Transform>().kind(ecs::OnStore)
            .each([](Entity e, fox::Image& img, fox::Transform& transform)
                  {
                      ray::Rectangle sourceRec = { 0.0f, 0.0f, (float)img.sprite().width, (float)img.sprite().height };
                      ray::Rectangle destRec = { transform.position.x, transform.position.y, img.sprite().width * transform.scale.x, img.sprite().height * transform.scale.y };
                      img.sprite().Draw(sourceRec, destRec, Vec2(), transform.rotation.GetAngle());
                  });

        get_world().system<ray::Text, fox::Transform>().kind(fox::ecs::OnStore)
            .each([](Entity e, ray::Text& text, fox::Transform& transform)
        {
            text.Draw(transform.position.x, transform.position.y);
        });

        get_world()
                .system<RigidBody, fox::Transform>()
                .kind(fox::ecs::PreFixUpdate)
                .each([&](
                        Entity e, RigidBody &body,
                        fox::Transform &transform)
                      {
                          body.get_rb()->setTransform(transform);
                      });
        get_world()
                .system<RigidBody, fox::Transform>()
                .kind(fox::ecs::PostFixUpdate)
                .each([&](
                        Entity e, RigidBody &body,
                        fox::Transform &transform)
                      {
                          const reactphysics3d::Transform &qTrans =
                                  body.get_rb()->getTransform();
                          transform.position =
                                  Vec3(qTrans.getPosition().x, qTrans.getPosition().y,
                                       qTrans.getPosition().z);
                      });

        get_world().system<RigidBody, BoxCollider, fox::Transform>()
                .kind(ecs::OnAdd)
                .each([](Entity e, RigidBody& body, BoxCollider& shape, fox::Transform& transform)
                      {
                          reactphysics3d::Vector3 v = shape.getReactShape()->getHalfExtents();
                          fox::Transform trans = fox::Transform();
                          trans.scale = Vec3(v.x * (transform.scale.x * .5f), v.y * (transform.scale.y * .5f), v.z * (transform.scale.z * .5f));
                          shape.getReactShape()->setHalfExtents(shape.getHalfExtents() * trans.scale);
                          auto f = body.get_rb()->addCollider(shape.getReactShape(), trans);
                          f->getMaterial().setBounciness(0);
                          shape.set_collider(f);
                          // f->getMaterial().setFrictionCoefficient(0);
                          // f->getMaterial().setMassDensity(0);
                          // f->getMaterial().setRollingResistance(0);
                          f->setUserData(&shape);
                      });
        get_world().system<RigidBody, BoxCollider>()
                .kind(ecs::OnRemove)
                .each([](Entity e, RigidBody& body, BoxCollider& shape)
                      {
                          body.get_rb()->removeCollider(shape.get_collider());
                      });

        get_world().system<ray::InputBox, fox::Transform>().kind(ecs::OnStore)
            .each([](Entity e, ray::InputBox& box, fox::Transform& transform)
                  {
                      box.Draw();
                  });
    }

    World& Scene::get_world()
    {
        return m_oWorld;
    }

    void Scene::destroy_systems()
    {
    }

    std::string Scene::name() const
    {
        return m_strName;
    }

    reactphysics3d::PhysicsWorld &Scene::get_world_physic()
    {
        return *m_World;
    }

    reactphysics3d::PhysicsCommon &Scene::get_world_common()
    {
        return *m_PhysicsCommon;
    }

}// namespace fox