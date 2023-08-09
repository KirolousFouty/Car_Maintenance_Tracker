#ifndef DATEANDRANGE_H
#define DATEANDRANGE_H

#include "date.h"

class dateAndRange
{
private:
    date d;   // date
    double r; // range

public:
    dateAndRange();
    dateAndRange(date p_d, double p_r);

    void setDate(date p_d);
    void setRange(double p_r);

    date getDate();
    double getRange();
    bool operator<(dateAndRange const &d2);
    dateAndRange operator+(dateAndRange const &d2);
    dateAndRange operator=(dateAndRange const &d2);
};

#endif