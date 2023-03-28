#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <ctime>
#include <math.h>
#include <bits/stdc++.h>

class Date {
public:
    Date(int day = 1, int month = 1, int year = 1970) {
        if (!is_valid(day, month, year)) {
            throw std::invalid_argument("Invalid date.");
        }
        day_ = day;
        month_ = month;
        year_ = year;
    }

    Date(const std::string& date_str) {
        std::stringstream ss(date_str);
        char sep;
        int day, month, year;
        ss >> day >> sep >> month >> sep >> year;
        if (!ss || sep != '/' || !is_valid(day, month, year)) {
            throw std::invalid_argument("Invalid date string.");
        }
        day_ = day;
        month_ = month;
        year_ = year;
    }

    int get_day() const {
        return day_;
    }

    int get_month() const {
        return month_;
    }

    int get_year() const {
        return year_;
    }

    Date add_days(int days) const {
        std::tm time = { 0, 0, 0, day_, month_ - 1, year_ - 1900 };
        std::time_t time_stamp = std::mktime(&time);
        time_stamp += days * 86400;
        std::tm* new_time = std::gmtime(&time_stamp);
        return Date(new_time->tm_mday, new_time->tm_mon + 1, new_time->tm_year + 1900);
    }

    int days_until(const Date& other) const {
        std::tm t1 = { 0, 0, 0, day_, month_ - 1, year_ - 1900 };
        std::tm t2 = { 0, 0, 0, other.day_, other.month_ - 1, other.year_ - 1900 };
        std::time_t time1 = std::mktime(&t1);
        std::time_t time2 = std::mktime(&t2);
        double seconds = std::difftime(time2, time1);
        return static_cast<int>(seconds / 86400);
    }

private:
    int day_;
    int month_;
    int year_;

    bool is_valid(int day, int month, int year) const {
        if (year < 0 || year > 9999 || month < 1 || month > 12) {
            return false;
        }
        int max_day = 31;
        if (month == 4 || month == 6 || month == 9 || month == 11) {
            max_day = 30;
        }
        else if (month == 2) {
            max_day = 28;
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                max_day = 29;
            }
        }
        return day >= 1 && day <= max_day;
    }
};

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.get_day() << '/' << date.get_month() << '/' << date.get_year();
    return os;
}

int main() {
    try {
        Date date1(27, 3, 2023);
        std::cout << "Date 1: " << date1 << '\n';
        Date date2("28/3/2023");
        std::cout << "Date 2: " << date2 << '\n';

        int days = date2 - date1;
        std::cout << "Number of days between Date 1 and Date 2: " << days << '\n';

        Date date3 = date1 + 10;
        std::cout << "Date 3 (10 days after Date 1): " << date3 << '\n';

        Date date4 = date2-5;
        std::cout << "Date 4 (5 days before Date 2): " << date2 << '\n';
    }
}
