#include <fstream>
#include <iomanip>
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>

using namespace std;

class Student {
   private:
    string name;
    int scores[3];

   public:
    Student() = default;
    Student(string name, int scores[3]) : name(name) {
        int i = 0;
        for (auto& score : this->scores) {
            score = scores[i++];
        }
    }

    bool operator>(Student b) {
        int a_avg = 0, b_avg = 0;
        for (int i = 0; i < 3; i++) {
            a_avg += scores[i];
            b_avg += b.scores[i];
        }
        a_avg /= 3;
        b_avg /= 3;
        return a_avg > b_avg;
    }
    friend Student operator+(int n, Student b) {
        Student temp(b.name, b.scores);
        for (auto& score : temp.scores) {
            score += n;
        }
        return temp;
    }
    friend istream& operator>>(istream& is, Student& b) {
        cout << "Enter student's name: ";
        is >> b.name;
        cout << "Enter student's grades (seperated by space): ";
        is >> b.scores[0] >> b.scores[1] >> b.scores[2];
        return is;
    }
    friend ostream& operator<<(ostream& os, Student& b) {
        os << "Name: " << b.name << " Score: " << b.scores[0] << " " << b.scores[1] << " " << b.scores[2] << endl;
    }
};

int main() {
    // int scores1[] = {90, 75, 88};
    // int scores2[] = {95, 75, 89};
    // Student a("hiep", scores1);
    // Student b = 5 + a;
    // cin >> b;
    // cout << b;

    Student studentArr[10];
    ifstream fileReader("data.txt");
    string line;

    if (!fileReader) {
        cerr << "Unable to open file";
        return -1;
    }

    int i = 0;
    while (getline(fileReader, line) && i < 10) {
        stringstream ss(line);
        string name;
        getline(ss, name, ',');
        
        int scores[3];
        for (auto& score: scores) {
            ss >> score;
        }

        studentArr[i] = Student(name, scores);
        cout << studentArr[i];
        i++;
    }

    Student* highest = &studentArr[0];
    for (int i = 1; i < 10; i++) {
        if (studentArr[i] > *highest) highest = &studentArr[i];
    }
    cout << "Student with the highest score: " << *highest; 
    cout << "Testing" << endl;

    fileReader.close();
    return 0;
}

