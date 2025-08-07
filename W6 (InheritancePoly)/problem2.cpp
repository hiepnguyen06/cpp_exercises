#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Student {
   public:
    string name;
    int studentID;
    Student(string name = "", int studentID = 0) : name(name), studentID(studentID) {}
};

class SchoolSystem {
   private:
   public:
    vector<Student> students;
    void addStudent() {
        cout << "Adding Student: ";
        cout << "Enter new student's name: ";
        string name;
        getline(cin >> ws, name);
        cout << "Enter new student's ID: ";
        int id;
        cin >> id;

        students.push_back(Student(name, id));
        cout << "Student has been added" << endl;
    }

    void removeStudent() {
        cout << "Deleting Student: ";
        cout << "Enter student's name: ";
        string name;
        getline(cin >> ws, name);
        cout << "Enter student's ID: ";
        int id;
        cin >> id;

        for (int i = 0; i < students.size(); i++) {
            if (students[i].name == name && students[i].studentID == id) {
                students.erase(students.begin() + i);
                cout << "Student has been deleted" << endl;
                return;
            }
        }
        cout << "No student was found" << endl;
    }
};

int main() {
    string fileName = "students.dat";
    ifstream fileReader(fileName);

    SchoolSystem system;

    while (true) {
        if (fileReader) {  // Read saved data
            string line, name;
            int id;

            while (getline(fileReader, line)) {
                stringstream ss(line);
                getline(ss, name, ',');
                ss >> id;

                system.students.push_back(Student(name, id));
            }
        }

        cout << "School Management System\n1. View all Students\n2.Add Student\n3. Remove Student\n4. Exit\n5. Enter your choice: ";
        int user;
        cin >> user;

        switch (user) {
            case 1:
                for (int i = 0; i < system.students.size(); i++) {
                    cout << "#" << i + 1 << " Name: " << system.students[i].name << " ID: " << system.students[i].studentID << endl;
                }
                break;
            case 2:
                system.addStudent();
                break;
            case 3:
                system.removeStudent();
                break;
            case 4:
                cout << "Exitting...";
                return -1;
            default:
                cout << "Invalid input. Try again!" << endl;
                return -1;
        }

        ofstream fileWriter;
        if (fileReader) {
            fileWriter.open(fileName, ios::app);
        } else {
            fileWriter.open(fileName);
        }
        for (auto stu : system.students) {
            fileWriter << stu.name << " , " << stu.studentID << endl;
        }
        fileReader.close();
        fileWriter.close();

        cout << endl;
    }

    return 0;
}