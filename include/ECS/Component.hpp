#pragma once
#ifndef SDL_ENGINE_COMPONENT_HPP
#define SDL_ENGINE_COMPONENT_HPP

#include "Entity.hpp"
#include <unordered_map>
#include <typeinfo>
#include <memory>


class IComponentArray
{
    ~IComponentArray();
    virtual void EntityDestroyed(Entity entity)
};

//--------------------------------------------------------------------------------------
template <typename T>
class ComponentArray :public IComponentArray
{
public:
void InsertData(Entity entity,T component)
{
    assert(mEntityToIndexMap.find(entity) == mEntityToIndexMap.end() && "Component added to same entity more than once.");
    //we insert the component at the last of the array
    size_t newIndex = size;
    EntityToIndexMap[entity] = newIndex;
    IndexToEntity[newIndex] = entity;
    componentArray[newIndex] = component;
    ++size;
}

void removeData(Entity entity)
{
    assert(mEntityToIndexMap.find(entity) != mEntityToIndexMap.end() && "Removing non-existent component.");

    //we put the component of the entity at the last of the array
    size_t indexOfRemovedEntity = EntityToIndexMap[entity];
    size_t indexOfLastEntity = size-1;
    componentArray[indexOfRemovedEntity] = componentArray[indexOfLastEntity];

// we just change the index of the last entity with the index of the removed one
    Entity lastEntity = IndexToEntityMap[indexOfLastEntity];
    IndexToEntityMap[indexOfRemovedEntity] = lastEntity;
    EntityToIndexMap[lastEntity]=indexOfRemovedEntity;
//we delete the last entity
    EntityToIndexMap.erase(entity);
    IndexToEntityMap.erase(indexOfLastEntity);

    --size;


}

T& getData(Entity entity)
{
    assert(EntityToIndexMap.find(entity) != EntityToIndexMap.end() && "Retrieving non-existent component.");

    return componentArray[EntityToIndexMap[entity]];
}

void EntityDestroyed(Entity entity) override
    {
        if (EntityToIndexMap.find(entity) != EntityToIndexMap.end())
        {
            // Remove the entity's component if it existed
            RemoveData(entity);
        }
    }

private:
    //an array of components with the time
    //each entity has her own component
    std::array <T,MAX_ENTITY> componentArray;


//it allows us to know the index of an entity in the componentArray
//so that we can know the data of an entity by just knowing her id
    std::unordere_map<Entity,size_t> EntityToIndexMap;

//it allows us to know the Entity of a component in the componentArray
//so that we can know an entity  by just knowing the index of her component
    std::unordered_map <size_t, Entity> IndexToEntityMap;


//total of valid entries in the array
    size_t size;


};
//--------------------------------------------------------------------------------------
class ComponentManager
{
public:
void RegisterComponent()
{
    const char* typeName = typeid(T).name();
    assert(componentTypes.find(typeName) == componentTypes.end() && "Registering component type more than once.");

    // Add this component type to the component type map
    componentTypes.insert({typeName, NextComponentType});

    // Create a ComponentArray pointer and add it to the component arrays map
    componentArrays.insert({typeName, std::make_shared<ComponentArray<T>>()});

    // Increment the value so that the next component registered will be different
    ++NextComponentType;

}

    template<typename T>
    ComponentType GetComponentType()
    {
        const char* typeName = typeid(T).name();

        assert(mComponentTypes.find(typeName) != mComponentTypes.end() && "Component not registered before use.");

        // Return this component's type - used for creating signatures
        return componentTypes[typeName];
    }

    template<typename T>
    void AddComponent(Entity entity, T component)
    {
        // Add a component to the array for an entity
        GetComponentArray<T>()->InsertData(entity, component);
    }

    template<typename T>
    void RemoveComponent(Entity entity)
    {
        // Remove a component from the array for an entity
        GetComponentArray<T>()->RemoveData(entity);
    }

    template<typename T>
    T& GetComponent(Entity entity)
    {
        // Get a reference to a component from the array for an entity
        return GetComponentArray<T>()->GetData(entity);
    }

    void EntityDestroyed(Entity entity)
    {
        // Notify each component array that an entity has been destroyed
        // If it has a component for that entity, it will remove it
        for (auto const& pair : componentArrays)
        {
            auto const& component = pair.second;

            component->EntityDestroyed(entity);
        }
    }


private:
    std::unordered_map<const char*,ComponentType> componentTypes;

    std::unordered_map<const char*,std::shared_ptr<IComponentArray> > componentArrays;

    ComponentType NextComponentType;


    template<typename T>
    std::shared_ptr<ComponentArray<T> > GetComponentArray()
    {
        const char* typeName = typeid(T).name();

        assert(componentTypes.find(typeName) != componentTypes.end() && "Component not registered before use.");

        return std::static_pointer_cast<ComponentArray<T> >(componentArrays[typeName]);
    }
};


#endif //SDL_ENGINE_COMPONENT_HPP
