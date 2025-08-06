#include <iostream>

using namespace std;

class Book {
   private:
    string title;
    int price;
    int availableCopies;
    string borrowerNames[10];

   public:
    Book() = default;
    Book(string title, int price, int availableCopies, string borrowerNames[10]) : title(title), price(price), availableCopies(availableCopies) {
        for (int i = 0; i < 10; i++) {
            this->borrowerNames[i] = borrowerNames[i];
        }
    }
    bool borrowBook(string borrowerName) {
        if (availableCopies < 1) return false;
        availableCopies--;
        return true;
    }
    void returnBook(string borrowerName) {
        for (auto& name : this->borrowerNames) {
            if (name.compare(borrowerName) == 0) {
                name = "NA";
                availableCopies++;
                return;
            }
        }
    }
    void returnAllBook(string borrowerName) {
        for (auto& name : this->borrowerNames) {
            if (name.compare(borrowerName) == 0) {
                name = "NA";
                availableCopies++;
            }
        }
    }
    void operator++(int) {
        availableCopies++;
    }
    friend void operator+(int n, Book& book) {
        book.price += n;
    }
    void getInfo() {
        cout << "Title: " << title << " ( $" << price << " ) " << " has " << availableCopies << " copies left" << endl;
    }
};

class User {
   private:
    string name;
    Book* borrowedBooks[5];

   public:
    User() = default;
    User(string name, Book* borrowedBooks[5]) : name(name) {
        for (int i = 0; i < 5; i++) {
            this->borrowedBooks[i] = borrowedBooks[i];
        }
    }
    bool doBorrow(Book* abook) {
        return abook->borrowBook(name);
    }
    void doReturn(Book* abook) {
        abook->returnBook(name);
    }
    void operator>>(Book& book) {
        book.returnAllBook(name);
    }
};

int main() {
    string borrowerNames[10] = {
        "Alice Johnson",
        "Bob Smith",
        "NA",
        "Diana Lee",
        "NA",
        "NA",
        "George Tran",
        "Hannah Liu",
        "NA",
        "NA"};
    Book bookA("The Giver", 48, 5, borrowerNames);
    bookA++;
    bookA++;
    50 + bookA;
    bookA.getInfo();
}
