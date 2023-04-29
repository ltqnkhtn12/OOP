#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getDaysInMonth(int month, int year) {
    switch (month) {
    case 2:
        return isLeapYear(year) ? 29 : 28;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    default:
        return 31;
    }
}

struct Date {
    int day;
    int month;
    int year;
};

Date getNextDate(Date currentDate) {
    int daysInMonth = getDaysInMonth(currentDate.month, currentDate.year);

    if (currentDate.day < daysInMonth) {
        currentDate.day++;
    }
    else {
        currentDate.day = 1;

        if (currentDate.month < 12) {
            currentDate.month++;
        }
        else {
            currentDate.month = 1;
            currentDate.year++;
        }
    }

    return currentDate;
}

int main() {
    Date currentDate;

    cout << "Enter the date (dd/mm/yyyy): ";
    cin >> currentDate.day >> currentDate.month >> currentDate.year;

    Date nextDate = getNextDate(currentDate);

    cout << "The next date is: " << nextDate.day << "/" << nextDate.month << "/" << nextDate.year << endl;

    return 0;
}
