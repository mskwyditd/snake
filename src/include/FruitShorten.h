#ifndef FRUITSHORTEN_H
#define FRUITSHORTEN_H

#include "Fruit.h"
#include "Snake.h"

class FruitShorten : public Fruit
{
    Snake * snake;
public:
    FruitShorten( Snake * s );
    ~FruitShorten();
    int getTypeOfFruit() override;
    void eat( int & time_to_move ) override;
    int getPoints() override;
};

#endif // FRUITSHORTEN_H
