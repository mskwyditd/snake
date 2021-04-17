#include "FruitShorten.h"

FruitShorten::FruitShorten( Snake * s ): snake(s)
{

}

FruitShorten::~FruitShorten()
{

}

void FruitShorten::eat( int & time_to_move )
{
    snake->shorten_by_half();
}

int FruitShorten::getTypeOfFruit()
{
    return 3;
}

int FruitShorten::getPoints()
{
    return -2;
}

