//
// Created by francesco on 16/10/17.
//

#include <iostream>
#include "Menu.h"

Menu::Menu(sf::Vector2u windowSize) {
    this->windowSize=windowSize;
    body.setPosition (300,100);
    body2.setPosition (300,400);
    body.setSize (sf::Vector2f(200,40));
    body2.setSize (sf::Vector2f(200,40));
    font.loadFromFile ("arial.ttf");
    text.setFont (font);
    text2.setFont (font);
    text.setPosition (340,100);
    text2.setPosition (340,400);
    text.setString ("Start");
    text2.setString ("Exit");
    body.setFillColor (sf::Color::Transparent);
    body2.setFillColor (sf::Color::Transparent);
    body.setOutlineThickness (5);
    body2.setOutlineThickness (5);
    body.setOutlineColor (sf::Color::Red);
    body2.setOutlineColor (sf::Color::Red);
    text.setColor (sf::Color::Red);
    text2.setColor (sf::Color::Red);
    ispress= 0;
}


Menu::~Menu() {}



void Menu::IsPressed() {

    if (sf::Keyboard::isKeyPressed (sf::Keyboard::A)) {
        ispress = 1;
    }
    if (sf::Keyboard::isKeyPressed (sf::Keyboard::L)) {
        ispress = 2;
    }
}



void Menu::Render(sf::RenderWindow &window) {
    window.draw (body);
    window.draw (body2);
    window.draw (text);
    window.draw (text2);
}

void Menu::Update() {
    IsPressed ();

}