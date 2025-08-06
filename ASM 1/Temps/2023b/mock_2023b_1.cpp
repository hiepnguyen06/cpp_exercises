#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int sumDigit(int num) {
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

bool checkPal(int num) {
    int digitSum = sumDigit(num);
    int reverse = 0;
    while (digitSum != 0) {
        reverse *= 10;
        reverse += digitSum % 10;
        digitSum /= 10;
    }
    return reverse == sumDigit(num);
}

string recPal(int num) {
    int n = 0;
    while (!checkPal(num + n) && !checkPal(num - n)) {
        n++;
    }
    if (checkPal(num + n)) {
        return "Add " + to_string(n) + " to make it a palindrome\n";
    } else {
        return "Minus " + to_string(n) + " to make it a palindrome\n";
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Invalid number of argument(s)";
        return -1;
    }

    ifstream fileReader(argv[1]);
    ofstream fileWriter("Result.txt");
    int num;

    if (!fileReader || !fileWriter) {
        cerr << "Unable to read/write file";
        return -1;
    }

    while (fileReader >> num) {
        stringstream ss;
        ss << num << ": ";
        if (checkPal(num)) {
            ss << "Result " << sumDigit(num) << " is a palindrome\n" << endl;
        } else {
            ss << "Result " << sumDigit(num) << " is NOT a palindrome" << endl;
            ss << recPal(num) << endl;
        }
        fileWriter << ss.str();
        cout << ss.str();
    }

    fileReader.close(); 
    fileWriter.close();

}