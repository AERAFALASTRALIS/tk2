/*
** EPITECH PROJECT, 2021
** wrap
** File description:
** wrap
*/

#ifndef WRAP_H_
#define WRAP_H_

#include "Object.hpp"

class Wrap : public Object {
public:
    const Object* get_Obj() const;
    Wrap(std::string const & name, std::string const & type);
    ~Wrap();
    bool isEmpty() const;
    bool isOpen() const;
    Object* takeWrap();
    std::string getType() const;

    void openMe();
    void wrapMeThat(Object *obj);

protected:
    Object* _obj;
    bool _isOpen;

private:
    std::string _type;
};

#endif
