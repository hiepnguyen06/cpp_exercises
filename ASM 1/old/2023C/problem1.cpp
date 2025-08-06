#include <iostream>
using namespace std;
int main() {
    int second, hour, minute;
    int totalSecond;
    cout << "Input total amount of seconds: "; cin >> totalSecond;

    hour = totalSecond / 3600;
    minute = (totalSecond % 3600) / 60;
    second = totalSecond % 60;


    cout << "It is " << hour << " hour(s), " << minute << " minute(s), and " << second << " second(s)" << endl; 

    return 0;
}