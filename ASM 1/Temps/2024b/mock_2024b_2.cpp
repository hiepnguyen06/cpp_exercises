#include <iostream>

using namespace std;

bool checkHex(string hex) {
    string prefix = hex.substr(0, 2);
    string suffix = hex.substr(2);

    if (prefix != "0x" && prefix != "0X") {
        return false;
    }

    for (auto c : suffix) {
        if (isdigit(c)) continue;
        c = tolower(c);
        if (c < 'a' || c > 'f') return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        cerr << "Insufficient arguments";
        return -1;
    }

    string lhs = argv[1], op = argv[2], rhs = argv[3];

    if (!checkHex(lhs) || !checkHex(rhs)) {
        cerr << "Argument(s) provided is(are) not hexadecimal.";
        return -1;
    }

    int lhs_value = stoi(lhs, nullptr, 16);
    int rhs_value = stoi(rhs, nullptr, 16);

    if (op.find("+") != string::npos) {
        cout << "Result is " << lhs_value + rhs_value << endl;
    } else {
        cout << "Result is " << lhs_value - rhs_value << endl;
    }

    return 0;
}