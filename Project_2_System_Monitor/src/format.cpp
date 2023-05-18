#include "format.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds_) {
  int hour, minutes, seconds;
  std::stringstream out_str;
  hour = (seconds_ / 3600) % 100;  // Number of hours returns to 0 after 99
  minutes = (seconds_ / 60) % 60;
  seconds = seconds_ % 60;
  out_str << std::setfill('0') << std::setw(2) << hour << ":"
          << std::setfill('0') << std::setw(2) << minutes << ":"
          << std::setfill('0') << std::setw(2) << seconds;
  return out_str.str();
}