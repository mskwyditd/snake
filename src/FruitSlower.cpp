#include "FruitSlower.h"

FruitSlower::FruitSlower( Snake * s ): snake(s)
{

}

FruitSlower::~FruitSlower()
{

}

void FruitSlower::eat( int & time_to_move )
{
    snake->make_slower( time_to_move );
}

int FruitSlower::getTypeOfFruit()
{
    return 1;
}

int FruitSlower::getPoints()
{
    return 1;
}



