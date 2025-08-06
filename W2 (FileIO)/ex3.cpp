#include <iomanip>
#include <iostream>
#include <string>
#include <cmath>

void problem1() {
    char str[100];

    std::cout << "Enter a string: ";
    std::cin >> str;

    for (int i = 0; str[i] != '\0'; i++) {
        std::cout << str[i] << " ";
    }
}

void problem2() {
    double n = 1.234;

    std::cout << std::setfill('0') << std::setw(9) << n << "\n";
    std::cout << std::fixed << std::setprecision(2) << n << "\n";
}

int mapHex(char c) {
    if (isdigit(c)) {
        return c - '0';
    } else {
        c = tolower(c);
        int n = c - ('a' - 10);
        return n;
    }
}

void problem3(std::string input) {
    
    std::string hex_str = input.substr(2, input.length() - 2);
    int hex = 0;
    for (int i = 0, n = hex_str.length() - 1; hex_str[i] != '\0' ; i++, n--) {
        hex += mapHex(hex_str[i]) * std::pow(16,n);
    }
    std::cout << input << ": " << hex;
}
int main() {
    // problem1();
    // problem2();
    problem3("0x1b7e");

    

    return 0;
}