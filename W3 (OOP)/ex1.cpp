#include <fstream>
#include <iostream>
#define FILE_NAME "pwd.dat"

std::string readPass() {
    std::ifstream myFile(FILE_NAME);
    std::string pass;

    getline(myFile, pass);

    myFile.close();
    return pass;
}

void writePass(std::string pass) {
    std::ofstream myFile(FILE_NAME);

    myFile << pass;
    myFile.close();
    std::cout << "Saved to the file!\n";
}

int main() {
    while (true) {
        int select;
        std::cout << "Password Management Program: \n1. Save your password\n2. Read your password\nEnter an option (1/2): ";
        std::cin >> select;

        if (select != 1 && select != 2) {
            std::cout << "Program exits...\n";
            break;
        }

        if (select == 1) {
            std::string password;
            std::cout << "Enter the password: ";
            // std::cin.ignore(1); // Remove trailling new line
            std::getline(std::cin >> std::ws, password);
            writePass(password);
        } else {
            std::cout << "Your saved password: " << readPass();
        }

        std::cout << "\n";
    }

    return 0;
}