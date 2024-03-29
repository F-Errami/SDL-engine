#pragma once
#ifndef SDL_ENGINE_SYSTEM_HPP
#define SDL_ENGINE_SYSTEM_HPP


#include "Entity.hpp"
#include "Component.hpp"
#include <typeinfo>
#include <set>

class System
{
public:
    std::set<Entity> Entities;

};

//--------------------------------------------------------------------------------------

class SystemManager
{
public:
    template<typename T>
    std::shared_ptr<T> RegisterSystem()
    {
        const char* typeName = typeid(T).name();

        assert(mSystems.find(typeName) == mSystems.end() && "Registering system more than once.");

        // Create a pointer to the system and return it so it can be used externally
        std::shared_ptr<T> system = std::make_shared<T>();
        mSystems.insert(make_pair(typeName,system));
        return system;
    }

    template<typename T>
    void SetSignature(Signature signature)
    {
        const char* typeName = typeid(T).name();

        assert(mSystems.find(typeName) != mSystems.end() && "System used before registered.");

        // Set the signature for this system
        mSignatures.insert(std::make_pair(typeName,signature));
    }

    void EntityDestroyed(Entity entity)
    {
        // Erase a destroyed entity from all system lists
        // mEntities is a set so no check needed
        for (auto const& pair : mSystems)
        {
            std::shared_ptr<System> const& system = pair.second;

            system->Entities.erase(entity);
        }
    }

    void EntitySignatureChanged(Entity entity, Signature entitySignature)
    {
        // Notify each system that an entity's signature changed
        for (auto const& pair : mSystems)
        {
            const char* const& type = pair.first;
            std::shared_ptr<System> const& system = pair.second;
            Signature const& systemSignature = mSignatures[type];

            // Entity signature matches system signature - insert into set
            if ((entitySignature & systemSignature) == systemSignature)
            {
                system->Entities.insert(entity);
            }
                // Entity signature does not match system signature - erase from set
            else
            {
                system->Entities.erase(entity);
            }
        }
    }

private:
    // Map from system type string pointer to a signature
    std::unordered_map<const char*, Signature> mSignatures;

    // Map from system type string pointer to a system pointer
    std::unordered_map<const char*, std::shared_ptr<System> > mSystems;
};
#endif //SDL_ENGINE_SYSTEM_HPP
