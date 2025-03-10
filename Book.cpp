#include "Book.h"
#include <iostream>

// Constructor definition
Book::Book(std::string title, std::string author, std::string ISBN)
    : title(title), author(author), ISBN(ISBN), available(true) {}

// Method to display book information
void Book::displayInfo() const{
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "ISBN: " << ISBN << std::endl;
    std::cout << "Availability: " << (available ? "Available" : "Borrowed") << std::endl;
}
