#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

int doubleVal(int num) {
    return num * 2;
}

double doubleVal(double num) {
    return num * 2;
}

int doubleVal(string hex) {
    return stoi(hex, nullptr, 16) * 2;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Invalid argument(s)";
        return -1;
    }
    string input = argv[1];

    if (input.find("0X") != string::npos || input.find("0x") != string::npos) {
        stringstream ss;
        ss << hex << showbase << doubleVal(input);
        cout << ss.str() << endl;
        return -1;
    } else if (input.find(".") != string::npos) {
        cout << fixed << setprecision(2) << doubleVal(stod(input)) << endl;
    } else {
        cout << doubleVal(stoi(input)) << endl;
    }

    return 0;
}