/*
    Assumptions: Every month is 31 days long
    To-Do: - File handling system to store previous dates
           - Save or discard option in file handling
           - Fully implement item.cpp
           - Implement statistical functions
*/

#include <iostream>

#include "date.h"
#include "dateAndRange.h"
#include "motorOilAndFilter.h"
#include "coolingFluid.h"
#include "sparkPlug.h"
#include "fuelFilter.h"
#include "airFilter.h"
#include "brakeOil.h"
#include "gearboxOil.h"
#include "brakePadsFront.h"
#include "brakePadsBack.h"
#include "battery.h"
#include "fuelPump.h"
#include "tyresFront.h"
#include "tyresBack.h"
#include "airConditionerFilter.h"

using namespace std;

motorOilAndFilter p1;
coolingFluid p2;
sparkPlug p3;
fuelFilter p4;
airFilter p5;
brakeOil p6;
gearboxOil p7;
brakePadsFront p8;
brakePadsBack p9;
battery p10;
fuelPump p11;
tyresFront p12;
tyresBack p13;
airConditionerFilter p14;

void check(dateAndRange in);
void checkNextKM(dateAndRange in, double KM);

int main()
{
    // motorOilAndFilter p1;
    p1.setBeforeRegularReplacement(dateAndRange(date(0, 12, 0), 10));
    date d1(13, 6, 2023);
    dateAndRange dr1(d1, 157180);
    p1.setLastReplaced(dr1); // 13/6/2023 157180 KM

    // coolingFluid p2;
    p2.setBeforeRegularReplacement(dateAndRange(date(0, 24, 0), 40));
    date d2(17, 12, 2021);
    dateAndRange dr2(d2, 127000);
    p2.setLastReplaced(dr2); // 17/12/2021 127000 KM         //// 23/1/2023 148000 KM

    // sparkPlug p3;
    p3.setBeforeRegularReplacement(dateAndRange(date(0, 0, 0), 100));
    date d3(9, 9, 2022);
    dateAndRange dr3(d3, 139863);
    p3.setLastReplaced(dr3); // 9/9/2022 139863 KM

    // fuelFilter p4;
    p4.setBeforeRegularReplacement(dateAndRange(date(0, 96, 0), 80));
    date d4(28, 11, 2021);
    dateAndRange dr4(d4, 125552);
    p4.setLastReplaced(dr4); // 28/11/2021 125552 KM

    // airFilter p5;
    p5.setBeforeRegularReplacement(dateAndRange(date(0, 48, 0), 40));
    p5.setBeforeRegularCheck(dateAndRange(date(0, 24, 0), 20));
    date d5(13, 6, 2023);
    dateAndRange dr5(d5, 157180);
    p5.setLastReplaced(dr5); // 13/6/2023 157180 KM

    // brakeOil p6;
    p6.setBeforeRegularReplacement(dateAndRange(date(0, 24, 0), 40));
    p6.setBeforeRegularCheck(dateAndRange(date(0, 6, 0), 10));
    date d6(17, 12, 2021);
    dateAndRange dr6(d6, 127000);
    p6.setLastReplaced(dr6); // 17/12/2021 127000 KM

    // gearboxOil p7;
    p7.setBeforeRegularReplacement(dateAndRange(date(0, 24, 0), 80)); // 24 or 48?
    p7.setBeforeRegularCheck(dateAndRange(date(0, 24, 2), 40));
    date d7(30, 11, 2019);
    dateAndRange dr7(d7, 101077);
    p7.setLastReplaced(dr7); // 30/11/2019 101077 KM

    // brakePadsFront p8;
    p8.setBeforeRegularReplacement(dateAndRange(date(0, 24, 0), 80)); // 24 or 48?
    p8.setBeforeRegularCheck(dateAndRange(date(0, 24, 2), 40));
    date d8(3, 12, 2021);
    dateAndRange dr8(d8, 125800);
    p8.setLastReplaced(dr8);
    // brake pads front 3/12/2021 125800 KM

    // brakePadsBack p9;
    p9.setBeforeRegularReplacement(dateAndRange(date(0, 24, 0), 80)); // 24 or 48?
    p9.setBeforeRegularCheck(dateAndRange(date(0, 24, 2), 40));
    date d9(10, 1, 2020);
    dateAndRange dr9(d9, 102472);
    p9.setLastReplaced(dr9);
    // brake pads back 10/1/2020 102472 KM

    // battery p10;
    p10.setBeforeRegularReplacement(dateAndRange(date(0, 24, 0), 80)); // 24 or 48?
    p10.setBeforeRegularCheck(dateAndRange(date(0, 24, 2), 40));
    date d10(9, 5, 2022);
    dateAndRange dr10(d10, 133505);
    p10.setLastReplaced(dr10);
    // battery 9/5/2022 133505 KM

    // fuelPump p11;
    p11.setBeforeRegularReplacement(dateAndRange(date(0, 24, 0), 80)); // 24 or 48?
    p11.setBeforeRegularCheck(dateAndRange(date(0, 24, 2), 40));
    date d11(30, 11, 2019);
    dateAndRange dr11(d11, 124565);
    p11.setLastReplaced(dr11);
    // fuel pump 4/11/2021 124565 KM

    // tyresFront p12;
    p12.setBeforeRegularReplacement(dateAndRange(date(0, 24, 0), 80)); // 24 or 48?
    p12.setBeforeRegularCheck(dateAndRange(date(0, 24, 2), 40));
    date d12(30, 11, 2019);
    dateAndRange dr12(d12, 150489);
    p12.setLastReplaced(dr12);
    // tyres front 16/3/2023 150489 KM

    // tyresBack p13;
    p13.setBeforeRegularReplacement(dateAndRange(date(0, 24, 0), 80)); // 24 or 48?
    p13.setBeforeRegularCheck(dateAndRange(date(0, 24, 2), 40));
    date d13(30, 11, 2019);
    dateAndRange dr13(d13, 85179);
    p13.setLastReplaced(dr13);
    // tyres back 7/11/2018 85179 KM

    // airConditionerFilter p14;
    p14.setBeforeRegularReplacement(dateAndRange(date(0, 24, 0), 80)); // 24 or 48?
    p14.setBeforeRegularCheck(dateAndRange(date(0, 24, 2), 40));
    date d14(30, 11, 2019);
    dateAndRange dr14(d14, 157180);
    p14.setLastReplaced(dr14);
    // ACfilter 13/6/2023 157180 KM

    double carRange;
    cout << "Please enter car range: ";
    cin >> carRange;

    int day, month, year;
    cout << "\nPlease enter the date as \"DD MM YYYY\" : ";
    cin >> day >> month >> year;

    check(dateAndRange(date(day, month, year), carRange));

    return 0;
}

