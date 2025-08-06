#include <bits/stdc++.h>
using namespace std;

int reverseNum(int num) {
    int reverse;
    while (num != 0) {
        reverse *= 10;
        reverse += num % 10;
        num /= 10;
    }
    return reverse;
}

string reverseString(string str) {
    reverse(str.begin(), str.end());

    return str;
}


int main() {
    // Exercise 1

    int a, b;
    cout << "Enter values for a and b (seperated by space): ";
    cin >> a >> b;

    cout << "Equation: " << a << "x + " << b << "= 0 has the solution of " << - (double) b / a << "\n";

    // Exercise 2

    int arr[5];
    int max, sum = 0;
    
    for (int i = 0; i < 5; i++) {
        cout << "Enter value for element " << i + 1 << ": ";
        cin >> arr[i];
        
        if (i == 0) {
            max = arr[i];
        } else {
            if (max < arr[i]) {
                max = arr[i];
            }
        }

        sum += arr[i];
    }

    cout << "Maximum value: " << max << "\n";
    cout << "Average: " << sum / 5 << "\n";

    // Exercise 3


    return 0;
}