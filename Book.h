#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
public:
    // Attributes
    std::string title;
    std::string author;
    std::string ISBN;
    bool available;

    // Constructor
    Book(std::string title, std::string author, std::string ISBN);
    // Method to display book information
    void displayInfo() const;
};

#endif
