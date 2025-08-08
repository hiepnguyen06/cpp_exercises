#include <iostream>

using namespace std;

class Student {
   public:
    string name;
    int studentID;
    Student(string name = "", int studentID = 0) : name(name), studentID(studentID) {
        cout << "Student " << name << " is created" << endl;
    }
    ~Student() {
        cout << "Student " << name << " is destructed " << endl;
    }
    virtual string toString() {
        return "Student: " + name + "\n";
    }
};

class Staff {
   public:
    string name;
    int staffID;
    Staff(string name = "", int staffID = 0) : name(name), staffID(staffID) {
        cout << "Staff " << name << " is created" << endl;
    }
    ~Staff() {
        cout << "Staff " << name << " is destructed " << endl;
    }
    virtual string toString() {
        return "Staff: " + name + "\n";
    }
};

class Tutor : public Student, public Staff {
   public:
    Tutor(string name) : Student(name), Staff(name) {
        cout << "Tutor " << Student::name << " is created" << endl;
    }
    ~Tutor() {
        cout << "Tutor " << Student::name << " is destructed" << endl;
    }
    void Consultation() {
        cout << "Tutor " << Student::name << " is doing consultation" << endl;
    }
    void setName(string name) {
        Student::name = name;
    }
    string toString() override {
        return "Tutor: " + Student::name + "\n";
    }
};

void showInfoStudent(Student& stu) {
    cout << stu.toString() << endl;
}

void showInfoStaff(Staff& staff) {
    cout << staff.toString() << endl;
}

int main() {
    Tutor tutor("Hiep");

    // showInfoStudent(tutor);
    // showInfoStaff(tutor);

    return 0;
}