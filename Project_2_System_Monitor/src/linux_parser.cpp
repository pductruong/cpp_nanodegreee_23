#include "linux_parser.h"

#include <dirent.h>
#include <unistd.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::stof;
using std::stoi;
using std::stol;
using std::string;
using std::to_string;
using std::vector;

// Read and return the name of the Operating System from the filesystem
string LinuxParser::OperatingSystem() {
  string line;
  string key;
  string value;
  std::ifstream filestream(kOSPath);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ' ', '_');
      std::replace(line.begin(), line.end(), '=', ' ');
      std::replace(line.begin(), line.end(), '"', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "PRETTY_NAME") {
          std::replace(value.begin(), value.end(), '_', ' ');
          return value;
        }
      }
    }
  }
  return value;
}

// Read and return the Kernel version from the filesystem
string LinuxParser::Kernel() {
  string os, version, kernel;
  string line;
  std::ifstream stream(kProcDirectory + kVersionFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> os >> version >> kernel;
  }
  return kernel;
}

// BONUS: Update this to use std::filesystem
vector<int> LinuxParser::Pids() {
  vector<int> pids;
  DIR* directory = opendir(kProcDirectory.c_str());
  struct dirent* file;
  while ((file = readdir(directory)) != nullptr) {
    // Is this a directory?
    if (file->d_type == DT_DIR) {
      // Is every character of the name a digit?
      string filename(file->d_name);
      if (std::all_of(filename.begin(), filename.end(), isdigit)) {
        int pid = stoi(filename);
        pids.push_back(pid);
      }
    }
  }
  closedir(directory);
  return pids;
}

// Read and return the system memory utilization
float LinuxParser::MemoryUtilization() {
  string line, name, value;
  string totalRam;
  string freeRam;
  std::ifstream stream(kProcDirectory + kMeminfoFilename);
  if (stream.is_open()) {
    while (std::getline(stream, line)) {
      std::istringstream linestream(line);
      while (linestream >> name >> value) {
        if (name == "MemTotal:") {
          totalRam = value;
        } else if (name == "MemFree:") {
          freeRam = value;
        }
      }
    }
  }
  stream.close();
  // std::cout << (stof(totalRam) - stof(freeRam)) / stof(totalRam) << "\n";
  return (stof(totalRam) - stof(freeRam)) / stof(totalRam);
}

// Read and return the system uptime
long LinuxParser::UpTime() {
  string upTime;
  string line;
  std::ifstream stream(kProcDirectory + kUptimeFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> upTime;
  }
  stream.close();
  // std::cout << stol(upTime) << std::endl;
  return stol(upTime);
}

// Read and return the number of jiffies for the system
long LinuxParser::Jiffies() {
  vector<string> values = LinuxParser::CpuUtilization();
  long temp;
  long total = 0;
  vector<CPUStates> all = {kUser_,   kNice_, kSystem_,  kIdle_,
                           kIOwait_, kIRQ_,  kSoftIRQ_, kSteal_};
  for (auto i : all) {  // All non-guest values
    temp = stol(values[i]);
    total += temp;
  };
  return total;
}

// Read and return the number of active jiffies for a PID
long LinuxParser::ActiveJiffies(int pid) {
  string line, value;
  vector<string> values;
  std::ifstream stream(kProcDirectory + to_string(pid) + kStatFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    while (linestream >> value) {
      values.push_back(value);
    }
  }
  stream.close();
  return stol(values[13] + values[14]);
}

// Read and return the number of active jiffies for the system
long LinuxParser::ActiveJiffies() {
  vector<string> jiffies = CpuUtilization();
  return stol(jiffies[CPUStates::kUser_]) + stol(jiffies[CPUStates::kNice_]) +
         stol(jiffies[CPUStates::kSystem_]) + stol(jiffies[CPUStates::kIRQ_]) +
         stol(jiffies[CPUStates::kSoftIRQ_]) +
         stol(jiffies[CPUStates::kSteal_]);
}

