#include <iostream>
#include <ostream>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

class Task {
    private:
        int t_Hour;
        int t_Minute;
    public:
        Task(int t_Hour = 0, int t_Minute = 0) : t_Hour(t_Hour) {
            this->t_Minute = (t_Minute < 0 || t_Minute > 59) ? 0 : t_Minute;
        }
        bool operator>(Task b) {
            int totalA_mins = (t_Hour * 60) + t_Minute;
            int totalB_mins = (b.t_Hour * 60) + b.t_Minute;
            return totalA_mins > totalB_mins;
        }
        friend ostream& operator<<(ostream& os, Task& b) {
            os << setw(2) << setfill('0') << b.t_Hour;
            os << ":";
            os << setw(2) << setfill('0') << b.t_Minute;
            return os;
        }
};

int main() {
    // Task a(5, 9);
    // Task b(33, 42);
    // cout << a << " > " << b << " ? " << boolalpha << (a > b) << endl;
    Task taskArr[4];
    
    ifstream fileReader("data2024B.txt");

    if (!fileReader) {
        cerr << "Unable to open file";
        return -1;
    }

    int user_hour, user_minute;
    cout << "Enter hours and minutes taken for your task: "; cin >> user_hour >> user_minute;
    Task userTask(user_hour, user_minute);
    cout << "Your task = " << userTask << endl;

    string line;
    int i = 0;
    int longerTasks = 0;
    while(getline(fileReader, line)) {
        stringstream ss(line);
        int hour, minute;
        ss >> hour >> minute;
        taskArr[i] = Task(hour, minute);
        cout << "Task " << i + 1 << " = " << taskArr[i] << endl;
        if (taskArr[i] > userTask) longerTasks++;
        i++;
    }

    cout << "Number of tasks time greater than your task time: " << longerTasks << endl;

    return 0;
}