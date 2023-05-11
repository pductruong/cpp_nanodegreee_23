#include <cassert>
#include <iostream>
#include <stdexcept>

// TODO: Define class Pyramid
class Pyramid {
public:
  Pyramid(int length, int width, int height)
      : _length(length), _width(width), _height(height) {
    if (_length < 0 || _width < 0 || _height < 0) {
      throw std::runtime_error("Value need larger 0");
    }
  }
  void setLength(int l);
  void setWidth(int w);
  void setHeight(int h);

  int Length();
  int Width();
  int Height();
  int Volume() {
    int volume = _length * _width * _height / 3;
    return volume;
  }

private:
  int _length;
  int _width;
  int _height;
};
void Pyramid::setLength(int l) {
  if (l < 0) {
    throw std::runtime_error("Value need larger 0");
  }
  _length = l;
}
int Pyramid::Length() { return _length; }
void Pyramid::setWidth(int w) {
  if (w < 0) {
    throw std::runtime_error("Value need larger 0");
  }
  _width = w;
}
int Pyramid::Width() { return _width; }
void Pyramid::setHeight(int h) {
  if (h < 0) {
    throw std::runtime_error("Value need larger 0");
  }
  _height = h;
}
int Pyramid::Height() { return _height; }

// Test
int main() {
  Pyramid pyramid(4, 5, 6);

  assert(pyramid.Length() == 4);
  assert(pyramid.Width() == 5);
  assert(pyramid.Height() == 6);
  assert(pyramid.Volume() == 40);

  bool caught{false};
  try {
    Pyramid invalid(-1, 2, 3);
    std::cout << invalid.Length() << "\n";
  } catch (...) {
    caught = true;
  }
  assert(caught);
}