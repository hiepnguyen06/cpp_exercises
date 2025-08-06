#include <iostream>
#include <sstream>
using namespace std;

int getValue(string str) {
    if (tolower(str[1]) != 'x') return stoi(str);
    return stoi(str, nullptr, 16);
}

int main(int argc, char* argv[]) {
    if (argc >= 4) {
        int a = getValue(argv[1]);
        int b = getValue(argv[3]);
        int result;
        if (string(argv[2]) == "+") result = a + b;
        if (string(argv[2]) == "-") result = a - b;
        cout << "Result: " << result << endl;
    }

    return 0;
}