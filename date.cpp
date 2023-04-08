#include "date.h"

date::date()
{
    day = 0;
    month = 0;
    year = 0;
}

date::date(int m, int y)
{
    day = 15;
    month = m;
    year = y;
}

date::date(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

void date::setDay(int d)
{
    day = d;
}

void date::setMonth(int m)
{
    month = m;
}

void date::setYear(int y)
{
    year = y;
}

void date::setDate(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

int date::getDay()
{
    return day;
}

int date::getMonth()
{
    return month;
}

int date::getYear()
{
    return year;
}

string date::getDate()
{
    string s;
    s = to_string(day) + "/" + to_string(month) + "/" + to_string(year);
    return s;
}