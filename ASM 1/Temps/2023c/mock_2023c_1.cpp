#include <iostream>

using namespace std;
int main() {
    cout << "Input total amount of seconds: ";
    int seconds; cin >> seconds;

    int hour = seconds / 3600;
    int minute = (seconds / 60) % 60;
    seconds = seconds % 60;

    cout << "It is " << hour << " hour(s), " << minute << " minute(s)"
    << " and " << seconds << " second(s)." << endl;

    return 0;
}