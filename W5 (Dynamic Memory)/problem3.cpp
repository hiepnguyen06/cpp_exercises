#include <iostream>

using namespace std;

int main() {
    double a, b;
    bool validInput = false;
    cout << "Enter a and b: "; cin >> a >> b;

    while(!validInput) {
        try {
            if (b == 0) {
                throw 101;
            } else {
                validInput = true;
            }
        } catch (int errorCode) {
            cout << "B cannot be 0" << endl;
            cout << "Please re-enter b value: "; cin >> b;
        }
    }

    cout << "A divided by B: " << a / b << endl;

}