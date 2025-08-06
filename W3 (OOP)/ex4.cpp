#include <iostream>

class Cat {
   public:
    std::string name;
    int age;

    Cat(std::string name, int age) : name(name), age(age) {};
};

class Person {
   public:
    Cat cat;
    std::string name;

    Person(Cat cat, std::string name) : cat(cat), name(name) {};
};

int main() {
    Cat c1("ABC", 14);
    Cat c2("CBA", 20);
    Cat c3("DEG", 13);

    Person p1(c1, "An");
    Person p2(c2, "Phu");
    Person p3(c3, "Dat");

    Person persons[] = {p1, p2, p3};

    int maxAge = 0;
    Person *pCat;

    for (auto &p : persons) {
        if (maxAge < p.cat.age) {
            maxAge = p.cat.age;
            pCat = &p;
        }
    }

    std::cout << "Person with the oldest cat: " << pCat->name << "\nCat info: " << pCat->cat.name << " (Age: " << pCat->cat.age << ")\n";

    return 0;
}