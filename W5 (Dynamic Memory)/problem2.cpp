#include <iostream>

using namespace std;

class Book {
    private:
        string *name;
        int price;
    public:
        Book(string name = "", int price = 0) : price(price) {
            this->name = new string(name);
        }

        ~Book() {
            delete name;
            cout << "Name and obj memory has been deleted";
        }

        void display() {
            cout << "Name: " << *name << " Price: " << price << endl;
        }

        void setName(string name) { *this->name = name; }
        void setPrice(int price) { this->price = price; }
        string getName() { return *name; }
        int getPrice() { return price; }

};

int main() {    
    Book *b1 = new Book("The Giver", 99);
    b1->setName("The Giver 2");
    b1->display();
    
    delete b1;

    return 0;
}