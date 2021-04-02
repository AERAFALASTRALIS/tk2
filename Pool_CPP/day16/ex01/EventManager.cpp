/*
** EPITECH PROJECT, 2021
** eventman
** File description:
** eventman
*/

#include "EventManager.hpp"

EventManager::EventManager() : _list(), _time(0)
{
}

EventManager::~EventManager()
{
}

EventManager::EventManager(EventManager const& other) : _list(other._list), _time(other._time)
{
}

EventManager& EventManager::operator=(EventManager const& rhs)
{
  this->_list = rhs._list;
  this->_time = rhs._time;
  return (*this);
}

void EventManager::addEvent(const Event& e)
{
  if (e.getTime() < this->_time)
    return;
  this->_list.push_back(e);
  this->_list.sort(EventManager::_listSort);
}

void EventManager::removeEventsAt(unsigned int time)
{
  std::list<Event>::iterator i = this->_list.begin();
  while (i != this->_list.end())
  {
    if ((*i).getTime() == time)
      this->_list.erase(++i);
    else
      ++i;
  }
}

void EventManager::dumpEvents(void) const
{
  std::list<Event>::const_iterator i = this->_list.begin();
  while (i != this->_list.end())
  {
    std::cout << (*i).getTime() << ": " << (*i).getEvent() << '\n';
    ++i;
  }
}

void EventManager::dumpEventAt(unsigned int time) const
{
  std::list<Event>::const_iterator i = this->_list.begin();
  while (i != this->_list.end())
  {
    if ((*i).getTime() == time)
      std::cout << (*i).getTime() << ": " << (*i).getEvent() << '\n';
    ++i;
  }
}

void EventManager::addTime(unsigned int time)
{
  this->_time += time;
  std::list<Event>::const_iterator i = this->_list.begin();
  while (i != this->_list.end())
  {
    if ((*i).getTime() <= this->_time)
    {
      std::cout << (*i).getEvent() << '\n';
      this->_list.erase(++i);
    }
    else
      ++i;
  }
}

void EventManager::addEventList(std::list<Event>& list)
{
  std::list<Event>::const_iterator i = list.begin();
  while (i != list.end())
  {
    if ((*i).getTime() > this->_time)
      this->_list.push_back(*i);
    this->_list.sort(EventManager::_listSort);
    ++i;
  }
}

bool EventManager::_listSort(Event const& e1, Event const& e2)
{
  if (e1.getTime() > e2.getTime())
    return false;
  return true;
}
