#include "Fruit.h"

Fruit::Fruit()
{
    x = 1;
    y = 1;
}

Fruit::~Fruit()
{

}

void Fruit::updateSnake(Snake * s)
{
    snake = s;
}

int Fruit::coordinates_x()
{
    return x;
}

int Fruit::coordinates_y()
{
    return y;
}

void Fruit::setPosition_x( int pos_x )
{
    x =  pos_x;
}

void Fruit::setPosition_y( int pos_y )
{
    y =  pos_y;
}

