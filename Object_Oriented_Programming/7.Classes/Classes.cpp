#include <cassert>
#include <iostream>

class Date {
public:
  void Day(int d) {
    if (d >= 0 && d <= 31) {
      day = d;
    }
  }
  int Day() { return day; }
  void Month(int m) {
    if (m >= 0 && m <= 12) {
      month = m;
    }
  }
  int Month() { return month; }
  void Year(int y) { year = y; }
  int Year() { return year; }

private:
  int day;
  int month;
  int year;
};

// Test in main
int main() {
  Date date;
  date.Day(-1);
  date.Month(14);
  date.Year(2000);
  assert(date.Day() != -1);
  assert(date.Month() != 14);
  assert(date.Year() == 2000);
}
