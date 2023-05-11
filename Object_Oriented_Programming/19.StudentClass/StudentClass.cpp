#include <cassert>
#include <iostream>
#include <stdexcept>
#include <string.h>

// TODO: Define "Student" class
class Student {
public:
  // constructor
  // accessors
  // mutators
  Student(std::string name, int grade, float gpa)
      : _studentName(name), _studentGrade(grade), _studentGpa(gpa) {
    if (name.compare("") == 0 || name.compare(" ") == 0) {
      throw std::runtime_error("The name must be existed string");
    }
    if (grade < 0) {
      throw std::runtime_error("The grade must be lager 0");
    }
    if (gpa < 0.0) {
      throw std::runtime_error("The gpa must be positive");
    }
  }
  std::string getStudentName();
  int getStudentGrade();
  float getStudentGpa();

  void setStudentName(std::string name);
  void setStudentGrade(int grade);
  void setStudentGpa(float gpa);

private:
  std::string _studentName;
  int _studentGrade;
  float _studentGpa;
};
void Student::setStudentName(std::string name) { _studentName = name; }
void Student::setStudentGrade(int grade) { _studentGrade = grade; }
void Student::setStudentGpa(float gpa) { _studentGpa = gpa; }

std::string Student::getStudentName() {
    return _studentName;
}
int Student::getStudentGrade() {
    return _studentGrade;
}
float Student::getStudentGpa() {
    return _studentGpa;
}

int main() {
  Student student("student", 5, 9.0);
  std::cout << student.getStudentName() << " " << student.getStudentGrade()
            << " " << student.getStudentGpa() << "\n";
  assert(student.getStudentName() == "student");
  assert(student.getStudentGrade() == 5);
  assert(student.getStudentGpa() == 9.0);
  try {
  Student student1("", 5, 9.0);
  }
  catch (std::exception& e) {
    std::cout << "Bug" << "\n";
  }
}