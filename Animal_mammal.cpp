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
    static int counter;
    std::string name;
    int age;

public:
    mammal(const std::string& Name, int Age) : name(Name), age(Age) {

        counter++;
        std::cout << name << " It's the name" << std::endl;
    }

    static int getCount() {
        return counter;
    }

    bool operator<(const mammal& obj) const {
        return age < obj.age;
    }

    bool operator>(const mammal& obj) const {
        return age > obj.age;
    }
};

int mammal::counter = 0;

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
    Lion lion1("Reks", 10);
    Lion lion2("Mufasa", 15);

    lion1.number_of_legs();
    lion1.sound();
    lion1.color();
    lion1.behavior();
    std::cout << (lion1 < lion2) << std:: endl;

    std::cout << mammal::getCount() << std::endl;
    return 0;
}


