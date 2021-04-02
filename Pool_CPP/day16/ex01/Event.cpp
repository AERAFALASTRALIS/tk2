/*
** EPITECH PROJECT, 2021
** event
** File description:
** event
*/

#include "Event.hpp"

Event::Event(void) : _time(0), _event("")
{
}

Event::Event(unsigned int time, const std::string& event) : _time(time), _event(event)
{
}

Event::Event(Event const& other) : _time(other._time), _event(other._event)
{
}

Event::~Event()
{
}

Event& Event::operator=(Event const& rhs)
{
  this->_time = rhs._time;
  this->_event = rhs._event;
  return (*this);
}

unsigned int Event::getTime(void) const
{
  return (this->_time);
}

const std::string& Event::getEvent(void) const
{
  return (this->_event);
}

void Event::setTime(unsigned int time)
{
  this->_time = time;
}

void Event::setEvent(std::string const& event)
{
  this->_event = event;
}
