#include <iostream>
#include <fstream>

class BankAcc {
   public:
    std::string name;
    float amount;

    BankAcc(std::string name, float amount) : name(name), amount(amount) {};

    std::string getInfo() {
        std::string output = "Name: " + name + "   Amount: $" + std::to_string(amount) + "\n";
        return output;
    }

    void withdraw(float num) {
        if (num > amount) {
            std::cerr << "Not enough money";
            return;
        }
        amount -= num;
    }
};

int main(int argc, char *argv[]) {
    
    BankAcc acc1("Hiep", 2000);
    BankAcc acc2("Vy", 1500);
    BankAcc acc3("Anh", 50);
    
    acc2.withdraw(1500);
    
    if (argc >= 2) {
        std::string fileName = argv[1];
        
        std::ofstream fileWriter(fileName, std::ios::app);

        fileWriter << acc1.getInfo();

        fileWriter.close();
        
    }


    return 0;
}