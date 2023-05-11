#include <assert.h>
#include <string>

// TODO: Define class Person
// TODO: Define a public constructor with an initialization list
// TODO: Define a public member variable: name
class Person {
public:
  Person(std::string name);
  const std::string name;
};
Person::Person(std::string n) : name(n) { return; }

// Test
int main() {
  Person alice("Alice");
  Person bob("Bob");
  assert(alice.name != bob.name);
}