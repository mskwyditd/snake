#ifndef RANKING_H
#define RANKING_H

#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <bits/stdc++.h>
#include "Record.h"


class Ranking
{
    std::vector < Record > leaderboard;
    int score_tmp;
    int best_score;

public:
    Ranking();
    ~Ranking();
    void save( std::string nick );
    int getScoreTmp() const;
    int getYourBestScore() const;
    void addToScore( int x );
    void resetScore();
    int getLeader() const;
};

#endif // RANKING_H
