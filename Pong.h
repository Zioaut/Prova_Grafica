//
// Created by francesco on 29/09/17.
//

#ifndef PROVA_PONG_H
#define PROVA_PONG_H


#include <SFML/System.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

enum class Direction{None,Up,Down,Up2,Down2};

class Pong {
public:
    Pong(sf::Vector2u windSize);
    ~Pong();

    void Update();
    void SetDirection(Direction dir);
    Direction GetDirection();
    int GetSpeed();
    void Reset();
    void Increasescore();
    void Increasescore2();
    bool Haswin();
    void Move();
    void BouncingBall();
    void CreateBall();
    void Render(sf::RenderWindow& window);
    void Addstring(std::string message);
    void Addstring2(std::string message);
private:
    void CheckCollision();

    sf::Vector2u windowSize;
    sf::RectangleShape p1;
    sf::RectangleShape p2;
    sf::CircleShape ball;
    int speed;
    int score,score2;
    bool win;
    Direction  direction;
    sf::Vector2f increment;
    float delay;
    sf::Font font;
    sf::Text text;
    sf::Text text2;
    sf::RectangleShape point;

};


#endif //PROVA_PONG_H
