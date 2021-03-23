#pragma once

#ifndef SDL_ENGINE_ECS_HPP
#define SDL_ENGINE_ECS_HPP

#include <iostrem>
#include <memory>
#include <bitset>
#include <algorithm>
#include <array>
#include <vector>


class Component;
class Entity;

using  ComponentID = std::size_t;
inline ComponentID getComponenetID()
{
    static ComponentID lastID = 0;
    return lastID++;
}

template <typename T> inline ComponentID getComponentID()
{
    static ComponenentID typeID =getComponentID();
    return typeID;
}

constexpr std::size_t maxComponents =32;
using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std:array<Component*,maxComponent>;

class Component
{
public:
  Entity* entity;

  virtual void init(){};
  virtual void update(){};
  virtual void draw();

  virtual ~Component();

};

class Entity
{
private:
    bool active =true;
    std::vector<std::unique_ptr<Component>> components;
    ComponentArray componentArray;
    ComponentBitSet componentBitSet;

public:

    void update()
    {
        for (auto& c:components)  c->update();

        for (auto& c:components)  c->draw();
    }

    void draw(){}
    bool isActive() {return active;}
    void destroy() { active= false;}

    template<typeName T> bool hasComponent() const
    {
        componentBitSet[getComponentID<T>];
    }

    template <typename T,typename... TArgs>

};

#endif //SDL_ENGINE_ECS_HPP
