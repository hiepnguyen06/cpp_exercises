#include <fstream>
#include <iostream>
#include <string>
#define NAME "textxx.txt"

int main() {
    std::fstream MyFile("text.txt", std::ios::in | std::ios::out | std::ios::trunc);

    if (!MyFile) {
        std::cerr << "Unable to open file";
        return 1;
    }

    MyFile << "Hello world";

    MyFile.close();
    MyFile.open("text.txt");

    std::string text;

    while (MyFile >> text) {
        std::cout << text << std::endl;
    }

    MyFile.close();
}