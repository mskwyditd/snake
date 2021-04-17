#include "Ranking.h"


Ranking::Ranking()
{
    score_tmp = 0;
    best_score = 0;
    std::ifstream input("leaderboard.txt");
    if( !input.good() ) abort();

    while( !input.eof() )
    {
        int tmp2;
        std::string tmp1;
        input >> tmp1 >> tmp2;
        Record a( tmp1 );
        Record b( tmp2 );
        leaderboard.push_back( a + b );
    }
    input.close();

}

Ranking::~Ranking()
{

}

void Ranking::save( std::string nick )
{
    if( best_score > 0 )
    {
        std::ofstream output("leaderboard.txt");
        if( !output.good() ) abort();
        Record a( nick );
        Record b( best_score );
        leaderboard.push_back( a + b );

        for( int i = leaderboard.size() - 1; i > 0; i-- )
        {
            Record c = leaderboard.at( i ), d = leaderboard.at( i - 1 );

            if( c.howManyPoints() > d.howManyPoints() )
            {
                Record tmp = leaderboard.at( i );
                leaderboard.at( i ) = leaderboard.at( i - 1 );
                leaderboard.at( i - 1 ) = tmp;
            }
        }

        int leaderboardSize = leaderboard.size();
        for( int i = 0; i < leaderboardSize; i++)
        {
            output << leaderboard.at( i );
            if( i + 1 != leaderboardSize ) output << std::endl;
        }

        output.close();
    }
}



int Ranking::getScoreTmp() const
{
    return score_tmp;
}


int Ranking::getYourBestScore() const
{
    return best_score;
}

void Ranking::addToScore( int x )
{
    score_tmp += x;
}

void Ranking::resetScore()
{
    if( best_score < score_tmp ) best_score = score_tmp;
    score_tmp = 0;
}

//najwyzszy wynik w pliku
int Ranking::getLeader() const
{
    if( leaderboard.size() == 0 ) return 0;
    Record a = leaderboard.at( 0 );
    return a.howManyPoints();
}



