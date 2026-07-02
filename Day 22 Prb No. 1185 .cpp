#include <iostream>
#include <vector>
using namespace std;

string dayOfTheWeek(int day, int month, int year) {

    vector<string> week = {"Sunday", "Monday", "Tuesday", "Wednesday",
                           "Thursday", "Friday", "Saturday"};

    vector<int> days = {31,28,31,30,31,30,31,31,30,31,30,31};

    int totalDays = 0;

    for (int y = 1971; y < year; y++) {
        totalDays += 365;

        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
            totalDays++;
    }

    for (int m = 1; m < month; m++) {
        totalDays += days[m - 1];
    }

    if (month > 2 &&
        ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
        totalDays++;

    totalDays += day;

    return week[(totalDays + 4) % 7];
}

int main() {

    int day, month, year;

    cout << "Enter day month year: ";
    cin >> day >> month >> year;

    cout << dayOfTheWeek(day, month, year);

    return 0;
}