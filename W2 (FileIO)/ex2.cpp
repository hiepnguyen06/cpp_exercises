#include <iostream>
#include <string>

void dispErr(std::string str, std::string reason) {
    std::cerr << str << " is NOT a hexadecimal\nReason: " << reason << "\n\n";
}

bool isHex(std::string str) {
    std::string prefix = str.substr(0, 2);
    std::string suffix = str.substr(2, str.length() - 2);

    // Checking prefix = 0x (if not -> error)
    if (prefix.compare("0x") != 0) {
        dispErr(str, "Wrong prefix");
        return false;
    }
    
    // Checking suffix (0-9, A-F, a,f)
    for (int i = 0; i < suffix.length(); i++) {
        if (isdigit(suffix[i])) continue;
        
        if (isalpha(suffix[i])) {
            char c = tolower(suffix[i]);
            if (c < 'a' || c > 'f') {
                dispErr(str, "Not a-f / A-F");
                return false;
            }
        } else {
            dispErr(str, "Invalid character");
            return false;
        }
    } 
    
    std::cout << str << " is a hexadecimal\n\n";
    return true;
}

int main() {
    isHex("0xA23PD");
    isHex("0xA23!D");
    isHex("OxD3AD");
    isHex("0xA5B");
    return 0;
}