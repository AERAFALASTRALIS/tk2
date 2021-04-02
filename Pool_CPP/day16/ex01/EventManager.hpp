/*
** EPITECH PROJECT, 2021
** evenman
** File description:
** eventman
*/

#ifndef EVENTMANAGER_HPP_
#define EVENTMANAGER_HPP_

#include <iostream>
#include <list>
#include "Event.hpp"

class EventManager {
public:
  EventManager();
  ~EventManager();
  EventManager(EventManager const& other);
  EventManager& operator=(EventManager const& rhs);
  void addEvent(const Event& e);
  void removeEventsAt(unsigned int time);
  void dumpEvents() const;
  void dumpEventAt(unsigned int time) const;
  void addTime(unsigned int time);
  void addEventList(std::list<Event>& list);
  static bool _listSort(Event const& e1, Event const& e2);
private:
  std::list<Event> _list;
  unsigned int _time;
};

#endif
