#include "Board.h"

Board::Board( const int & width, const int & height, Draw * d, Snake * s, Fruit * f, const int & FS, sf::Clock & clk, int & tim2mv )
: SCREEN_WIDTH( width ), SCREEN_HEIGHT( height ), draw( d ), snake( s ), fruit( f ), FIELD_SIZE( FS ),
COLUMN_FIELDS( height / FS ), ROW_FIELDS( width / FS ), clock( clk ), time_to_move( tim2mv )
{
    dir = 0;
}

Board::~Board()
{

}

void Board::updateSnake(Snake * s)
{
    snake = s;
}

void Board::updateFruit(Fruit * f)
{
    fruit = f;
}

void Board::resetDirection()
{
    dir = 0;
}

void Board::pickPlaceForFruit()
{
    int x, y;
    do
    {
        x = std::rand() % ROW_FIELDS;
        y = std::rand() % COLUMN_FIELDS;
    }
    while( !snake->isSnakeOn( x, y ) );

    fruit->setPosition_x( x );
    fruit->setPosition_y( y );
}

bool Board::nextStep( sf::RenderWindow & window )
{
    window.clear( sf::Color::Black );

    if( !snake->isAlive() ) return false;

    if( clock.getElapsedTime().asMilliseconds() > abs( time_to_move ) )
    {
        if( ( dir + 1 ) % 4 == snake->check_direction() )
        {
            snake->turn_left();
        }

        else if( ( dir + 3 ) % 4 == snake->check_direction() )
        {
            snake->turn_right();
        }

        if( !snake->isAlive() ) return false;

        snake->move();
        clock.restart();
    }

    draw->drawOnWindow( window );
    window.display();
    return true;
}

void Board::handleEvents( sf::Event & event )
{
    switch( event.key.code )
    {
    case 73:
        dir = 3;
        break;
    case 22:
        dir = 3;
        break;
    case 71:
        dir = 2;
        break;
    case 0:
        dir = 2;
        break;
    case 74:
        dir = 1;
        break;
    case 18:
        dir = 1;
        break;
    case 72:
        dir = 0;
        break;
    case 3:
        dir = 0;
        break;
    case 27:
        //predkosc 1
        time_to_move = 400;
        break;
    case 28:
        //predkosc 2
        time_to_move = 120;
        break;
    case 29:
        //predkosc 3
        time_to_move = 80;
        break;
    case 30:
        //predkosc 4
        time_to_move = 60;
        break;
    default:
        break;

    }

}


int Board::handleKeyboard( sf::Event & event )
{
    int x = event.key.code;
    if( x >= 0 && x <= 26 ) return x;
    if( x == sf::Keyboard::BackSpace ) return -2;
    if( x == sf::Keyboard::Space ) return x;
    return -1;
}



