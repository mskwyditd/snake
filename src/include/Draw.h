#ifndef DRAW_H
#define DRAW_H

#include <string>
#include "Snake.h"
#include "Fruit.h"
#include "SFML/Graphics.hpp"
#include <string>
#include "Ranking.h"


class Draw
{
    sf::RectangleShape snake_token;
    sf::RectangleShape fruit_token;
    Snake * snake;
    Fruit * fruit;
    const int & FIELD_SIZE;
    Ranking * ranking;
    sf::Font font;
    sf::Text text;
public:
    Draw( Snake * s, Fruit * f, const int & FS, Ranking * r );
    ~Draw();
    void updateSnake(Snake * s);
    void updateFruit(Fruit * f);
    void drawOnWindow( sf::RenderWindow & window );
    void writeText( sf::RenderWindow & window, std::string txt, int pos_x, int pos_y, sf::Color color );
};

#endif // DRAW_H
