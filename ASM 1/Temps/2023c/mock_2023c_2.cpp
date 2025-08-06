#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 4) {
        cerr << "Insufficient arguments";
        return -1;
    }

    string lhs = argv[1], op = argv[2], rhs = argv[3];
    int lhs_value, rhs_value;
    if (lhs.find("0x") != string::npos || lhs.find("0X") != string::npos) {
        lhs_value = stoi(lhs, nullptr, 16);
    } else {
        lhs_value = stoi(lhs);
    }
    if (rhs.find("0x") != string::npos || rhs.find("0X") != string::npos) {
        rhs_value = stoi(rhs, nullptr, 16);
    } else {
        rhs_value = stoi(rhs);
    }

    if (op == "+") {
        cout << "Result is " << (lhs_value + rhs_value) << endl;
    } else {
        cout << "Result is " << (lhs_value - rhs_value) << endl;
    }

    return 0;
}