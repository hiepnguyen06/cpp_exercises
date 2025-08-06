#include <iostream>
#include <iomanip>

#if 1

class Vec {
   private:
    double real;
    double imag;

   public:
    Vec(double real, double imag) : real(real), imag(imag) {};
    
    Vec operator +(Vec b) { // Operator overloading to add two vectors
        return Vec(real + b.real, imag + b.imag);
    }

    Vec operator ++() { // Unary operator overloading (prefix)
        return Vec(real++, imag++);
    }

    Vec operator --(int) {  // Unary operator overloading (postfix)
        return Vec(real--, imag--);
    }

    void toString() {
        std::cout << std::fixed << std::setprecision(2) << real << " + " << imag << "i";
    }

    friend Vec operator *(double a, Vec b);
};

Vec operator *(double a, Vec b) {
    return Vec(a * b.real, a * b.imag);
}


int main() {
    Vec a(10, 5);
    Vec b(2, 3);

    Vec c = a + b;
    c = 2 * c;
    c.toString();
    
    
    
    return 0;
}
#endif

#if 0
int main() {



    return 0;
}


#endif