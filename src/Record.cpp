#include "Record.h"

#include <fstream>
#include <cstdlib>

Record::Record()
{
    nickname = "";
    score = 0;
}

Record::Record( std:: string name )
{
    nickname = name;
    score = 0;
}

Record::Record( int scoreTmp )
{
    score = scoreTmp;
    nickname = "";
}


Record Record::operator +(const Record & rv) const
{
    Record wynik;
    wynik.nickname = nickname;//this->re
    wynik.score = rv.score + score;//this->im
    return wynik;
}

Record & Record::operator =(const Record & r)
{
    if(this == &r) return *this;

    score = r.score;
    nickname = r.nickname;

    return *this;
}

int Record::howManyPoints() const
{
    return score;
}

std::string Record::whatName() const
{
    return nickname;
}

std::ostream & operator<<(std::ostream & str, const Record & rv)
{
    str << rv.whatName() << " " << rv.howManyPoints();
    return str;
}
