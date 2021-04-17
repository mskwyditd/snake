#include "Snake.h"

Snake::Snake( const int & FIELDS_X, const int & FIELDS_Y ): LINE_FIELDS( FIELDS_X ), COLUMN_FIELDS( FIELDS_Y )
{
    snake_position_x.push_back( ( FIELDS_X / 2 ) + 0 );
    snake_position_y.push_back( ( FIELDS_Y / 2 ) + 0 );
    length = 1;
    direction = 0;
}

Snake::~Snake()
{

}

void Snake::grow()
{
    //make_longer = true;
    snake_position_x.push_back( snake_position_x.at( 0 ) );
    snake_position_y.push_back(  snake_position_y.at( 0 ) );
    length++;
}

void Snake::shorten_by_half()
{
    length /= 2;

    snake_position_x.resize( length );
    snake_position_y.resize( length );

}

void Snake::move()
{
    //moving tail
    for( int i = length - 1; i > 0; --i )
    {
        snake_position_x.at( i ) = snake_position_x.at( i - 1 );
        snake_position_y.at( i ) = snake_position_y.at( i - 1 );
    }

    //moving head
    if( snake_position_x.size() > 0 && snake_position_y.size() > 0 )
    {
        if( direction == 0 ) snake_position_x.at( 0 ) ++;
        else if( direction == 1 ) snake_position_y.at( 0 ) ++;
        else if( direction == 2 ) snake_position_x.at( 0 ) --;
        else if( direction == 3 ) snake_position_y.at( 0 ) --;
    }

    //checking if snake out the board
    if( length > 0 )
    {
        if( snake_position_y.at( 0 ) >= LINE_FIELDS ) length = 0;
        else if( snake_position_y.at( 0 ) < 0 ) length = 0;
        else if( snake_position_x.at( 0 ) >= COLUMN_FIELDS ) length = 0;
        else if( snake_position_x.at( 0 ) < 0 ) length = 0;
    }

    //checking if snake on snake
    for( int i = 1; i < length; ++i )
    {
        if( ( snake_position_y.at( i ) == snake_position_y.at( 0 ) ) && ( snake_position_x.at( i ) == snake_position_x.at( 0 ) ) )
            length = 0;
    }
}

void Snake::turn_right()
{
    direction ++;
    direction %= 4;
}

void Snake::turn_left()
{
    direction += 3;
    direction %= 4;
}

bool Snake::isAlive() const
{
    if( length > 0 ) return true;
    return false;
}

int Snake::coordinates_x( int position ) const
{
    return snake_position_x.at( position );
}

int Snake::coordinates_y( int position ) const
{
    return snake_position_y.at( position );
}

bool Snake::isSnakeOn( int x, int y )
{
    for( int i = 0; i < snake_position_x.size() ;i++)
    {
        for( int j = 0; j < snake_position_y.size() ; j++)
        {
            if( snake_position_x.at( i ) == x && snake_position_y.at( j ) == y ) return false;
        }
    }
    return true;
}

int Snake::getLength()
{
    return length;
}

int Snake::check_direction() const
{
    return direction;
}

void Snake::make_faster( int & time_to_move )
{
    if( time_to_move > 180 ) time_to_move -= 80;
    else if( time_to_move > 60 ) time_to_move -= 20;
}

void Snake::make_slower( int & time_to_move )
{
    if( time_to_move < 400 ) time_to_move += 50;
}

