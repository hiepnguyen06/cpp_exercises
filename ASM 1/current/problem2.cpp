#include <iomanip>
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <fstream>

class Student {
   private:
    std::string name;
    int scores[3];

   public:
    Student() = default;
    Student(std::string name, int scores[3]) : name(name) {
        for (int i = 0; i < 3; i++) {
            this->scores[i] = scores[i];
        }
    };

    double getAvgScore() {
        int sum = 0;
        for (int score : scores) {
            sum += score;
        }
        return (double)sum / 3;
    }

    bool operator>(Student s2) {
        return getAvgScore() > s2.getAvgScore();
    }

    friend Student operator+(int n, Student s2) {
        int newScores[3];
        int i = 0;
        for (auto score : s2.scores) {
            newScores[i] = score + n;
            i++;
        }
        return Student(s2.name, newScores);
    };

    void getInfo() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Scores: " << std::endl;

        for (auto& s : scores) {
            std::cout << s << std::endl;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, Student& student) {  // display the student's info
        os << "Name: " << student.name << "\nScores: ";
        for (auto score : student.scores) {
            os << std::left << std::setw(4) << score;
        }
        os << std::endl;
        return os;
    };

    friend std::istream& operator >>(std::istream& is, Student& student) {
        std::cout << "Enter name: " << std::endl;
        std::getline(std::cin >> std::ws, student.name);
        std::cout << "Enter scores: " << std::endl;
        for (int i = 0; i < 3; i++) {
            std::cout << "Score " << i + 1 << ": ";
            std::cin >> student.scores[i];
        }
        return is;
    }

    void setName(std::string name) { this->name = name; }
    void setScores(int arr[3]) {
        int i = 0;
        for (int i = 0; i < 3; i++) {
            this->scores[i] = arr[i];
        }
    }
};

int main() {
    Student studentList[10];

    std::ifstream fileReader("data.txt");
    std::string line;
    if (!fileReader) {
        std::cerr << "unable to open file";
        return -1;
    }
    int i = 0;
    while (getline(fileReader, line)) {
        std::stringstream ss(line);
        std::string name;
        std::getline(ss, name, ',');
        int scores[3];
        for (auto& score: scores) {
            ss >> score;
        }
        studentList[i] = Student(name, scores);        
        i++;
    }

    double highest = 0;
    Student* highestPtr;
    for (auto& s: studentList) {
        if (s.getAvgScore() > highest) {
            highest = s.getAvgScore();
            highestPtr = &s;
        }
        
    }

    if (highestPtr != nullptr) std::cout << *highestPtr << "Average Score: " << std::fixed << std::setprecision(2) << highestPtr->getAvgScore() << std::endl;

    return 0;
}