/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Application.hpp
*/

#ifndef FOX_APP_HPP_
#define FOX_APP_HPP_

#include <Core/Audio/AudioManager.hpp>
#include "FoxEcs.hpp"
#include "SceneManager.hpp"
#include "ResourceManager.hpp"
#include "Core.hpp"
#include "raylib-cpp.hpp"
#include "PlayerManager.hpp"
#include "SaveManager.hpp"
namespace fox
{
    class Application
    {
    public:
        /**
         * @brief Contructor of the class
         * @param ac arguments count
         * @param av arguments
         */
        Application(int ac, char** av);
        virtual ~Application();

        /**
         * @brief Initialize the application
         */
        virtual void init();

        /**
         * @brief Run the application
         */
        void run();

        /**
         * @brief QUi the application
         */
        void quit();


        // ---------------------------------------------------------------------


        // -------- Resource Manager ----------------------------------

        /**
         * @brief Add a new IAssetManager
         * @tparam T the type of the Asset (use to identify the manager)
         * @param pAssetManager the manager
         * @return true if the manager is successfully added or false if the manager have been register twice
         */
        template <typename T>
		bool add_manager(IAssetManager* pAssetManager) noexcept
		{
			return m_pResourceManager->AddManager<T>(pAssetManager);
		}

        /**
         * @brief Add a new Asset
         * @tparam T the type of the asset
         * @param strAssetPath the path of the asset (use to identify the asset like a Unique ID)
         * @return true if the asset is successfully added or false if the asset have been register twice
         */
		template <typename T>
		bool add_asset(const std::string& strAssetPath) noexcept
		{
			return m_pResourceManager->AddAsset<T>(strAssetPath);
		}

        /**
         * @brief Get the asset match with the path given in parameter
         * @tparam TAsset the type of the asset
         * @param strAssetPath the path of the asset
         * @return a pointer to the asset if it's exist otherwise it return nullptr
         */
		template<typename TAsset>
		TAsset* get_asset(const std::string& strAssetPath)
		{
			return m_pResourceManager->GetAsset<TAsset>(strAssetPath);
		}

        /**
         * @brief Remove a asset to it manager
         * @tparam TAsset the type of the asset
         * @param strAssetPath the path of the asset
         * @return true if the asset is successfully removed or otherwise false
         */
		template<typename TAsset>
		bool remove_asset(const std::string& strAssetPath) noexcept
		{
			return m_pResourceManager->RemoveAsset<TAsset>(strAssetPath);
		}

        /**
         * @brief Get the resource manager
         * @return a reference to the resource manager
         */
        ResourceManager& get_resource_manager() const
        {
            return *m_pResourceManager;
        }

        /**
         * @brief Get the save manager
         * @return a reference to the save manager
         */
        SaveManager& get_save_manager() const
        {
            return *m_pSaveManager;
        }
        // ---------------------------------------------------------------------

        /**
         * @brief Add a new scene
         * @tparam T the class of the scene
         * @tparam Args the constructor arguments types
         * @param args the constructor arguments
         */
        template<typename T, typename... Args,
                std::enable_if_t<std::is_base_of<Scene, T>::value, bool> = true>
        void add_scene(Args&&... args)
        {
            m_pSceneManager->add<T>(args...);
        }

        /**
         * @brief Remove a scene
         * @param name the name of the scene to be removed
         */
        void remove_scene(const std::string &name);

        /**
         * @brief Transitions to scene with specified name
         * @param name the name of the new scene
         */
        void switch_to(const std::string& name);

        /**
         * @brief Get the current scene
         * @return the current scene
         */
        Scene* get_active();

        // --------------------------------------------------------------------

        /**
         * @brief Add a new @AudioGroup
         * @param name the name of the new audio group
         */
        void CreateGroup(const std::string &name);

        /**
         * @brief Get the audio group using the name
         * @param name the name to be search
         * @return a reference to the audio group or throw an exception if not found
         */
        AudioGroup &getGroup(const std::string &name);

        /**
         * @brief Play a sound
         * @param group the name of the group
         * @param asset the path to the sound file
         * @param volume the value of the volume between 0 and 1
         * @param pitch the value of the pitch between 0 and 1
         */
        void PlaySound(const std::string& group, const std::string& asset, float volume = 1, float pitch = 1);

        /**
         * @brief Play a music
         * @param group the name of the group
         * @param asset the path to the sound file
         * @param volume the value of the volume between 0 and 1
         * @param pitch the value of the pitch between 0 and 1
         */
        void PlayMusic(const std::string& group, const std::string& asset, float volume = 1, float pitch = 1);

        /**
         * @brief Stop a sound
         * @param asset the path to the sound file
         */
        void StopSound(const std::string &asset);

        // --------------------------------------------------------------------

        /**
         * @brief Get the Player Manager
         * @return the ref of the Player Manager
         */
        PlayerManager& get_player_manager() const
        {
            return *m_pPlayerManager;
        }

        bool m_bIsRunning;
    private:

    protected:
        scope<ResourceManager> m_pResourceManager;
        scope<SceneManager> m_pSceneManager;
        scope<AudioManager> m_pAudioManager;
        scope<PlayerManager> m_pPlayerManager;
        scope<SaveManager> m_pSaveManager;
    };
}

#endif
