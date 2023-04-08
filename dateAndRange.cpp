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