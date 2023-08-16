#include "part.h"

part::part()
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
    name = "";
}

// part::part(dateAndRange p_lastChecked,
//            dateAndRange p_lastReplaced,
//            dateAndRange p_upcomingCheck,
//            dateAndRange p_upcomingReplacement,
//            dateAndRange p_avgLifetime,
//            dateAndRange p_beforeRegularCheck,
//            dateAndRange p_beforeRegularReplacement,
//            int p_timesChecked,
//            int p_timesReplaced,
//            int p_timesFailed,
//            string p_notes,
//            vector<pair<bool, dateAndRange>> p_checkDates,
//            vector<dateAndRange> p_replacementDates,
//            vector<dateAndRange> p_failureDates)
// {
//     lastChecked = p_lastChecked;
//     lastReplaced = p_lastReplaced;
//     upcomingCheck = p_upcomingCheck;
//     upcomingReplacement = p_upcomingReplacement;
//     avgLifetime = p_avgLifetime;
//     beforeRegularCheck = p_beforeRegularCheck;
//     beforeRegularReplacement = p_beforeRegularReplacement;
//     timesChecked = p_timesChecked;
//     timesReplaced = p_timesReplaced;
//     timesFailed = p_timesFailed;
//     notes = p_notes;

//     checkDates = p_checkDates;
//     replacementDates = p_replacementDates;
//     failureDates = p_failureDates;
// }

dateAndRange part::getLastChecked()
{
    return lastChecked;
}

dateAndRange part::getLastReplaced()
{
    return lastReplaced;
}

dateAndRange part::getUpcomingCheck()
{
    return upcomingCheck;
}

dateAndRange part::getUpcomingReplacement()
{
    return upcomingReplacement;
}

dateAndRange part::getAvgLifeTime()
{
    date d = date(0, 0, 0);
    double r = 0;

    for (int i = 0; i < replacementDates.size(); i++)
    {
        d = d + replacementDates[i].getDate();
        r += replacementDates[i].getRange();
    }
    d = d / replacementDates.size();
    r /= replacementDates.size();

    setAvgLifetime(dateAndRange(d, r));
    return dateAndRange(d, r);
}

string part::getNotes()
{
    return notes;
}

string part::getName()
{
    return name;
}

void part::setLastChecked(dateAndRange d)
{
    lastChecked = d;
}

void part::setLastReplaced(dateAndRange d)
{
    lastReplaced = d;
    upcomingReplacement.setRange(d.getRange() + beforeRegularReplacement.getRange());
    replacementDates.push_back(d);
    // adjust here for also time period detection
}

void part::setUpcomingCheck(dateAndRange d)
{
    upcomingCheck = d;
}

void part::setUpcomingReplacement(dateAndRange d)
{
    upcomingReplacement = d;
}

void part::setAvgLifetime(dateAndRange d)
{
    avgLifetime = d;
}

void part::setBeforeRegularCheck(dateAndRange d)
{
    beforeRegularCheck = d;
}

void part::setBeforeRegularReplacement(dateAndRange d)
{
    beforeRegularReplacement = d;
    beforeRegularReplacement.setRange(beforeRegularReplacement.getRange() * 1000);
}

void part::setTimesChecked(int n)
{
    timesChecked = n;
}

void part::setTimesReplaced(int n)
{
    timesReplaced = n;
}

void part::setTimesFailed(int n)
{
    timesFailed = n;
}

void part::setNotes(string s)
{
    notes = s;
}

void part::setName(string s)
{
    name = s;
}

void part::checked(bool state, date d, double currentRange)
{
    checkDates.push_back(make_pair(state, dateAndRange(d, currentRange)));
}
void part::replaced(date d, double currentRange)
{
    replacementDates.push_back(dateAndRange(d, currentRange));
}