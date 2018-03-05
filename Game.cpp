//
// Created by francesco on 30/09/17.
//

#include <cstdlib>
#include "Game.h"
Game::Game():window("Pong!",sf::Vector2u(800,600)),pong(sf::Vector2u(800,600)),menu(sf::Vector2u(800,600)) {

}


void Game::HandleInput() {
    pong.BouncingBall();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        pong.SetDirection(Direction::Up);}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        pong.SetDirection(Direction::Down);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        pong.SetDirection(Direction::Down2);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        pong.SetDirection(Direction::Up2);
    }
}


void Game::Update() {

    window.Update();
    menu.Update ();

    float frametime=1.0/60.0f;

    if(menu.Getispress ()==1){
    if(elapsed.asSeconds()>=frametime) {
        pong.Update();
        pong.Increasescore();
        pong.Increasescore2();
        elapsed-=sf::seconds(frametime);
    }
    if(pong.Haswin())

        pong.Reset();}
}


void Game::Render() {

    if (menu.Getispress () != 1&&menu.Getispress ()!=2) {
        window.BeginDraw ();
        menu.Render (*window.GetRenderWindow ());
        window.EndDraw ();
    } else if(menu.Getispress ()==1){
        window.BeginDraw ();
        pong.Render (*window.GetRenderWindow ());
        window.EndDraw ();
    } else if(menu.Getispress ()==2){
        window.Destroy ();

    }
}
Game::~Game() {}