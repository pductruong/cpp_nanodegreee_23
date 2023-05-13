// TODO: Write hello() function

// TODO: Overload hello() three times

// TODO: Call hello() from main()

#include <iostream>

class Human {};
class Cat {};
class Dog {};

void hello() { std::cout << "Hello, World!\n"; }

void hello(Human human) { std::cout << "Human\n"; }

void hello(Cat cat) { std::cout << "Cat\n"; }

void hello(Dog dog) { std::cout << "Dog\n"; }

int main() {
  hello(Human());
  hello(Cat());
  hello(Dog());
  return 0;
}