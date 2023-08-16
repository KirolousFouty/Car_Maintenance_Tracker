/*
    Assumptions: Every month is 31 days long
    To-Do: - File handling system to store previous dates
           - Save or discard option in file handling
           - Fully implement part.cpp
           - Implement statistical functions
*/

#include <iostream>
#include <iomanip>
#include <vector>

#include "date.h"
#include "dateAndRange.h"
#include "part.h"

using namespace std;

vector<part> parts;

void check(dateAndRange in);
void checkNextKM(dateAndRange in, double KM);
void printList();
void printLastReplaced();
void printUpcomingReplacement();

void mainMenu();
void checkMenu();
void updateMenu();
void notesMenu();
void historyMenu();

int main()
{

    part motorOilAndFilter;
    part coolingFluid;
    part sparkPlug;
    part fuelFilter;
    part airFilter;
    part brakeOil;
    part gearboxOil;
    part brakePadsFront;
    part brakePadsBack;
    part battery;
    part fuelPump;
    part tyresFront;
    part tyresBack;
    part airConditionerFilter;

    airConditionerFilter.setBeforeRegularReplacement(dateAndRange(date(0, 24, 0), 80)); // 24 or 48?
    airConditionerFilter.setBeforeRegularCheck(dateAndRange(date(0, 24, 2), 40));
    airConditionerFilter.setName("Air conditioner filter");
    airConditionerFilter.setLastReplaced(dateAndRange(date(30, 11, 2019), 157180));
    // ACfilter 13/6/2023 157180 KM

    airFilter.setBeforeRegularReplacement(dateAndRange(date(0, 48, 0), 40));
    airFilter.setBeforeRegularCheck(dateAndRange(date(0, 24, 0), 20));
    airFilter.setName("Air filter");
    airFilter.setLastReplaced(dateAndRange(date(13, 6, 2023), 157180));
    // 13/6/2023 157180 KM

    battery.setBeforeRegularReplacement(dateAndRange(date(0, 24, 0), 80)); // 24 or 48?
    battery.setBeforeRegularCheck(dateAndRange(date(0, 24, 2), 40));
    battery.setName("Battery");
    battery.setLastReplaced(dateAndRange(date(9, 5, 2022), 133505));
    // battery 9/5/2022 133505 KM

    brakeOil.setBeforeRegularReplacement(dateAndRange(date(0, 24, 0), 40));
    brakeOil.setBeforeRegularCheck(dateAndRange(date(0, 6, 0), 10));
    brakeOil.setName("Brake oil");
    brakeOil.setLastReplaced(dateAndRange(date(17, 12, 2021), 127000)); // 17/12/2021 127000 KM

    brakePadsBack.setBeforeRegularReplacement(dateAndRange(date(0, 24, 0), 80)); // 24 or 48?
    brakePadsBack.setBeforeRegularCheck(dateAndRange(date(0, 24, 2), 40));
    brakePadsBack.setName("Brake pads - back");
    brakePadsBack.setLastReplaced(dateAndRange(date(10, 1, 2020), 102472));
    // brake pads back 10/1/2020 102472 KM

    brakePadsFront.setBeforeRegularReplacement(dateAndRange(date(0, 24, 0), 80)); // 24 or 48?
    brakePadsFront.setBeforeRegularCheck(dateAndRange(date(0, 24, 2), 40));
    brakePadsFront.setName("Brake pads - front");
    brakePadsFront.setLastReplaced(dateAndRange(date(3, 12, 2021), 125800));
    // brake pads front 3/12/2021 125800 KM

    coolingFluid.setBeforeRegularReplacement(dateAndRange(date(0, 24, 0), 40));
    coolingFluid.setName("Cooling fluid");
    coolingFluid.setLastReplaced(dateAndRange(date(17, 12, 2021), 127000)); // 17/12/2021 127000 KM         //// 23/1/2023 148000 KM

    fuelFilter.setBeforeRegularReplacement(dateAndRange(date(0, 96, 0), 80));
    fuelFilter.setName("Fuel filter");
    fuelFilter.setLastReplaced(dateAndRange(date(28, 11, 2021), 125552)); // 28/11/2021 125552 KM

    fuelPump.setBeforeRegularReplacement(dateAndRange(date(0, 24, 0), 80)); // 24 or 48?
    fuelPump.setBeforeRegularCheck(dateAndRange(date(0, 24, 2), 40));
    fuelPump.setName("Fuel pump");
    fuelPump.setLastReplaced(dateAndRange(date(30, 11, 2019), 124565));
    // fuel pump 4/11/2021 124565 KM

    gearboxOil.setBeforeRegularReplacement(dateAndRange(date(0, 24, 0), 80)); // 24 or 48?
    gearboxOil.setBeforeRegularCheck(dateAndRange(date(0, 24, 2), 40));
    gearboxOil.setName("Gearbox oil");
    gearboxOil.setLastReplaced(dateAndRange(date(30, 11, 2019), 101077)); // 30/11/2019 101077 KM

    motorOilAndFilter.setBeforeRegularReplacement(dateAndRange(date(0, 12, 0), 10));
    motorOilAndFilter.setName("Motor oil and filter");
    motorOilAndFilter.setLastReplaced(dateAndRange(date(13, 6, 2023), 157180)); // 13/6/2023 157180 KM

    sparkPlug.setBeforeRegularReplacement(dateAndRange(date(0, 0, 0), 100));
    sparkPlug.setName("Spark plugs");
    sparkPlug.setLastReplaced(dateAndRange(date(9, 9, 2022), 139863)); // 9/9/2022 139863 KM

    tyresBack.setBeforeRegularReplacement(dateAndRange(date(0, 24, 0), 80)); // 24 or 48?
    tyresBack.setBeforeRegularCheck(dateAndRange(date(0, 24, 2), 40));
    tyresBack.setName("Tyres - back");
    tyresBack.setLastReplaced(dateAndRange(date(30, 11, 2019), 85179));
    // tyres back 7/11/2018 85179 KM

    tyresFront.setBeforeRegularReplacement(dateAndRange(date(0, 24, 0), 80)); // 24 or 48?
    tyresFront.setBeforeRegularCheck(dateAndRange(date(0, 24, 2), 40));
    tyresFront.setName("Tyres - front");
    tyresFront.setLastReplaced(dateAndRange(date(30, 11, 2019), 150489));
    // tyres front 16/3/2023 150489 KM

    parts.push_back(airConditionerFilter);
    parts.push_back(airFilter);
    parts.push_back(battery);
    parts.push_back(brakeOil);
    parts.push_back(brakePadsBack);
    parts.push_back(brakePadsFront);
    parts.push_back(coolingFluid);
    parts.push_back(fuelFilter);
    parts.push_back(fuelPump);
    parts.push_back(gearboxOil);
    parts.push_back(motorOilAndFilter);
    parts.push_back(sparkPlug);
    parts.push_back(tyresBack);
    parts.push_back(tyresFront);

    cout << "\nWelcome!";

    mainMenu();

    return 0;
}

