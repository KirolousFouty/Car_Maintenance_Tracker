#include "dateAndRange.h"

dateAndRange::dateAndRange()
{
    d = date(0, 0, 0);
    r = 0;
}

dateAndRange::dateAndRange(date p_d, double p_r)
{
    d = p_d;
    r = p_r;
}

void dateAndRange::setDate(date p_d)
{
    d = p_d;
}

void dateAndRange::setRange(double p_r)
{
    r = p_r;
}

date dateAndRange::getDate()
{
    return d;
}

double dateAndRange::getRange()
{
    return r;
}

bool dateAndRange::operator<(dateAndRange const &d2)
{
    if (this->r < d2.r || this->d < d2.d)
        return true;
    else
        return false;
}

dateAndRange dateAndRange::operator+(dateAndRange const &d2)
{
    dateAndRange temp;
    temp.r = this->r + d2.r;
    temp.d = this->d + d2.d;
    return temp;
}

dateAndRange dateAndRange::operator=(dateAndRange const &d2)
{
    this->d = d2.d;
    this->r = d2.r;
}
