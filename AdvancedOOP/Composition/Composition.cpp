// #include <iostream>
// #include <cmath>
// #include <assert.h>

// class LineSegment {
//     public:
//     LineSegment(int l): length(l) {};
//     int getLength() {
//         return length;
//     }
//     protected:
//     int length;
// };

// class Circle {
//     public:
//     Circle (LineSegment r) : radius(r) {};
//     float Area() {
//         int r = radius.getLength();
//         float area = M_PI * pow(r, 2);
//         return area;
//     }
//     private:
//     LineSegment radius;
//     float area;
// };
// // Test in main()
// int main() 
// {
//     LineSegment radius {3};
//     Circle circle(radius);
//     assert(int(circle.Area()) == 28);
// }



#include <iostream>
#include <cmath>
#include <assert.h>
#define PI 3.14159;


struct LineSegment {
public:
    double length;
};

class Circle {
public:
    Circle(LineSegment& radius);
    double Area();

private:
    LineSegment& radius_;
};

Circle::Circle(LineSegment& radius) : radius_(radius) {}

double Circle::Area() 
{
    return pow(Circle::radius_.length, 2) * PI;
}

int main() 
{
    LineSegment radius {3};
    Circle circle(radius);
    assert(int(circle.Area()) == 28);
}