#include "Draw.h"


Draw::Draw( Snake * s, Fruit * f, const int & FS, Ranking * r ): snake( s ), fruit(f), FIELD_SIZE( FS ), ranking( r )
{
    snake_token = sf::RectangleShape( sf::Vector2f( FIELD_SIZE, FIELD_SIZE ) );
    snake_token.setFillColor( sf::Color::Green );
    fruit_token = sf::RectangleShape( sf::Vector2f( FIELD_SIZE, FIELD_SIZE ) );
    fruit_token.setFillColor( sf::Color::Blue );

    if(!font.loadFromFile("Arial.ttf"))
    {
        abort();
    }
    text.setFont(font);
}

Draw::~Draw()
{

}

void Draw::drawOnWindow( sf::RenderWindow & window )
{
    int x, y;
    for( int i = 0; i < snake->getLength(); i++ )
    {
        x = snake->coordinates_x( i );
        y = snake->coordinates_y( i );
        snake_token.setPosition( FIELD_SIZE*x, FIELD_SIZE*y );
        window.draw( snake_token );
    }

    x = fruit->coordinates_x();
    y = fruit->coordinates_y();
    if( x >=0 && y >= 0 )
    {
        if( fruit->getTypeOfFruit() == 0 ) fruit_token.setFillColor( sf::Color::Magenta );
        else if( fruit->getTypeOfFruit() == 1 ) fruit_token.setFillColor( sf::Color::Yellow );
        else if( fruit->getTypeOfFruit() == 2 ) fruit_token.setFillColor( sf::Color::Blue );
        else if( fruit->getTypeOfFruit() == 3 ) fruit_token.setFillColor( sf::Color::Red );
        fruit_token.setPosition( FIELD_SIZE*x, FIELD_SIZE*y );
        window.draw( fruit_token );
    }

    writeText( window, std::to_string( ranking->getScoreTmp() ), 0, 0, sf::Color::White );

}

void Draw::updateSnake(Snake * s)
{
    snake = s;
}

void Draw::updateFruit(Fruit * f)
{
    fruit = f;
}

void Draw::writeText( sf::RenderWindow & window, std::string txt, int pos_x, int pos_y, sf::Color color )
{
    text.setString( txt );
    text.setPosition( pos_x, pos_y );
    text.setFillColor( color );
    window.draw( text );
}

