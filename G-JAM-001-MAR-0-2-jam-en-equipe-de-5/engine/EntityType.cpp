/*
** EPITECH PROJECT, 2020
** G-JAM-001-MAR-0-2-jam-killian.moudery
** File description:
** EntityType.cpp
*/
#include "EntityType.hpp"
#include "Engine.hpp"
#include "GraphicEngine.hpp"

template <class T>
EntityType<T>::EntityType(float radius) : radius(radius)
{
    Engine::instance->addEntityType(this);
    GraphicEngine::instance->addEntityType(this);
}

template <class T>
EntityType<T>::~EntityType()
{
    Engine::instance->removeEntityType(this);
    GraphicEngine::instance->removeEntityType(this);
}

template class EntityType<Entity>;
