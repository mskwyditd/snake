#include "GameController.h"


GameController::GameController()
{
    snake = new Snake( FIELDS_X, FIELDS_Y );
    fruit = new FruitFaster( snake );
    ranking = new Ranking();
    draw = new Draw( snake, fruit, FIELD_SIZE, ranking );
    board = new Board( SCREEN_WIDTH, SCREEN_HEIGHT, draw, snake, fruit, FIELD_SIZE, clock, time_to_move );
    srand( time( NULL ) );
    hasEscaped = false;
}

GameController::~GameController()
{
    delete board;
    delete draw;
    delete ranking;
    delete fruit;
    delete snake;
}

void GameController::newFruit()
{
    int tmp = rand() % 8;
    if( tmp == 0 ) fruit = new FruitFaster( snake );
    else if( tmp == 1 ) fruit = new FruitSlower( snake );
    else if( tmp == 3 ) fruit = new FruitShorten( snake );
    else fruit = new FruitGrow( snake );
}

void GameController::winMenu()
{
    sf::RenderWindow window( sf::VideoMode( SCREEN_WIDTH, SCREEN_HEIGHT ), "Snake" );
    window.setVerticalSyncEnabled( true );
    while( window.isOpen() )
    {
        sf::Event event;
        while( window.pollEvent ( event ) )
        {
            if( ( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape ) ||
                    event.type == sf::Event::Closed ) hasEscaped = true;

            if ( hasEscaped || ( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space ) )
            {
                window.close();
                continue;
            }
        }
        window.clear( sf::Color::Black );
        draw->writeText( window, "Press Space to start, Esc to exit", 200, 200, sf::Color::Blue );
        draw->writeText( window, "Rules:", 200, 240, sf::Color::White );
        draw->writeText( window, "1. Moving with arrows or WSAD keys", 200, 280, sf::Color::White );
        draw->writeText( window, "2. Change the speed with 1-4 buttons", 200, 320, sf::Color::White );
        draw->writeText( window, "3. Use Space to end the game & save score", 200, 360, sf::Color::White );
        draw->writeText( window, "4. Use Esc to exit without saving score", 200, 400, sf::Color::White );

        window.display();
    }
}

void GameController::startGame()
{
    sf::RenderWindow window( sf::VideoMode( SCREEN_WIDTH, SCREEN_HEIGHT ), "Snake" );
    window.setVerticalSyncEnabled( true );

    sf::Clock tmp_clock;
    board->pickPlaceForFruit();

    while ( window.isOpen() )
    {
        sf::Event event;
        while ( window.pollEvent(event) )
        {
            if( event.type == sf::Event::Closed ||
               ( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape ) ) hasEscaped = true;

            if ( hasEscaped )
            {
                window.close();
                continue;
            }
            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space )
            {
                ranking->resetScore();
                window.close();
                continue;
            }
            board->handleEvents( event );
        }
        //when head on fruit
        if( snake->coordinates_x( 0 ) == fruit->coordinates_x() && snake->coordinates_y( 0 ) == fruit->coordinates_y() )
        {
            ranking->addToScore( ( fruit->getPoints() ) * ( 440 / time_to_move ) );
            fruit->eat( time_to_move );
            delete fruit;
            newFruit();
            draw->updateFruit( fruit );
            board->updateFruit( fruit );
            board->pickPlaceForFruit();

            tmp_clock.restart();
        }
        //new fruit after every 10 sec
        if( tmp_clock.getElapsedTime().asMilliseconds() > 10000 )
        {
            delete fruit;
            newFruit();
            draw->updateFruit( fruit );
            board->updateFruit( fruit );
            board->pickPlaceForFruit();

            tmp_clock.restart();
        }
        //if snake died
        if( !board->nextStep( window ) )
        {
            delete snake;
            snake = new Snake( FIELDS_X, FIELDS_Y );
            draw->updateSnake( snake );
            board->updateSnake( snake );
            fruit->updateSnake( snake );
            ranking->resetScore();
            board->resetDirection();
            time_to_move = 300;
        }
    }
}


void GameController::saveScore()
{
    sf::Clock tmp_clock;

    sf::RenderWindow window( sf::VideoMode( SCREEN_WIDTH, SCREEN_HEIGHT ), "Snake" );
    window.setVerticalSyncEnabled( true );
    int letterCode = -1;
    while( window.isOpen() )
    {
        sf::Event event;
        while( window.pollEvent ( event ) )
        {
            if ( event.type == sf::Event::Closed ||
                    ( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape )
               )
            {
                window.close();
                continue;
            }
            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter )
            {
                if( textbox.getText() != "" ) ranking->save( textbox.getText() );
                window.close();
                continue;
            }

            if( event.type == sf::Event::KeyPressed ) letterCode = board->handleKeyboard( event );
        }

        if( tmp_clock.getElapsedTime().asMilliseconds() > 40 )
        {
            if( letterCode >= 0 && letterCode <= 26 ) textbox.addLetter( char( letterCode ) + 'A' );
            else if( letterCode == -2 ) textbox.deleteLastLetter();
            else if( letterCode == 57 ) textbox.addLetter( '_' );
            letterCode = -1;
            tmp_clock.restart();
        }

        window.clear( sf::Color::Black );
        draw->writeText( window, "Your best score is: " + std::to_string( ranking->getYourBestScore() ), 300, 200, sf::Color::White );
        draw->writeText( window, "The best score on leaderboard: " + std::to_string( ranking->getLeader() ), 300, 240, sf::Color::White );
        draw->writeText( window, "Press Esc to exit without saving", 300, 280, sf::Color::Blue );
        draw->writeText( window, "Press Enter to save score", 300, 320, sf::Color::Blue );
        draw->writeText( window, "Your nickname: " + textbox.getText() , 300, 360, sf::Color::White );
        window.display();
    }
}

void GameController::run()
{
    //winMenu();
    if( !hasEscaped )
    {
        startGame();
    }
    /*if( !hasEscaped )
    {
        saveScore();
    }*/


}

