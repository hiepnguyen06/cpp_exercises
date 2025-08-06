#include <iostream>
#include <iomanip>
#include <cmath>

class ComplNum {
    private:
        double real;
        double imag;
    public:
        ComplNum() : real(0), imag(0) {} 

        ComplNum(double real, double imag) {
            this->real = real;
            this->imag = imag;
        }

        ComplNum operator -(ComplNum b) { // object - object
            return ComplNum(real - b.real, imag - b.imag);
        }

        ComplNum operator -(double b) { // object - double
            return ComplNum(real - b, imag - b);
        }

        friend ComplNum operator -(double a, ComplNum b); // double - object

        ComplNum operator --(int) { // object--
            real--;
            imag--;
            return *this;
        }

        ComplNum operator --() { // --object
            return (*this)--;
        }

        void getComplNum() {
            std::cout << std::fixed << std::setprecision(2) << real << " + " << imag << "i";
        }

        friend double getAbs(ComplNum complex);
       
};

ComplNum operator -(double a, ComplNum b) { // double - object
    return ComplNum(a - b.real, a - b.imag);
}

double getAbs(ComplNum complex) {
    return std::sqrt(std::pow(complex.real, 2) + std::pow(complex.imag, 2));
}

int main() {
    ComplNum a(2, 4);
    ComplNum b(1, 3);

   a.getComplNum();
   
   std::cout << "\n" << getAbs(a);

}