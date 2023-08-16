#ifndef PART_H
#define PART_H

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "date.h"
#include "dateAndRange.h"
using namespace std;

class part
{
private:
    // check and replacement
    dateAndRange lastChecked;
    dateAndRange lastReplaced;
    dateAndRange upcomingCheck;
    dateAndRange upcomingReplacement;
    dateAndRange beforeRegularCheck;
    dateAndRange beforeRegularReplacement;
    string notes;
    string name;

    // statistics
    int timesChecked;
    int timesReplaced;
    int timesFailed;
    dateAndRange avgLifetime; // calculated on driver's actual usage

public:
    part();
    // part(dateAndRange p_lastChecked,
    //      dateAndRange p_lastReplaced,
    //      dateAndRange p_upcomingCheck,
    //      dateAndRange p_upcomingReplacement,
    //      dateAndRange p_avgLifetime,
    //      dateAndRange p_beforeRegularCheck,
    //      dateAndRange p_beforeRegularReplacement,
    //      int p_timesChecked,
    //      int p_timesReplaced,
    //      int p_timesFailed,
    //      string p_notes,
    //      vector<pair<bool, dateAndRange>> p_checkDates,
    //      vector<dateAndRange> p_replacementDates,
    //      vector<dateAndRange> p_failureDates);

    vector<pair<bool, dateAndRange>> checkDates;
    vector<dateAndRange> replacementDates;
    vector<dateAndRange> failureDates;

    dateAndRange getLastChecked();
    dateAndRange getLastReplaced();
    dateAndRange getUpcomingCheck();
    dateAndRange getUpcomingReplacement();
    dateAndRange getAvgLifeTime();
    string getNotes();
    string getName();

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
    void setName(string s);

    void checked(bool state, date d, double currentRange);
    void replaced(date d, double currentRange);
};
#endif