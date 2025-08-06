#include <iostream>

using namespace std;

int main() {
    string str;
    cout << "Enter a string: "; getline(cin >> ws, str);

    int highestDigit = 0;
    bool isDigit = false;
    for (char c: str) {
        if (!isdigit(c)) continue;
        int n = c - '0';
        highestDigit = (n > highestDigit) ? n : highestDigit;
        isDigit = true;
    }

    if (!isDigit) {
        cout << "There's no digit in the string" << endl;
    } else {
        cout << "The highest digit value is " << highestDigit << endl;
    }

    return 0;
}