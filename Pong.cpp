//
// Created by francesco on 29/09/17.
//

#include <iostream>
#include "Pong.h"

Pong::Pong(sf::Vector2u windSize) {
    windowSize = windSize;
    p1.setSize(sf::Vector2f(30, 100));
    p2.setSize(sf::Vector2f(30, 100));
    ball.setRadius(10);
    increment=sf::Vector2f(0.1,0.1);
    delay=1.6;
    font.loadFromFile ("arial.ttf");
    text.setFont (font);
    text.setString ("0");
    text.setColor (sf::Color::Red);
    text.setPosition (200,point.getPosition ().y/2);
    text2.setFont (font);
    text2.setColor (sf::Color::Red);
    text2.setString ("0");
    text2.setPosition (600,point.getPosition ().y/2);
    point.setPosition (200,1);
    point.setSize (sf::Vector2f(windowSize.x/2,50));
    point.setFillColor (sf::Color::Transparent);
    CreateBall();
    Reset();

}

Pong::~Pong() {}


void Pong::Reset() {
 p1.setPosition(50,windowSize.y/2);
 p2.setPosition(windowSize.x-50,windowSize.y/2);
    SetDirection(Direction::None);
    score=0;
    score2=0;
    speed=10;
    win=false;
    text.setString ("0");
    text2.setString ("0");



}


void Pong::Update() {
    if(direction==Direction::None){ return;}

       Move();
       CheckCollision();

}



void Pong::Move() {
    if(direction==Direction::Down){
        p1.setPosition(p1.getPosition().x,p1.getPosition().y+1*delay*10);
        direction=Direction ::None;
    }else if(direction==Direction::Up){
        p1.setPosition(p1.getPosition().x,p1.getPosition().y-1*delay*10);
        direction=Direction ::None;
    }
    if(direction==Direction::Down2){
        p2.setPosition(p2.getPosition().x,p2.getPosition().y+1*delay*10);
        direction=Direction ::None;
    }else if(direction==Direction::Up2){
        p2.setPosition(p2.getPosition().x,p2.getPosition().y-1*delay*10);
        direction=Direction ::None;
    }

}

void Pong::CheckCollision() {
    if(p1.getPosition().y<1) {
        p1.setPosition(p1.getPosition().x, 1);
    }else if(p1.getPosition().y>=windowSize.y-p1.getSize().y){
        p1.setPosition(p1.getPosition().x,windowSize.y-p1.getSize().y);
    }
    if(p2.getPosition().y<1) {
        p2.setPosition(p2.getPosition().x, 1);
    }else if(p2.getPosition().y>=windowSize.y-p2.getSize().y){
        p2.setPosition(p2.getPosition().x,windowSize.y-p2.getSize().y);}
}

void Pong::CreateBall() {
    ball.setPosition(windowSize.x/2,windowSize.y/2);
}


void Pong::Increasescore() {
    if(ball.getPosition().x>windowSize.x) {
        score += 1;
        Addstring (std::to_string (score));
        CreateBall();

    }
}

void Pong::Increasescore2() {

    if(ball.getPosition().x<=1){
        score2+=1;
        Addstring2 (std::to_string (score2));
        CreateBall();


    }

}

void Pong::SetDirection(Direction dir) {
    direction=dir;
}

int Pong::GetSpeed() { return speed;}

Direction Pong::GetDirection() {
    return direction;
}

bool Pong::Haswin() {
    if(score>9||score2>9){
        win=true;}
        return win;
}

void Pong::Render(sf::RenderWindow &window) {
    p1.setFillColor(sf::Color::White);
    p2.setFillColor(sf::Color::Yellow);
    ball.setFillColor(sf::Color::Red);
    p1.setPosition(p1.getPosition().x,p1.getPosition().y);
    p2.setPosition(p2.getPosition().x,p2.getPosition().y);
    window.draw(p1);
    window.draw(p2);
    window.draw(ball);
    window.draw (text);
    window.draw (point);
    window.draw (text2);
}



void Pong::BouncingBall() {


    if(ball.getPosition().y>windowSize.y&&increment.y>0||
            ball.getPosition().y<0&&increment.y<0)
        increment.y=-increment.y;



    if(ball.getGlobalBounds().intersects(p1.getGlobalBounds())||(ball.getGlobalBounds().intersects(p2.getGlobalBounds()))){
        increment.x=-increment.x;
    }



    ball.setPosition(ball.getPosition().x+increment.x*delay,ball.getPosition().y+increment.y*delay);
}

void Pong::Addstring(std::string message) {
    text.setString (message);

}

void Pong::Addstring2(std::string message) {
    text2.setString (message);

}
