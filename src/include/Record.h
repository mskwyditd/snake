#ifndef RECORD_H
#define RECORD_H

#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <iostream>

class Record
{
    std::string nickname;
    int score;
public:
    Record();
    Record( std:: string name );
    Record( int scoreTmp );
    Record operator+(const Record & rv) const;
    Record & operator =( const Record & r );
    int howManyPoints() const;
    std::string whatName() const;

    friend std::ostream & operator<<(std::ostream & str, const Record & rv);

};

std::ostream & operator<<(std::ostream & str, const Record & rv);

#endif // RECORD_H
