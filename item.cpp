#include "item.h"

item::item()
{
    lastChecked = dateAndRange(date(0, 0, 0), 0);
    lastReplaced = dateAndRange(date(0, 0, 0), 0);
    upcomingCheck = dateAndRange(date(0, 0, 0), 0);
    upcomingReplacement = dateAndRange(date(0, 0, 0), 0);
    avgLifetime = dateAndRange(date(0, 0, 0), 0);
    beforeRegularCheck = dateAndRange(date(0, 0, 0), 0);
    beforeRegularReplacement = dateAndRange(date(0, 0, 0), 0);
    timesChecked = 0;
    timesReplaced = 0;
    timesFailed = 0;
    notes = "";
}

item::item(dateAndRange p_lastChecked,
           dateAndRange p_lastReplaced,
           dateAndRange p_upcomingCheck,
           dateAndRange p_upcomingReplacement,
           dateAndRange p_avgLifetime,
           dateAndRange p_beforeRegularCheck,
           dateAndRange p_beforeRegularReplacement,
           int p_timesChecked,
           int p_timesReplaced,
           int p_timesFailed,
           string p_notes,
           vector<pair<bool, dateAndRange>> p_checkDates,
           vector<dateAndRange> p_replacementDates,
           vector<dateAndRange> p_failureDates)
{
    lastChecked = p_lastChecked;
    lastReplaced = p_lastReplaced;
    upcomingCheck = p_upcomingCheck;
    upcomingReplacement = p_upcomingReplacement;
    avgLifetime = p_avgLifetime;
    beforeRegularCheck = p_beforeRegularCheck;
    beforeRegularReplacement = p_beforeRegularReplacement;
    timesChecked = p_timesChecked;
    timesReplaced = p_timesReplaced;
    timesFailed = p_timesFailed;
    notes = p_notes;

    checkDates = p_checkDates;
    replacementDates = p_replacementDates;
    failureDates = p_failureDates;
}

dateAndRange item::getLastChecked()
{
    return lastChecked;
}

dateAndRange item::getLastReplaced()
{
    return lastReplaced;
}

dateAndRange item::getUpcomingCheck()
{
    return upcomingCheck;
}

dateAndRange item::getUpcomingReplacement()
{
    return upcomingReplacement;
}

void item::setLastChecked(dateAndRange d)
{
    lastChecked = d;
}

void item::setLastReplaced(dateAndRange d)
{
    lastReplaced = d;
    upcomingReplacement.setRange(d.getRange() + beforeRegularReplacement.getRange());
    // adjust here for also time period detection
}

void item::setUpcomingCheck(dateAndRange d)
{
    upcomingCheck = d;
}

void item::setUpcomingReplacement(dateAndRange d)
{
    upcomingReplacement = d;
}

void item::setAvgLifetime(dateAndRange d)
{
    avgLifetime = d;
}

void item::setBeforeRegularCheck(dateAndRange d)
{
    beforeRegularCheck = d;
}

void item::setBeforeRegularReplacement(dateAndRange d)
{
    beforeRegularReplacement = d;
    beforeRegularReplacement.setRange(beforeRegularReplacement.getRange() * 1000);
}

void item::setTimesChecked(int n)
{
    timesChecked = n;
}

void item::setTimesReplaced(int n)
{
    timesReplaced = n;
}

void item::setTimesFailed(int n)
{
    timesFailed = n;
}

void item::setNotes(string s)
{
    notes = s;
}

void item::checked(bool state, date d, double currentRange)
{
    checkDates.push_back(make_pair(state, dateAndRange(d, currentRange)));
}
void item::replaced(date d, double currentRange)
{
    replacementDates.push_back(dateAndRange(d, currentRange));
}