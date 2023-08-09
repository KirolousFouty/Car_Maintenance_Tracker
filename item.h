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
    dateAndRange avgLifetime;
    dateAndRange beforeRegularCheck;
    dateAndRange beforeRegularReplacement;
    int timesChecked;
    int timesReplaced;
    int timesFailed;
    string notes;

    vector<pair<bool, dateAndRange>> checkDates;
    vector<dateAndRange> replacementDates;
    vector<dateAndRange> failureDates;

public:
    item();
    item(dateAndRange p_lastChecked,
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
         vector<dateAndRange> p_failureDates);

    dateAndRange getLastChecked();
    dateAndRange getLastReplaced();
    dateAndRange getUpcomingCheck();
    dateAndRange getUpcomingReplacement();

    void setLastChecked(dateAndRange d);
    void setLastReplaced(dateAndRange d);
    void setUpcomingCheck(dateAndRange d);
    void setUpcomingReplacement(dateAndRange d);
    void setAvgLifetime(dateAndRange d);
    void setBeforeRegularCheck(dateAndRange d);
    void setBeforeRegularReplacement(dateAndRange d);

    void setTimesChecked(int n);
    void setTimesReplaced(int n);
    void setTimesFailed(int n);
    void setNotes(string s);

    void checked(bool state, date d, double currentRange);
    void replaced(date d, double currentRange);
};
#endif