void check(dateAndRange in)
{
    cout << "\n\nNeeds to be replaced:";
    string s = " None";

    for (int i = 0; i < parts.size(); i++)
    {
        if (parts[i].getUpcomingReplacement().getRange() < in.getRange())
        {
            cout << "\n"
                 << parts[i].getName();
            s = "";
        }
    }
    cout << s;
    s = " None";

    cout << "\n\nNeeds to be replaced in the next 500 KMs:";
    for (int i = 0; i < parts.size(); i++)
    {
        if (parts[i].getUpcomingReplacement().getRange() + 500 < in.getRange())
        {
            cout << "\n"
                 << parts[i].getName();
            s = "";
        }
    }
    cout << s;
}

void printList()
{
    cout << "\n1) Air conditioner filter";
    cout << "\n2) Air filter";
    cout << "\n3) Battery";
    cout << "\n4) Brake oil";
    cout << "\n5) Brake pads - back";
    cout << "\n6) Brake pads - front";
    cout << "\n7) Cooling fluid";
    cout << "\n8) Fuel filter";
    cout << "\n9) Fuel pump";
    cout << "\n10) Gearbox oil";
    cout << "\n11) Motor oil and filter";
    cout << "\n12) Spark plugs";
    cout << "\n13) Tyres - back";
    cout << "\n14) Tyres - front";
}