// Read and return the number of idle jiffies for the system
long LinuxParser::IdleJiffies() {
  vector<string> jiffies = CpuUtilization();
  return stol(jiffies[CPUStates::kIdle_]) + stol(jiffies[CPUStates::kIOwait_]);
}

// Read and return CPU utilization
vector<string> LinuxParser::CpuUtilization() {
  string line, name, value;
  vector<string> values;
  std::ifstream stream(kProcDirectory + kStatFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> name;
    while (linestream >> value) {
      values.push_back(value);
    };
  }
  // for (int i = 0; i < values.size(); i++) {
  // Print test
  // values[i].erase(remove(values[i].begin(), values[i].end(), ' '),
  //                 values[i].end());
  // std::cout << values[i] << "\n";
  // }
  stream.close();
  return values;
}

// Read and return the total number of processes
int LinuxParser::TotalProcesses() {
  string line, name, value;
  std::ifstream stream(kProcDirectory + kStatFilename);
  if (stream.is_open()) {
    while (std::getline(stream, line)) {
      std::istringstream linestream(line);
      while (linestream >> name >> value) {
        if (name == "processes") {
          return stoi(value);
        }
      }
    }
  }
  stream.close();
  return 0;
}

// Read and return the number of running processes
int LinuxParser::RunningProcesses() {
  string line, name, value;
  std::ifstream stream(kProcDirectory + kStatFilename);
  if (stream.is_open()) {
    while (std::getline(stream, line)) {
      std::istringstream linestream(line);
      while (linestream >> name >> value) {
        if (name == "procs_running") {
          return stoi(value);
        }
      }
    }
  }
  stream.close();
  return 0;
}

// Read and return the command associated with a process
string LinuxParser::Command(int pid) {
  string command;
  std::ifstream stream(kProcDirectory + to_string(pid) + kCmdlineFilename);
  if (stream.is_open()) {
    std::getline(stream, command);
  }
  stream.close();
  return command;
}

// Read and return the memory used by a process
string LinuxParser::Ram(int pid) {
  string line, name, value;
  std::ifstream stream(kProcDirectory + to_string(pid) + kStatusFilename);
  if (stream.is_open()) {
    while (std::getline(stream, line)) {
      std::istringstream linestream(line);
      while (linestream >> name) {
        if (name == "VmSize:") {
          linestream >> value;
          return to_string(stol(value) / 1024);
        }
      }
    }
  }
  stream.close();
  return "0";
}

// Read and return the user ID associated with a process
string LinuxParser::Uid(int pid) {
  string line, name, value;
  std::ifstream stream(kProcDirectory + to_string(pid) + kStatusFilename);
  if (stream.is_open()) {
    while (std::getline(stream, line)) {
      std::istringstream linestream(line);
      while (linestream >> name >> value) {
        if (name == "Uid:") {
          return value;
        }
      }
    }
  }
  stream.close();
  return "0";
}

// Read and return the user associated with a process
string LinuxParser::User(int pid) {
  string line, name, uid;
  string x;
  std::ifstream stream(kPasswordPath);
  if (stream.is_open()) {
    while (std::getline(stream, line)) {
      std::replace(line.begin(), line.end(), ':', ' ');
      std::istringstream linestream(line);
      while (linestream >> name >> x >> uid) {
        // std::cout << name << " " << x << " " << uid << std::endl;
        if (uid == LinuxParser::Uid(pid)) {
          // std::cout << name << std::endl;
          return name;
        }
      }
    }
  }
  stream.close();
  return "unknown";
}

// Read and return the uptime of a process
long LinuxParser::UpTime(int pid) {
  string line, value;
  vector<string> values;
  std::ifstream stream(kProcDirectory + to_string(pid) + kStatFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    while (linestream >> value) {
      values.push_back(value);
    };
  }
  stream.close();
  return LinuxParser::UpTime() - (stol(values[21]) / 100);
}