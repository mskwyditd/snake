#ifndef BOARD_H
#define BOARD_H

#include "Draw.h"
#include "Snake.h"
#include "Fruit.h"
#include <vector>
#include <cstdlib>
#include "SFML/Graphics.hpp"
#include <cmath>
#include "Draw.h"
#include "Snake.h"
#include "Fruit.h"


class Board
{
    int dir;
    const int & SCREEN_WIDTH;
    const int & SCREEN_HEIGHT;
    Draw * draw;
    Snake * snake;
    Fruit * fruit;
    const int & FIELD_SIZE;
    const int COLUMN_FIELDS;
    const int ROW_FIELDS;
    sf::Clock & clock;
    int & time_to_move;
public:
    Board( const int & width, const int & height, Draw * d, Snake * s, Fruit * f, const int & FS, sf::Clock & clk, int & tim2mv );
    ~Board();
    void updateSnake(Snake * s);
    void updateFruit(Fruit * f);
    void resetDirection();
    void pickPlaceForFruit();
    bool nextStep( sf::RenderWindow & window );
    void handleEvents( sf::Event & event );
    int handleKeyboard( sf::Event & event );

};

#endif // BOARD_H
