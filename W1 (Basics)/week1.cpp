#include <iostream>
#include <cstring>

using namespace std;

int main() {
    // Exercise 1
    double a, b;

    cout << "Enter values for a and b (seperated by space): ";
    cin >> a >> b;
    cout << "Equation " << a << "x + " << b << " has a solution of " << - b / a;

    // Exercise 2
    int arr[5];
    int highest = -99999;
    int sum = 0;

    cout << "\n";
    cout << "Enter 5 values for the array\n";
    for (int i = 0; i < 5; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];

        if (arr[i] > highest) {
            highest = arr[i];
        }
        sum += arr[i];
    }

    // cout << "The highest value: " << highest << "\n";
    // cout << "The average: " << sum / 5;

    printf("The highest value: %d\nThe average: %d\n", highest, sum / 5);

    // Exercise 3
    int sumDigits = 0;
    char str[100];
    cout << "Input a string: ";
    cin >> str;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isupper(str[i])) {
            str[i] = tolower(str[i]);
        } else if (islower(str[i])) {
            str[i] = toupper(str[i]);
        } else if (isdigit(str[i])) {
            sumDigits += str[i] - '0';
        }
    }

    cout << "New string: " << str << "\n";
    cout << "Sum of digits: " << sumDigits << "\n";

    




    



    return 0;
}