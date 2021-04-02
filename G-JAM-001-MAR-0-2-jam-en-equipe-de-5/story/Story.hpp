/*
** EPITECH PROJECT, 2021
** gamejam2
** File description:
** Story
*/

#ifndef STORY_HPP_
#define STORY_HPP_

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include  <iterator>

class Story {
    public:
        Story();
        ~Story();

        void pushStory();
        void getStory(size_t pos);

    protected:
    private:
        std::vector<std::vector<std::string>> _story;
};

#endif /* !Story_HPP_ */
