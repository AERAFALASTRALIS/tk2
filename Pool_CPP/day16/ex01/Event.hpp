/*
** EPITECH PROJECT, 2021
** event
** File description:
** event
*/

#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <iostream>

class Event {
public:
  Event(void);
  Event(unsigned int time, const std::string& event);
  Event(Event const& other);
  ~Event();
  Event& operator=(Event const& rhs);
  unsigned int getTime(void) const;
  const std::string& getEvent(void) const;
  void setTime(unsigned int time);
  void setEvent(std::string const& event);
private:
  unsigned int _time;
  std::string _event;
};

#endif
