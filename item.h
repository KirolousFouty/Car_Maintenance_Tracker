#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "date.h"
#include "dateAndRange.h"
using namespace std;

class item
{
private:
    dateAndRange lastChecked;
    dateAndRange lastReplaced;
    dateAndRange upcomingCheck;
    dateAndRange upcomingReplacement;
    double avgLifetime;
    int timesChecked;
    int timesReplaced;
    int timesFailed;
    string notes;

    vector<pair<bool, dateAndRange>> checkDates;
    vector<dateAndRange> replacementDates;
    vector<dateAndRange> failureDates;

public:
    item();
    item(date lastChecked, date lastReplaced, date upcomingCheck, date upcomingReplacement, double avgLifetime, int timesChecked, int timesReplaced, int timesFailed, string notes);

    date getLastChecked();
    date getLastReplaced();
    date getUpcomingCheck();
    date getUpcomingReplacement();

    void setLastChecked(dateAndRange d);
    void setLastReplaced(dateAndRange d);
    void setUpcomingCheck(dateAndRange d);
    void setUpcomingReplacement(dateAndRange d);

    void checked(bool state, date d, double currentRange);
    void replaced(date d, double currentRange);
};
#endif