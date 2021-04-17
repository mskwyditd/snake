#include "FruitFaster.h"

FruitFaster::FruitFaster( Snake * s ): snake(s)
{

}

FruitFaster::~FruitFaster()
{

}

void FruitFaster::eat( int & time_to_move )
{
    snake->make_faster( time_to_move );
}

int FruitFaster::getTypeOfFruit()
{
    return 0;
}

int FruitFaster::getPoints()
{
    return 4;
}
