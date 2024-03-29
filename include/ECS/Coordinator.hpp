#pragma once
#ifndef SDL_ENGINE_COORDINATOR_HPP
#define SDL_ENGINE_COORDINATOR_HPP

#include "Entity.hpp"
#include"Component.hpp"
#include "System.hpp"

class Coordinator
        {
                public:

               Coordinator()
               {

               }
                void Init()
                {
                    // Create pointers to each manager
                    mComponentManager = std::make_shared<ComponentManager>();
                    mEntityManager = std::make_shared<EntityManager>();
                    mSystemManager = std::make_shared<SystemManager>();
                }


                // Entity methods
                Entity CreateEntity()
                {
                    return mEntityManager->CreateEntity();
                }

                void DestroyEntity(Entity entity)
                {
                    mEntityManager->DestroyEntity(entity);

                    mComponentManager->EntityDestroyed(entity);

                    mSystemManager->EntityDestroyed(entity);
                }


                // Component methods
                template<typename T>
                void RegisterComponent()
                {
                    mComponentManager->RegisterComponent<T>();
                }

                template<typename T>
                void AddComponent(Entity entity, T component)
                {
                    mComponentManager->AddComponent<T>(entity, component);

                    Signature signature = mEntityManager->GetSignature(entity);
                    signature.set(mComponentManager->GetComponentType<T>(), true);
                    mEntityManager->SetSignature(entity, signature);

                    mSystemManager->EntitySignatureChanged(entity, signature);
                }

                template<typename T>
                void RemoveComponent(Entity entity)
                {
                    mComponentManager->RemoveComponent<T>(entity);

                    Signature signature = mEntityManager->GetSignature(entity);
                    signature.set(mComponentManager->GetComponentType<T>(), false);
                    mEntityManager->SetSignature(entity, signature);

                    mSystemManager->EntitySignatureChanged(entity, signature);
                }

                template<typename T>
                T& GetComponent(Entity entity)
                {
                    return mComponentManager->GetComponent<T>(entity);
                }

                template<typename T>
                ComponentType GetComponentType()
                {
                    return mComponentManager->GetComponentType<T>();
                }


                // System methods
                template<typename T>
                std::shared_ptr<T> RegisterSystem()
                {
                    return mSystemManager->RegisterSystem<T>();
                }

                template<typename T>
                void SetSystemSignature(Signature signature)
                {
                    mSystemManager->SetSignature<T>(signature);
                }

                private:
                std::shared_ptr<ComponentManager> mComponentManager;
                std::shared_ptr<EntityManager> mEntityManager;
                std::shared_ptr<SystemManager> mSystemManager;
        };

#endif //SDL_ENGINE_COORDINATOR_HPP
