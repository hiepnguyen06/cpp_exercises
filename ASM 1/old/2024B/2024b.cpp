// Problem 1
#if 0
#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string str; 
    cout << "Enter a string: "; getline(cin >> ws, str);
    stringstream ss(str);
    int num, highest = 0;
    string word; 
    bool hasDigit = false;

    while (ss >> word) {
        for (int i = 0; i < word.length() - 1; i++) {
            if (isdigit(word[i])) {
                hasDigit = true;
                highest = (word[i] - '0') > highest ? word[i] - '0' : highest;
            }
        }
    }

    if (!hasDigit) {
        cerr << "There's no digit in the string" << endl;
        return -1;
    }
    cout << "The highest digit value is " << highest;
    return 0;
}
#endif

// Problem 2
#if 0
#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;

bool checkHex(string hex) {
    string prefix = hex.substr(0, 2);
    string postfix = hex.substr(2, hex.length() - 2);

    if (prefix != "0x" && prefix != "0X") {
        cerr << "Argument provided is(are) not hexadecimal" << endl;
        return false;
    }

    for (int i = 0; i < postfix.length(); i++) {
        if (isdigit(postfix[i])) continue; // if digit -> continue

        if (toupper(postfix[i]) < 65 || toupper(postfix[i]) > 70) {
            cerr << "Argument provided is(are) not hexadecimal" << endl;
            return false;
        }
    }

    return true;
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        cerr << "Incomplete arguments";
        return -1;
    } 

    bool hexArgvs = checkHex(argv[1]) && checkHex(argv[3]);
    bool hasOperator = string(argv[2]) == "+" || string(argv[2]) == "-"; 

    if (hexArgvs && hasOperator) { // checking hex and operators
        int result;
        int hexA = stoi(argv[1], nullptr, 16);
        int hexB = stoi(argv[3], nullptr, 16);

        string op = argv[2];

        if (op == "+") {
            result = hexA + hexB;
        } else {
            result = hexA - hexB;
        }
        cout << "Operation: " << hexA << argv[2] << hexB << endl;
        cout << "Result is " << result << endl;

    } else {
        cerr << "Something wong" << endl;
        return -1;
    }

    return 0;
}

#endif

// Problem 3
#if 1
#include <iostream>
#include <ostream>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

class Task {
    private:
        int hour;
        int minute;

    public:
        Task(int hour = 0, int minute = 0) : hour(hour) {
            this->minute = (minute >= 0 && minute <= 59) ? minute: 0;
        }

        bool operator >(Task b) {
            int totalMinutesA = (hour * 60) + minute;
            int totalMinutesB = (b.hour * 60) + b.minute;
            return totalMinutesA > totalMinutesB;
        }

        friend ostream& operator <<(ostream& os, Task b) {
            os << setfill('0') << setw(2) << b.hour;
            os << ":";
            os << setfill('0') << setw(2) << b.minute;
            return os;
        }

        int getHour() { return hour; }
        int getMinute() { return minute; }

};

int main() {
    Task taskArr[4];
    ifstream fileReader("data2024B.txt");
    string line;

    if (!fileReader) {
        cerr << "Unable to open file"; return -1;
    }

    int i = 0;
    while(getline(fileReader, line)) {
        stringstream ss(line);
        int hour, minute;
        ss >> hour >> minute;
        taskArr[i] = Task(hour, minute);
        i++;
    }

    int hour, minute;
    cout << "Enter hours and minutes taken for your task: "; cin >> hour >> minute;
    Task userTask(hour, minute);
    cout << "Your task: " << userTask << endl;

    int j = 0;
    int numOfBiggerTasks = 0;
    for (auto task: taskArr) {
        cout << "Task " << j + 1 << " = " << task << endl;
        if (task > userTask) numOfBiggerTasks++;
        j++;
    }

    cout << "Number of tasks time greater than your task time: " << numOfBiggerTasks << endl;



    fileReader.close();


    return 0;
}

#endif