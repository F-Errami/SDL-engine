#pragma once
#ifndef SDL_ENGINE_ENTITY_HPP
#define SDL_ENGINE_ENTITY_HPP
#include <iostream>
#include <bitset>
#include <queue>
#include <array>

//an Entity is just an ID
using Entity = uint32_t;
const Entity MAX_ENTITY = 5000;
using ComponentType = size_t;
cont ComponentType MAX_COMPONENT=32;
using Signature = std::bitset <MAX_COMPONENT>;

class EntityManager
{
public:
    EntityManager()
    {
        for (Entity entity = 0; entity < MAX_ENTITY; ++i)
        {
            availableEntities.push(entity);
        }
        livingEntity = 0;
    }

    Entity createEntity()
    {  assert(nbLivingEntity < MAX_ENTITIES && "Too many entities in existence.");
        id = availableEntities.front();
        availableEntities.pop();
        ++nbLivingEntity;

        return id;
    }

    void DestroyEntity(Entity entity)
    {
        assert(entity < MAX_ENTITIES && "Entity out of range.");
        availableEntities.push(entity);
        signatures[entity].resest();
        --nbLivingEntity;
    }

    void setSignatures( Entity entity, Signature signature)
    {
        assert(entity < MAX_ENTITIES && "Entity out of range.");
        signatures[entity] = signature;
    }

   Signature getSigmature(Entity entity)
    {
        assert(entity < MAX_ENTITIES && "Entity out of range.");
        return signatures[entity];
    }


private:
    //entity that are available
    std::queue<Entity> availableEntities;
    //an array of the signature of each entity where the index is the entity
    std::array<Signature,MAX_ENTITY> signatures;
    //the number of entity that are created
    uint32_t nbLivingEntity;


};


#endif //SDL_ENGINE_ENTITY_HPP
