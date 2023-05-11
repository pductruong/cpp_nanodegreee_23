#include <cassert>
#include <cmath>
#include <stdexcept>

// TODO: Define class Sphere
class Sphere {
 public:
  // Constructor
  Sphere(int r) : _radius(r) {
    if (r < 0) {
        throw std::runtime_error("Radius must be larger 0");
    }
  }

  // Accessors
  int Radius() {
    return _radius;
  }
  float Volume() {
    _volume = (4.0 / 3.0) * M_PI * pow(_radius, 3); 
    return _volume;
  }


 private:
  // Private members
  int _radius;
  float _volume;
};

// Test
int main(void) {
  Sphere sphere(5);
  assert(sphere.Radius() == 5);
  assert(abs(sphere.Volume() - 523.6) < 1);
}