#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
using namespace std;

class date
{
private:
    int day, month, year;

public:
    date();
    date(int m, int y);
    date(int d, int m, int y);

    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);
    void setDate(int d, int m, int y);

    int getDay();
    int getMonth();
    int getYear();
    string getDate();

    date operator+(double m);
    date operator+(date m);
    bool operator<(date const &d2);
};

#endif