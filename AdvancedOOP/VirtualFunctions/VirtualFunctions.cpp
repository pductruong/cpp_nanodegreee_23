// Example solution for Shape inheritance
#include <assert.h>
#include <cmath>

double pi{M_PI};

class Shape {
public:
  virtual double Area() const = 0;
  virtual double Perimeter() const = 0;
};

class Rectangle : Shape {
public:
  Rectangle(int w, int h) : width(w), height(h){};

  double Area() const override { return width * height; }

  double Perimeter() const override { return width * 2 + height * 2; }

private:
  int width;
  int height;
};

class Circle : Shape {
public:
  Circle(double r) : radius(r){};

  double Area() const override { return pi * pow(radius, 2); }

  double Perimeter() const override { return 2 * pi * radius; }

private:
  double radius;
};

int main() {
  double epsilon = 0.1; // useful for floating point equality

  //   Test circle
  Circle circle(12.31);
  assert(abs(circle.Perimeter() - 77.35) < epsilon);
  assert(abs(circle.Area() - 476.06) < epsilon);

  // Test rectangle
  Rectangle rectangle(10, 6);
  assert(rectangle.Perimeter() == 32);
  assert(rectangle.Area() == 60);
  return 0;
}