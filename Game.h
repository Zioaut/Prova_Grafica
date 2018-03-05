//
// Created by francesco on 30/09/17.
//

#ifndef PROVA_GAME_H
#define PROVA_GAME_H


#include "Window.h"
#include "Pong.h"
#include "Menu.h"

class Game {
public:
    Game();
    ~Game();

    void Update();
    void Render();
    void HandleInput();
    Window* GetWindow(){return &window;}
    sf::Time Getelapsed(){return elapsed;}
    void RestartClock(){elapsed+=clock.restart();}
    Menu*GetMenu(){return &menu;}
private:

    Window window;
    Pong pong;
    sf::Clock clock;
    sf::Time elapsed;
    Menu menu;



};


#endif //PROVA_GAME_H
