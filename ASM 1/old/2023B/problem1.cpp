#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int sumDigit(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

bool checkPal(int num) {
    int sum = sumDigit(num);
    int reversedSum = 0;
    while (sum > 0) {
        reversedSum += sum % 10;
        reversedSum *= 10;
        sum /= 10;
    }
    reversedSum /= 10;
    return sumDigit(num) == reversedSum;
}

string recPal(int num) {
    int n = 1;
    while (!checkPal(num + n) && !checkPal(num - n)) {
        n++;
    }

    if (checkPal(num + n)) return "Add " + to_string(n) + " to make it a palindrome\n";
    return "Minus " + to_string(n) + " to make it a palindrome\n";
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Invalid number of argument";
        return -1;
    }
    string fileName = argv[1];
    string line;
    ifstream fileReader(fileName);
    ofstream fileWriter("Result.txt");

    if (!fileReader) {
        cerr << "Unable to open file";
        return -1;
    }

    while (getline(fileReader, line)) {
        stringstream ss(line);
        int num;
        ss >> num;
        stringstream ss2;

        if (checkPal(num)) {
            ss2 << num << ": Result " << sumDigit(num) << " is a palindrome.\n";
        } else {
            ss2 << num << ": Result " << sumDigit(num) << " is NOT a palindrome." << endl;
            ss2 << recPal(num) << endl;
        }
        cout << ss2.str();
        fileWriter << ss2.str();
    }

    fileReader.close();
    fileWriter.close();

    return 0;
}