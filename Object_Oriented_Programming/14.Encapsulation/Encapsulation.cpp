#include <cassert>
#include <iostream>

class Date {
public:
  Date(int day, int month, int year);
  int Day() const { return day_; }
  void Day(int day);
  int Month() const { return month_; }
  void Month(int month);
  int Year() const { return year_; }
  void Year(int year);
  int DaysInMonth() {
    if (year_ % 4 == 0) {
      return 29;
    } else if (year_ % 4 != 0 && month_ == 2) {
      return 28;
    }
    switch (month_) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      std::cout << "1"
                << "\n";
      return 31;
      break;
    default:
      std::cout << "2"
                << "\n";
      return 30;
      break;
    }
  }

private:
  int day_{1};
  int month_{1};
  int year_{0};
};

Date::Date(int day, int month, int year) {
  Year(year);
  Month(month);
  Day(day);
}

void Date::Day(int day) {
  if (day >= 1 && day <= Date::DaysInMonth())
    day_ = day;
}

void Date::Month(int month) {
  if (month >= 1 && month <= 12)
    month_ = month;
}

void Date::Year(int year) { year_ = year; }

// Test
int main() {
  Date date(28, 2, 1981);
  assert(date.Day() == 29);
  assert(date.Month() == 8);
  assert(date.Year() == 1981);
}