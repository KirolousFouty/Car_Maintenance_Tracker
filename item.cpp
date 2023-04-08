#include "item.h"

date item::getLastChecked()
{
    return lastChecked;
}

date item::getLastReplaced()
{
    return lastReplaced;
}

date item::getUpcomingCheck()
{
    return upcomingCheck;
}

date item::getUpcomingReplacement()
{
    return upcomingReplacement;
}

void item::setLastChecked(date d)
{
    lastChecked = d;
}

void item::setLastReplaced(date d)
{
    lastReplaced = d;
}

void item::setUpcomingCheck(date d)
{
    upcomingCheck = d;
}

void item::setUpcomingReplacement(date d)
{
    upcomingReplacement = d;
}

void item::checked(bool state, date d, double currentRange)
{
    checkDates.push_back(make_pair(state, dateAndRange(d, currentRange)));
}
void item::replaced(date d, double currentRange)
{
    replacementDates.push_back(dateAndRange(d, currentRange));
}