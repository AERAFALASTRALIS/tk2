/*
** EPITECH PROJECT, 2020
** G-JAM-001-MAR-0-2-jam-killian.moudery
** File description:
** EntityType.hpp
*/

#ifndef ENTITYTYPE_HPP_
#define ENTITYTYPE_HPP_

#include <string>
#include <memory>
#include <list>
#include "tools/SafeQueue.hpp"
#include "Entity.hpp"
#include "tools/Save.hpp"
#include "tools/DataPack.hpp"

class Engine;
class GraphicEngine;

template <class T>
class EntityType {
public:
    EntityType(float radius);
    virtual ~EntityType();
    EntityType(const EntityType &cpy) = default;
    EntityType &operator=(const EntityType &src) = default;

    void insert(std::shared_ptr<T> entity) {
        physicQueue.pushCpy(entity);
        graphicQueue.pushCpy(entity);
    }
    template <class T2>
    void collideAll(std::shared_ptr<EntityType<T2>> &t2, const float radius, void (*func)(Entity &, Entity &)) {
        for (auto &target : t2->entities) {
            const float x2 = target->refX;
            const float y2 = target->refY;
            for (auto &self : entities) {
                const float x = x2 - self->refX;
                const float y = y2 - self->refY;
                if (x * x + y * y < radius)
                    func(*self, *target);
            }
        }
    }
    void updateAll() {
        for (auto &e : entities) {
            e->internalUpdate();
        }
        entities.remove_if([](auto &e){
            return (!e->isAlive());
        });
        std::shared_ptr<T> tmp;
        while (physicQueue.pop(tmp)) {
            entities.push_back(tmp);
        }
    }
    void drawAll() {
        for (auto &e : graphicEntities) {
            e->update();
            e->draw();
        }
        graphicEntities.remove_if([](auto &e){
            return (!e->isAlive());
        });
        std::shared_ptr<T> tmp;
        while (graphicQueue.pop(tmp)) {
            graphicEntities.push_back(tmp);
        }
    }
    float getRadius() const {return radius;}
    template <typename Etype, typename Edata = EntityData>
    void loadAll(Save &save, const std::string &entry) {
        DataPack<Edata> pack(save[entry]);
        Edata dat;
        while (pack.pop(dat)) {
            auto tmp = Etype::load(dat);
            entities.push_back(tmp);
            graphicEntities.push_back(tmp);
        }
    }
    template <typename Etype, typename Edata = EntityData>
    void saveAll(Save &save, const std::string &entry) {
        save[entry].clear();
        DataPack<Edata> pack(save[entry]);
        for (auto &e : entities) {
            pack.push(dynamic_cast<Etype *>(e.get())->save());
        }
    }
private:
    const float radius;
    SafeQueue<std::shared_ptr<T>> physicQueue;
    SafeQueue<std::shared_ptr<T>> graphicQueue;
    std::list<std::shared_ptr<T>> entities;
    std::list<std::shared_ptr<T>> graphicEntities;
};

#endif /* ENTITYTYPE_HPP_ */
