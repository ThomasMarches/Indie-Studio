/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** NativeScript.hpp
*/

#ifndef ECS_NATIVESCRIPT_HPP
#define ECS_NATIVESCRIPT_HPP

#include "../ScriptableBehaviour.hpp"

struct NativeScript
{
    ScriptableBehaviour* m_pInstance = nullptr;

    // ScriptableBehaviour* (*InstantiateScript)() = nullptr;
    std::function<ScriptableBehaviour*()> InstantiateScript;
    void (*DestroyScript)(NativeScript*) = nullptr;

    EntityId m_Id;
    fox::World* m_pWorld;

    /**
     * @brief Constructor
     */
    NativeScript()
    {
    }

    ~NativeScript()
    {
        if (m_pInstance)
            delete m_pInstance;
    }

    /**
     * @brief Bind a ScriptableBehaviour
     * @tparam T The type of the ScriptableBehaviour
     */
    template <typename T>
    void bind()
    {
        InstantiateScript = []()
        {
            return static_cast<ScriptableBehaviour*>(new T());
        };
        DestroyScript = [](NativeScript* pScript)
        {
            delete pScript->m_pInstance;
            pScript->m_pInstance =  nullptr;
        };
        m_pWorld->run_phase(fox::ecs::OnNativeScriptInit);
    }

    /**
     * @brief Bind a ScriptableBehaviour
     * @tparam T The type of the ScriptableBehaviour
     * @tparam Args the arguments types for the constructor of the ScriptableBehaviour
     * @param args the arguments for the constructor of the ScriptableBehaviour
     */
    template <typename T, typename... Args>
    void bind(Args&&... args)
    {
        InstantiateScript = [&]()
        {
            return static_cast<ScriptableBehaviour*>(new T(std::forward<Args>(args)...));
        };
        DestroyScript = [](NativeScript* pScript)
        {
            delete pScript->m_pInstance;
            pScript->m_pInstance =  nullptr;
        };
        m_pWorld->run_phase(fox::ecs::OnNativeScriptInit);
    }

    /**
     * @brief Check if this script is the same type as T
     * @tparam T the type of the script to check
     * @return true if the script type is same otherwise false
     */
    template<typename T>
    bool is()
    {
        return dynamic_cast<T*>(m_pInstance) != nullptr;
    }

    /**
     * @brief Get the script object
     * @tparam T the type of the script
     * @return a pointer to the script object
     */
    template<typename T>
    T* get()
    {
        return dynamic_cast<T*>(m_pInstance);
    }
};

#endif //ECS_NATIVESCRIPT_HPP
