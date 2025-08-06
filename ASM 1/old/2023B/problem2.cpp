#include <fstream>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <sstream>

using namespace std;
class Time {
   private:
    int hour;
    int minute;

   public:
    Time(int hour = 0, int minute = 0) {
        this->hour = (hour < 25 && hour > 0) ? hour : 0;
        this->minute = (minute < 60 && minute > 0) ? minute : 0;
    }
    void getInfo() {
        cout << hour << ":" << minute << endl;
    }
    Time operator+(Time b) {
        int totalMinutes = (hour + b.hour) * 60 + (minute + b.minute);
        return Time((totalMinutes / 60) % 24, totalMinutes % 60);
    }
    friend ostream& operator<<(ostream& os, Time b) {
        os << setw(2) << setfill('0') << b.hour;
        os << ":" << setw(2) << setfill('0') << b.minute;
    }
    int getHour() { return hour; }
    int getMinute() { return minute; }
};

int main() {
    Time timearray[4];
    ifstream fileReader("data2.dat");
    string line;
    
    Time a(5,23); 
    Time b(23,42);
    Time c = a + b;
    cout << a << " + " << b << " = " << c << endl;
    

    int i = 0;
    while (getline(fileReader, line)) {
        stringstream ss(line);
        int hour, minute;
        ss >> hour >> minute;
        timearray[i] = Time(hour, minute);
        cout << "Time " << i + 1 << ": " << timearray[i] << endl;
        i++;
    }

    Time* lowest = &timearray[0];
    for (int i = 1; i < 4; i++) {
        if (timearray[i].getHour() > lowest->getHour()) continue;
        if (timearray[i].getHour() < lowest->getHour()) {
            lowest = &timearray[i];
            continue;
        }
        if (timearray[i].getMinute() < lowest->getMinute()) lowest = &timearray[i];
    }
    cout << "Lowest time : " << *lowest;


    return 0;
}