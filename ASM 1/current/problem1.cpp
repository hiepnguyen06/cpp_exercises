#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

int doubleVal(int num) {
    return num * 2;
}

float doubleVal(float num) {
    return num * 2;
}

int hex_to_dec(std::string hex) {
    std::string main = hex.substr(2, hex.length() - 2);

    int dec = 0;
    for (int i = 0; i < main.length(); i++) {
        int num;
        if (isdigit(main[i])) {
            num = main[i] - '0';
        } else {
            num = std::tolower(main[i]) - 87;
        }
        dec += num * std::pow(16, main.length() - 1 - i);
    }
    return dec;
}

int doubleVal(std::string hex) {
    // return std::stoi(hex, nullptr, 16) * 2;
    return hex_to_dec(hex) * 2;
}

int main(int argc, char* argv[]) {
    std::string argument = argv[1];
    if (argc >= 2) {
        // Detect for 0x
        if (argument.find("0x") != std::string::npos) { // if it is a hex
            std::cout << std::hex << std::showbase << doubleVal(argument);
        } else {
            if (argument.find(".") != std::string::npos) { // if it is a float
                std::cout << std::fixed << std::setprecision(2) << doubleVal(std::stof(argument));
            } else { // if it is an int
                std::cout <<  doubleVal(std::stoi(argument));
            }
        }
    }
    
    return 0;

    std::cout << doubleVal(12) << std::endl;
    std::cout << std::fixed << std::setprecision(2) << doubleVal(12.1235f) << std::endl;
    std::cout << std::hex << std::showbase << doubleVal("0xAC") << std::endl;

    std::stringstream ss;

    ss << std::hex <<  std::showbase << doubleVal("0xAC");
    std::string res = ss.str(); 
    std::cout << res;

    // std::cout << hex;

}