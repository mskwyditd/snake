#ifndef FRUITGROW_H
#define FRUITGROW_H

#include "Fruit.h"
#include "Snake.h"

class FruitGrow : public Fruit
{
    Snake * snake;
public:
    FruitGrow( Snake * s );
    ~FruitGrow();
    int getTypeOfFruit() override;
    void eat( int & time_to_move ) override;
    int getPoints() override;
};

#endif // FRUITGROW_H
