#include <iostream>

class Student {
    int score;

   public:
    std::string name;

    Student(std::string name, int score) : name(name), score(score) {};

    int getScore() { return score; }

    void getInfo() {
        std::cout << name << " (Score: " << score << ")\n";
    }
};

int main() {
    // B
    Student s1("Hiep Nguyen", 95);
    Student s2("Ben Dover", 88);

    s1.getInfo();
    s2.getInfo();

    // C
    Student s3("Moe Lester", 69);
    Student studentArr[] = {s1, s2, s3};

    int highScore = 0;
    Student *mvp;

    for (auto &s : studentArr) {  // Range based loop by reference
        if (s.getScore() > highScore) {
            highScore = s.getScore();
            mvp = &s;
        }
    }

    std::cout << "Top student: ";
    mvp->getInfo();

    return 0;
}