#include <iostream>

class Animal {
public:
    virtual void number_of_legs() = 0;
    virtual void sound() = 0;
    virtual void color() = 0;
    virtual void behavior() = 0;
    virtual ~Animal() {}
};

class mammal : public Animal {
protected:
    std::string name;
    int age;

public:
    mammal(const std::string& Name, int Age) : name(Name), age(Age) {
        std::cout << name << " It's the name" << std::endl;
    }
};

class Lion : public mammal {
public:
    Lion(const std::string& Name, int Age) : mammal(Name, Age) {}

    void number_of_legs() override {
        std::cout << name << " has 4 legs." << std::endl;
    }

    void sound() override {
        std::cout << "The sound of " << name << " is RAR." << std::endl;
    }

    void color() override {
        std::cout << "The color of " << name << " is undefined." << std::endl;
    }

    void behavior() override {
        std::cout << "The behavior of " << name << " is aggressive." << std::endl;
    }
};

int main() {
    Lion lion("Reks", 10);
    lion.number_of_legs();
    lion.sound();
    lion.color();
    lion.behavior();

    return 0;
}



