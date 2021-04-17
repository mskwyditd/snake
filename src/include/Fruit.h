#ifndef FRUIT_
#define FRUIT_

#include <Snake.h>

class Fruit
{
    Snake * snake;
    int x;
    int y;
public:
    Fruit();
    virtual ~Fruit();
    virtual void eat( int & time_to_move ) = 0;
    virtual int getTypeOfFruit() = 0;
    virtual int getPoints() = 0;
    void updateSnake(Snake * s);
    int coordinates_x();
    int coordinates_y();
    void setPosition_x( int pos_x );
    void setPosition_y( int pos_y );
};

#endif // FRUIT_
