#include <fstream>
#include <iostream>

class Student {
   private:
    int score;
    std::string password;

   public:
    std::string name;

    Student(std::string name, int score) : name(name), score(score), password("") {};

    int getScore() { return score; }

    void getInfo() {
        std::cout << name << " (Score: " << score << ")\n";
    }

    std::string readPwd() {
        std::ifstream fileReader(name + ".dat");
        std::string password;

        while (getline(fileReader, password)) {
            fileReader >> password;
        }

        return password;
    }

    void writePwd(std::string pass) {
        std::ofstream fileWriter(name + ".dat");

        if (!fileWriter) {
            std::cerr << "File writing fails..";
            return;
        }

        fileWriter << pass;

        fileWriter.close();
    }

    bool hasPwd() {
        std::ifstream fileReader(name + ".dat");

        if (!fileReader) return false;
        return true;

    }

    void changePwd() {
        std::string pass;
        if (!hasPwd()) {
            std::cout << "Creating new account...\nPlease enter your new password: ";
            std::getline(std::cin, pass);
            writePwd(pass);
            std::cout << "Password saved...\n";
            return;
        }

        std::cout << "Your account exists. Please enter your password: ";
        std::getline(std::cin, pass);

        if (pass.compare(readPwd()) != 0) {  // if they are not equal
            std::cerr << "Wrong password. Try again\n";
            return;
        }

        std::cout << "Correct password. Enter your new password: ";
        std::getline(std::cin, pass);
        writePwd(pass);
        std::cout << "Password saved...\n";
    }
};

int main() {
    std::string name, pass;
    std::cout << "Enter name: ";
    std::getline(std::cin, name);
    Student student(name, 0);

    student.changePwd();

    return 0;
}