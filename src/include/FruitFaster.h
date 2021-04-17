#ifndef FRUITFASTER_H
#define FRUITFASTER_H

#include "Fruit.h"
#include "Snake.h"

class FruitFaster : public Fruit
{
    Snake * snake;
public:
    FruitFaster( Snake * s );
    ~FruitFaster();
    int getTypeOfFruit() override;
    void eat( int & time_to_move ) override;
    int getPoints() override;
};

#endif // FRUITFASTER_H
