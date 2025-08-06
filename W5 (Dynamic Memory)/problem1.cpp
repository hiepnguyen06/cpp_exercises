#include <iostream>

using namespace std;

class Book {
    private:
        string name;
        int price;
    public:
        Book(string name = "", int price = 0) : name(name), price(price) {}

        ~Book() {
            cout << "Book deleted" << endl;
        }

        void display() {
            cout << "Name: " << name << " Price: " << price << endl;
        }

        void setName(string name) { this->name = name; }
        void setPrice(int price) { this->price = price; }
        string getName() { return name; }
        int getPrice() { return price; }

};

#if 0
int main() {
    Book *b1 = new Book("The Giver", 19);
    Book *b2 = new Book("Harry Potter", 49);
    Book *b3 = new Book("Conan", 9);

    Book* books[] = { b1, b2, b3};

    for (Book* book: books) {
        if (book == nullptr) {
            cerr << "Null book";
            return -1;
        }
        cout << "Book Name: " << book->getName() << " (Price: " << book->getPrice() << ")" << endl;
        delete book;
    }

}
#endif


#if 1
int main() {
    int n;
    cout << "Enter the number of books: "; cin >> n;

    Book* bookArray = new Book[n];
    Book expensiveBook = bookArray[0];

    for (int i = 0; i < n; i++) {
        string bookName;
        int bookPrice;
        cout << "Enter book name " << i + 1 << ": "; getline(cin >> ws, bookName);
        cout << "Enter book price: "; cin >> bookPrice;

        bookArray[i].setName(bookName);
        bookArray[i].setPrice(bookPrice);
        bookArray[i].display();

        if (expensiveBook.getPrice() < bookArray[i].getPrice()) expensiveBook = bookArray[i];
    }

    cout << "Most expensive book: " << expensiveBook.getName() << " with price of " << expensiveBook.getPrice() << endl;

}
#endif