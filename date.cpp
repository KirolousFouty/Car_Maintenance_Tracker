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

void date::printDate()
{
    cout << day << "/" << month << "/" << year;
}

date date::operator+(double m)
{
    date temp = *this;
    temp.setMonth(temp.getMonth() + m);

    while (temp.getMonth() > 12)
    {
        temp.setYear(temp.getYear() + 1);
        temp.setMonth((temp.getMonth() - 12));
    }

    return temp;
}

date date::operator+(date d2)
{
    date temp = *this;

    temp.day += d2.day;

    while (temp.day > 31)
    {
        temp.month++;
        temp.day -= 31;
    }

    temp.month += d2.month;

    while (temp.month > 12)
    {
        temp.year++;
        temp.month -= 12;
    }

    temp.year += d2.year;

    return temp;
}

date date::operator/(int n)
{
    double d1 = this->day + this->month * 31 + this->year * 12 * 31;

    int days = 0, months = 0, years = 0;
    days = d1 / n;

    while (days > 31)
    {
        months++;
        days -= 31;
    }

    while (months > 12)
    {
        years++;
        months -= 12;
    }

    return date(days, months, years);
}

bool date::operator<(date const &d2)
{
    if (this->year < d2.year)
    {
        return true;
    }
    else if (this->year > d2.year)
    {
        return false;
    }
    else // same year
    {
        if (this->month < d2.month)
        {
            return true;
        }
        else if (this->month > d2.month)
        {
            return false;
        }
        else // same month
        {
            if (this->day < d2.day)
            {
                return true;
            }
            else if (this->day > d2.day)
            {
                return false;
            }
            else // same day
            {
                return true;
            }
        }
    }
}

void date::operator=(date const &d2)
{
    this->day = d2.day;
    this->month = d2.month;
    this->year = d2.year;
}
