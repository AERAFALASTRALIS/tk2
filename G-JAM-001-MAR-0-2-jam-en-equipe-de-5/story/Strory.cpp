/*
** EPITECH PROJECT, 2021
** gamejam2
** File description:
** Strory
*/

#include "Story.hpp"

Story::Story()
{
}

void Story::pushStory() {

    this->_story.resize(4);

    std::ifstream fileFr("story/consigne_fr");
    std::string linefr;
    while(std::getline(fileFr, linefr)) this->_story[0].push_back(linefr);

    std::ifstream fileEn("story/consigne_en");
    std::string lineEn;
    while(std::getline(fileEn, lineEn)) this->_story[1].push_back(lineEn);

    std::ifstream fileEs("story/consigne_es");
    std::string lineEs;
    while(std::getline(fileEn, lineEs)) this->_story[2].push_back(lineEs);
}

void Story::getStory(size_t id) {

    std::ifstream fileFr("story/consigne_fr");
    std::ifstream fileEn("story/consigne_en");
    std::ifstream fileEs("story/consigne_es");

    std::string line;
    if (id == 0 ) while(std::getline(fileFr, line)) std::cout << line << std::endl;
    else if (id == 1 ) while(std::getline(fileEn, line)) std::cout << line << std::endl;
    else if (id == 2 ) while(std::getline(fileEs, line)) std::cout << line << std::endl;
}

Story::~Story()
{
}
