#include <iostream>
#include <ctime>
#include <cstring>
#include <sstream>
#include <iomanip>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;
public:
    Date(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
        if (!isValid()) {
            throw std::invalid_argument("Invalid date.");
        }
    }

    Date(std::string& str) {
        std::istringstream ss(str);
        char c;
        ss >> day >> c >> month >> c >> year;
        if (!ss || c != '/') {
            throw std::invalid_argument("Invalid date format.");
        }
        if (!isValid()) {
            throw std::invalid_argument("Invalid date.");
        }
    }

    bool isLeapYear() {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    bool isValid() {
        if (year < 1 || year > 9999 || month < 1 || month > 12 || day < 1 || day > 31) {
            return false;
        }

        if (month == 2) {
            if (isLeapYear()) {
                return day <= 29;
            }
            else {
                return day <= 28;
            }
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11) {
            return day <= 30;
        }

        return true;
    }

    // Hàm cộng ngày tháng năm
    Date add(Date d, int numDays) {
        int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        d.day += numDays;
        while (d.day > daysInMonth[d.month - 1]) {
            d.day -= daysInMonth[d.month - 1];
            ++d.month;
            if (d.month > 12) {
                d.month = 1;
                ++d.year;
                if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0) {
                    daysInMonth[1] = 29;
                }
                else {
                    daysInMonth[1] = 28;
                }
            }
        }
        return d;
    }

    // Hàm trừ ngày tháng năm
    Date subtract(Date d, int numDays) {
        int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        d.day -= numDays;
        while (d.day < 1) {
            --d.month;
            if (d.month < 1) {
                d.month = 12;
                --d.year;
                if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0) {
                    daysInMonth[1] = 29;
                }
                else {
                    daysInMonth[1] = 28;
                }
            }
            d.day += daysInMonth[d.month - 1];
        }
        return d;
    }

    // Hàm tính khoảng cách ngày tháng năm
    int distance(Date d1, Date d2) {
        int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        int days1 = d1.day;
        for (int i = 0; i < d1.month - 1; ++i) {
            days1 += daysInMonth[i];
        }
        days1 += (d1.year - 1) * 365 + (d1.year - 1) / 4 - (d1.year - 1) / 100 + (d1.year - 1) / 400;

        int days2 = d2.day;
        for (int i = 0; i < d2.month - 1; ++i) {
            days2 += daysInMonth[i];
        }
        days2 += (d2.year - 1) * 365 + (d2.year - 1) / 4 - (d2.year - 1) / 100 + (d2.year - 1) / 400;

        return abs(days2 - days1);
    }

    int main() {
        Date d1 = { 30, 3, 2023 };
        Date d2 = { 10, 4, 2023 };

        // In ngày tháng năm
        cout << "Date 1: " << d1.day << "/" << d1.month << "/" << d1.year << endl;
        cout << "Date 2: " << d2.day << "/" << d2.month << "/" << d2.year << endl;

        // Cộng thêm 5 ngày vào ngày d1
        d1 = add(d1, 5);
        cout << "Date 1 sau khi cong 5 ngay la : " << d1.day << " / " << d1.month << " / " << d1.year << endl;

        // Trừ đi 15 ngày từ ngày d2
        d2 = subtract(d2, 15);
        cout << "Date 2 sau khi tru 15 ngay la : " << d2.day << " / " << d2.month << " / " << d2.year << endl;

        // Tính khoảng cách giữa ngày d1 và d2
        int days = distance(d1, d2);
        cout << "Khoang cach ngay giua date 2 va date 1 la: " << days << " ngay" << endl;

        return 0;
    }
};





