#ifndef SNAKE_H
#define SNAKE_H

#include <vector>

class Snake
{
    int length;
    int direction;
    const int & LINE_FIELDS;
    const int & COLUMN_FIELDS;
    std::vector < int > snake_position_x;
    std::vector < int > snake_position_y;
public:
    Snake( const int & FIELDS_X, const int & FIELDS_Y );
    ~Snake();

    void grow();
    void shorten_by_half();
    void make_faster( int & time_to_move );
    void make_slower( int & time_to_move );

    void move();
    int coordinates_x( int position ) const;
    int coordinates_y( int position ) const;
    bool isSnakeOn( int x, int y );
    int getLength();
    void turn_right();
    void turn_left();
    int check_direction() const;
    bool isAlive() const;
};

#endif // SNAKE_H
