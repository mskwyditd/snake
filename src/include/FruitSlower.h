#ifndef FRUITSLOWER_H
#define FRUITSLOWER_H

#include "Fruit.h"
#include "Snake.h"

class FruitSlower : public Fruit
{
    Snake * snake;
public:
    FruitSlower( Snake * s );
    ~FruitSlower();
    int getTypeOfFruit() override;
    void eat( int & time_to_move ) override;
    int getPoints() override;
};

#endif // FRUITSLOWER_H
