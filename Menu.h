//
// Created by francesco on 16/10/17.
//

#ifndef PROVA_MENU_H
#define PROVA_MENU_H


#include <SFML/Graphics/RectangleShape.hpp>
#include "Window.h"
#include <SFML/Graphics.hpp>

class Menu{
public:
    Menu(sf::Vector2u windowSize);

    void Update();
    void IsPressed();
    void Render(sf::RenderWindow & window);

    int Getispress(){return ispress;};
~Menu();


private:
    int ispress;
    sf::Vector2u windowSize;
    sf::RectangleShape body;
    sf::RectangleShape body2;
    sf::Text text;
    sf::Font font;
    sf::Text text2;
    sf::Mouse mouse;


};


#endif //PROVA_MENU_H
