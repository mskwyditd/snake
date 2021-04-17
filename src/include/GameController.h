#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "Board.h"
#include "Draw.h"
#include "Snake.h"
#include "Fruit.h"
#include "FruitSlower.h"
#include "FruitFaster.h"
#include "FruitGrow.h"
#include "FruitShorten.h"
#include "SFML/Graphics.hpp"
#include <ctime>
#include <cstdlib>
#include "Ranking.h"
#include "TextBox.h"


class GameController
{
    TextBox textbox;
    bool hasEscaped;
    Snake * snake;
    Fruit * fruit;
    Draw * draw;
    Board * board;
    Ranking * ranking;
    sf::Clock clock;
    const int FIELD_SIZE = 50;//must be true: NWD(SCREEN_WIDTH, SCREEN_HEIGHT, FIELD_SIZE) == FIELD_SIZE
    const int SCREEN_WIDTH = 1000;
    const int SCREEN_HEIGHT = 1000;
    const int FIELDS_X = SCREEN_WIDTH / FIELD_SIZE;
    const int FIELDS_Y = SCREEN_HEIGHT / FIELD_SIZE;
    int time_to_move = 300;//time of every snake's move
    void newFruit();
    void winMenu();
    void startGame();
    void saveScore();

public:
    GameController();
    ~GameController();
    void run();

};

#endif // GAME_CONTROLLER_H
