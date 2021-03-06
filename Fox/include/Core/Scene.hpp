/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Scene.hpp
*/

#ifndef FOX_SCENE_HPP_
#define FOX_SCENE_HPP_

#include <ColliderListener.hpp>
#include "Ecs/World.hpp"

namespace fox
{
    class Application;
}

namespace reactphysics3d
{
    class PhysicsCommon;
    class PhysicsWorld;
}

namespace fox
{
    class Scene
    {
    public:
        Scene();
        Scene(const std::string&);
        virtual ~Scene();

        /**
         * @brief Called when scene initially created. Called once.
         * @param app reference to the main application
         */
        virtual void on_create(Application& app) = 0;

        /**
         * @brief Called when scene destroyed. Called at most once (if a scene
         * is not removed from the game, this will never be called).
         * @param app reference to the main application
         */
        virtual void on_destroy(Application& app) = 0;

        /**
         * @brief Called whenever a scene is transitioned into. Can be
         * called many times in a typical game cycle.
         * @param app reference to the main application
         */
        virtual void on_enable(Application& app);

        /**
         * @brief This function called the on_enable function
         * @param app reference to the main application
         */
        void enable(Application& app);

        /**
         * @brief Called whenever a transition out of a scene occurs.
         * Can be called many times in a typical game cycle.
         * @param app reference to the main application
         */
        virtual void on_disable(Application& app);

        /**
         * @brief This function called the on_disable function
         * @param app reference to the main application
         */
        void disable(Application& app);

        /**
         * @brief Called every frame
         * @param app reference to the main application
         */
        virtual void on_update(Application& app) = 0;

        /**
         * @brief This function called the on_update function
         * @param app reference to the main application
         */
        void update(Application& app);

        /**
         * @brief Called every fix frame
         * @param app reference to the main application
         */
        void fix_update();

        /**
         * @brief Called to draw
         * @param app reference to the main application
         */
        void draw();

        /***
         * @brief Init the systems of the ecs
         */
        void init_systems();

        /***
         * @brief Destroy the systems of the ecs
         */
        void destroy_systems();

        /**
         * @brief Get the name of the scene
         * @return the name of the scene as a string
         */
        std::string name() const;

        /**
         * @brief Get the ECS World
         * @return ECS World
         */
        World& get_world();

        /**
         * @brief Get the physics world
         * @return the physics world
         */
        reactphysics3d::PhysicsWorld& get_world_physic();

        /**
         * @brief Get the common physics
         * @return common physics
         */
        reactphysics3d::PhysicsCommon& get_world_common();

    protected:
        World m_oWorld;
        scope<reactphysics3d::PhysicsCommon> m_PhysicsCommon;
        reactphysics3d::PhysicsWorld* m_World;
        Application* m_pApp;
        const float timeStep = 1.0f / 60.0f;
        ColliderListener m_oListener;
        bool m_bIsPaused = false;

    private:
        std::string m_strName;
    };
}
#endif /* !SCENE_HPP_ */
