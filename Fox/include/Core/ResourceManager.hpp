/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** ResourceManager.hpp
*/

#ifndef FOX_RESOURCE_MANAGER_HPP_
#define FOX_RESOURCE_MANAGER_HPP_

#include <string>
#include <memory>
#include <unordered_map>

namespace fox
{
	class ResourceManager;

	class IAssetManager
	{
	public:
		virtual ~IAssetManager() = 0;

        /**
         * @brief Add a new asset to this manager
         * @param strAssetPath the path of the asset (use to identify the asset like a Unique ID)
         * @return true if the asset is successfully added or false if the asset have been register twice
         */
		virtual bool Add(const std::string& strAssetPath) noexcept = 0;

        /**
         * @brief Get the asset match with the path given in parameter
         * @param strAssetPath the path of the asset
         * @return a pointer to the asset if it's exist otherwise it return nullptr
         */
		virtual void* Get(const std::string& strAssetPath) = 0;

        /**
         * @brief Remove a asset to the manager
         * @param strAssetPath the path of the asset
         * @return true if the asset is successfully removed or otherwise false
         */
		virtual bool Remove(const std::string& strAssetPath) noexcept = 0;
	};

	template <typename TAsset>
	class AAssetManager : public IAssetManager
	{
	public:
		AAssetManager(ResourceManager& oResourceManager) : m_oResourceManager(oResourceManager)
		{
		}
		virtual ~AAssetManager() = 0;
		virtual bool Add(const std::string& strAssetPath) noexcept = 0;
		virtual void* Get(const std::string& strAssetPath) = 0;
		virtual bool Remove(const std::string& strAssetPath) noexcept = 0;

		bool Exists(const std::string& strAssetPath) const
		{
			return m_vAssets.find(strAssetPath) != m_vAssets.end();
		}

	protected:
		ResourceManager& m_oResourceManager;

		using AssetPtr = std::unique_ptr<TAsset>;
		std::unordered_map<std::string, AssetPtr> m_vAssets;
	};

	class ResourceManager
	{
	public:
		using IAssetManagerPtr = std::unique_ptr<IAssetManager>;

	public:

        /**
         * @brief Add a new IAssetManager
         * @tparam T the type of the Asset (use to identify the manager)
         * @param pAssetManager the manager
         * @return true if the manager is successfully added or false if the manager have been register twice
         */
		template <typename T>
		bool AddManager(IAssetManager* pAssetManager) noexcept
		{
			std::size_t lHash = typeid(T).hash_code();
			if (m_vAssetManagers.find(lHash) == m_vAssetManagers.end())
			{
				m_vAssetManagers.emplace(lHash, IAssetManagerPtr(pAssetManager));
				return true;
			}
			return false;
		}

        /**
        * @brief Add a new Asset
        * @tparam T the type of the asset
        * @param strAssetPath the path of the asset (use to identify the asset like a Unique ID)
        * @return true if the asset is successfully added or false if the asset have been register twice
        */
		template <typename T>
		bool AddAsset(const std::string& strAssetPath) noexcept
		{
			std::size_t lHash = typeid(T).hash_code();
			if (m_vAssetManagers.find(lHash) != m_vAssetManagers.end())
				return m_vAssetManagers[lHash]->Add(strAssetPath);
			return false;
		}

        /**
         * @brief Get the asset match with the name given in parameter
         * @tparam TAsset the type of the asset
         * @param strAssetPath the path of the asset
         * @return a pointer to the asset if it's exist otherwise it return nullptr
         */
		template<typename TAsset>
		TAsset* GetAsset(const std::string& strAssetPath)
		{
			std::size_t lHash = typeid(TAsset).hash_code();
			if (m_vAssetManagers.find(lHash) != m_vAssetManagers.end())
				return static_cast<TAsset*>(m_vAssetManagers[lHash]->Get(strAssetPath));
			return nullptr;
		}

        /**
         * @brief Remove a asset to it manager
         * @tparam TAsset the type of the asset
         * @param strAssetPath the path of the asset
         * @return true if the asset is successfully removed or otherwise false
         */
		template<typename TAsset>
		bool RemoveAsset(const std::string& strAssetPath) noexcept
		{
			std::size_t lHash = typeid(TAsset).hash_code();
			if (m_vAssetManagers.find(lHash) != m_vAssetManagers.end())
				return m_vAssetManagers[lHash]->Remove(strAssetPath);
			return false;
		}

	private:
		std::unordered_map<std::size_t, IAssetManagerPtr> m_vAssetManagers;
	};
} // namespace Fox

#endif