void printLastReplaced()
{
    cout << "\n\n\nHere is a list of the last replacement of every part:\n";
    for (int i = 0; i < parts.size(); i++)
    {
        cout << "\n"
             << left << setw(26) << parts[i].getName();
        parts[i].getLastReplaced().getDate().printDate();
        cout << " at " << parts[i].getLastReplaced().getRange();
        cout << " Kms";
    }
}

void printUpcomingReplacement()
{
    cout << "\n\n\nHere is a list of the upcoming replacement of every part:\n";
    for (int i = 0; i < parts.size(); i++)
    {
        cout << "\n"
             << left << setw(26) << parts[i].getName();
        cout << parts[i].getUpcomingReplacement().getRange();
        cout << " Kms";
    }
}

void mainMenu()
{
    int choice = 0;
    while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5)
    {
        cout << "\n\n\nPlease choose what you wish to do:";
        cout << "\n1) Check";
        cout << "\n2) Update record";
        cout << "\n3) Show notes";
        cout << "\n4) Show part history";
        cout << "\n5) Show last replacement of every part";
        cout << "\n6) Show upcoming replacements of every part";
        cout << "\n7) Exit";
        cout << "\n\nAnswer: ";
        cin >> choice;
    }

    switch (choice)
    {
    case 1:
        checkMenu();
        break;
    case 2:
        updateMenu();
        break;
    case 3:
        notesMenu();
        break;
    case 4:
        historyMenu();
        break;
    case 5:
        printLastReplaced();
        break;
    case 6:
        printUpcomingReplacement();
        break;
    case 7:
        cout << "\n\nThank you for using our application!\n\n";
        exit(0);
        break;

    default:
        cout << "\n\nERROR\n\n";
        break;
    }
}

void checkMenu()
{
    double carRange;
    cout << "Please enter car range: ";
    cin >> carRange;

    int day, month, year;
    cout << "\nPlease enter the date as \"DD MM YYYY\" : ";
    cin >> day >> month >> year;

    check(dateAndRange(date(day, month, year), carRange));
    mainMenu();
}

void updateMenu()
{

    int choice = 0;

    while (choice != 1 && choice != 2)
    {
        cout << "\n\nWhat do you want to update?";
        cout << "\n 1) Replacement";
        cout << "\n 2) Notes";
        cout << "\n\nAnswer: ";
        cin >> choice;
    }

    if (choice == 1)
    {
        double inRange;
        int inDay;
        int inMonth;
        int inYear;

        choice = 0;
        cout << "\n\nWhat part did you replace?";
        printList();
        cout << "\n\nAnswer: ";
        cin >> choice;
        cout << "\nEnter range at replacement: ";
        cin >> inRange;
        cout << "\nEnter day of date at replacement: ";
        cin >> inDay;
        cout << "\nEnter month of date at replacement: ";
        cin >> inMonth;
        cout << "\nEnter year of date at replacement: ";
        cin >> inYear;
        parts[choice].setLastReplaced(dateAndRange(date(inDay, inMonth, inYear), inRange));
        cout << "\n\nRecord updated!";
    }
    else if (choice == 2)
    {
        string note;

        choice = 0;
        cout << "\n\nWhat part do you want to add note to?";
        printList();
        cout << "\n\nAnswer: ";
        cin >> choice;
        cout << "\nEnter your note: ";
        cin >> note;
        parts[choice].setNotes(note);
        cout << "\n\nNotes updated!";
    }

    mainMenu();
}

void historyMenu()
{
    int choice = 0;
    cout << "\n\nWhich part do you want to show history?";
    printList();
    cout << "\n\nAnswer: ";
    cin >> choice;
    cout << "\n\nReplacements were as follows:";
    for (int i = 0; i < parts[choice].replacementDates.size(); i++)
    {
        cout << "\n";
        parts[choice].replacementDates[i].getDate().printDate();
        cout << " at " << parts[choice].replacementDates[i].getRange() << " KMs";
    }
}

void notesMenu()
{
    int choice = 0;
    cout << "\n\nWhich part do you want to show notes?";
    printList();
    cout << "\n\nAnswer: ";
    cin >> choice;
    cout << "\n\nNotes:\n"
         << parts[choice].getNotes();
    mainMenu();
}
