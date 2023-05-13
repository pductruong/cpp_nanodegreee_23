#include <iostream>
#include <string>

class Animal {
    public:
    void MakeSound() {
        std::cout << "........" << std::endl;
    }
    std::string color;
    std::string name;
    int age;
};

class Snake: public Animal {
    public:
    void MakeSound() {
        std::cout << "Shhhh !!" << std::endl;
    }
    private:
    int length;

};

class Cat: public Animal {
    public:
    void MakeSound() {
        std::cout << "Meow !!" << std::endl;
    }
    private:
    int height;
};

int main() {
    Animal animal;
    animal.MakeSound();
    Snake snake;
    snake.age = 2;
    snake.MakeSound();
    std::cout << snake.age << std::endl;
    Cat cat;
    cat.MakeSound();
    return 0;
}