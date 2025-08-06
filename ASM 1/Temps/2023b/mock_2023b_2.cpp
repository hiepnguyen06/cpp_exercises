#include <iostream>
#include <iomanip>
#include <ostream>
#include <fstream>
#include <sstream>

using namespace std;

class Time {
    private: 
        int hour;
        int minute;
    public:
        Time(int hour = 0, int minute = 0) {
            this->hour = (hour < 0 || hour > 23) ? 0: hour;
            this->minute = (minute < 0 || minute > 59) ? 0: minute;
        }
        Time operator+(Time b) {
            int totalMin = (hour + b.hour) * 60 + (minute + b.minute);
            int hour = (totalMin / 60) % 24;
            int minute = totalMin % 60;
            return Time(hour, minute);
        }
        friend ostream& operator<<(ostream& os, Time& b) {
            os << setw(2) << setfill('0') << b.hour;
            os << ":";
            os << setw(2) << setfill('0') << b.minute;
            return os;
        }
        int getHour() { return hour; }
        int getMinute() { return minute; }
};

int main() {
    Time a(5,23); 
    Time b(23, 42);
    Time c = a + b;
    cout << a << " + " << b << " = " << c << endl;

    ifstream fileReader("data2.dat");
    Time timeArray[4];

    if (!fileReader) {
        cerr << "Unable to open file";
        return -1;
    }

    string line;
    int i = 0;
    while(getline(fileReader, line)) {
        stringstream ss(line);
        int hour, minute;
        ss >> hour >> minute;
        timeArray[i] = Time(hour, minute);
        i++;
    }

    Time* lowest = &timeArray[0];
    for (int i = 0; i < 4; i++) {
        cout << "Time " << i + 1 << " = " << *(timeArray + i) << endl;
        if ((timeArray + i)->getHour() < lowest->getHour()) lowest = &timeArray[i];
        if ((timeArray + i)->getHour() == lowest->getHour()) {
            if ((timeArray + i)->getMinute() < lowest->getMinute()) lowest = &timeArray[i];
        }
    }

    cout << "Lowest time = " << *lowest;


}