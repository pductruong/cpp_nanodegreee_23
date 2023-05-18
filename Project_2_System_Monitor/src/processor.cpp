#include "processor.h"

#include "linux_parser.h"

// Returning the aggregate CPU utilization
float Processor::Utilization() {
  long totalCPU = LinuxParser::Jiffies();
  long current = LinuxParser::ActiveJiffies();
  return current * (1.f / totalCPU);
}