void check(dateAndRange in)
{
    if (p1.getUpcomingReplacement().getRange() < in.getRange())
    {
        cout
            << "\nMotor oil and filter need to be replaced.";
    }

    if (p2.getUpcomingReplacement().getRange() < in.getRange())
    {
        cout << "\nCooling fluid needs to be replaced.";
    }

    if (p3.getUpcomingReplacement().getRange() < in.getRange())
    {
        cout << "\nSpark plugs need to be replaced.";
    }

    if (p4.getUpcomingReplacement().getRange() < in.getRange())
    {
        cout << "\nFuel filter needs to be replaced.";
    }

    if (p5.getUpcomingReplacement().getRange() < in.getRange())
    {
        cout << "\nAir filter needs to be replaced.";
    }

    if (p6.getUpcomingReplacement().getRange() < in.getRange())
    {
        cout << "\nBrake oil needs to be replaced.";
    }

    if (p7.getUpcomingReplacement().getRange() < in.getRange())
    {
        cout << "\nGearbox oil needs to be replaced.";
    }

    if (p8.getUpcomingReplacement().getRange() < in.getRange())
    {
        cout << "\nFront brake pads need to be replaced.";
    }

    if (p9.getUpcomingReplacement().getRange() < in.getRange())
    {
        cout << "\nBack brake pads need to be replaced.";
    }

    if (p10.getUpcomingReplacement().getRange() < in.getRange())
    {
        cout << "\nBattery needs to be replaced.";
    }

    if (p11.getUpcomingReplacement().getRange() < in.getRange())
    {
        cout << "\nFuel pump needs to be replaced.";
    }

    if (p12.getUpcomingReplacement().getRange() < in.getRange())
    {
        cout << "\nFront tyres need to be replaced.";
    }

    if (p13.getUpcomingReplacement().getRange() < in.getRange())
    {
        cout << "\nBack tyres need to be replaced.";
    }

    if (p14.getUpcomingReplacement().getRange() < in.getRange())
    {
        cout << "\nAir conditioner filter needs to be replaced.";
    }
}

void checkNextKM(dateAndRange in, double KM)
{
    in.setRange(in.getRange() + KM);
    check(in);
}