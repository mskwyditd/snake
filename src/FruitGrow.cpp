#include "FruitGrow.h"

FruitGrow::FruitGrow( Snake * s ): snake(s)
{

}

FruitGrow::~FruitGrow()
{

}

void FruitGrow::eat( int & time_to_move )
{
    snake->grow();
}

int FruitGrow::getTypeOfFruit()
{
    return 2;
}


int FruitGrow::getPoints()
{
    return 10;
}
