#include "LibrarySystem.h"
#include <iostream>

// Constructor definition
LibrarySystem::LibrarySystem() {
    // Initialize your library and transactions
}

// Menu function definition
int LibrarySystem::displayMenu() {
    int choice;
    std::cout << "========= Library Management System Menu =========" << std::endl;
    std::cout << "1. Add Book" << std::endl;
    std::cout << "2. Update Book" << std::endl;
    std::cout << "3. Display Books" << std::endl;
    std::cout << "4. Register Member" << std::endl;
    std::cout << "5. Display Members" << std::endl;
    std::cout << "6. Borrow Book" << std::endl;
    std::cout << "7. Return Book" << std::endl;
    std::cout << "8. Search Books" << std::endl;
    std::cout << "9. Generate Reports" << std::endl;
    std::cout << "10. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    return choice;
}

// Function to add a book
void LibrarySystem::addBook() {
    std::string title, author, ISBN;
    std::cout << "Enter book title: ";
    std::cin.ignore();
    std::getline(std::cin, title);
    std::cout << "Enter author name: ";
    std::getline(std::cin, author);
    std::cout << "Enter ISBN: ";
    std::getline(std::cin, ISBN);
    Book newBook(title, author, ISBN);
    libraryBooks.push_back(newBook);
    std::cout << "Book added successfully!" << std::endl;
}

// Function to update a book
void LibrarySystem::updateBook() {
    std::string ISBN;
    std::cout << "Enter ISBN of the book to update: ";
    std::cin >> ISBN;
    bool found = false;
    for (auto& book : libraryBooks) {
        if (book.ISBN == ISBN) {
            std::string newAuthor;
            std::cout << "Enter new author name: ";
            std::cin.ignore();
            std::getline(std::cin, newAuthor);
            book.author = newAuthor;
            std::cout << "Book details updated successfully!" << std::endl;
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Book with ISBN " << ISBN << " not found." << std::endl;
    }
}

// Function to display all books
void LibrarySystem::displayBooks() {
    std::cout << "List of books in the library:" << std::endl;
    for (const auto& book : libraryBooks) {
        book.displayInfo();
        std::cout << std::endl;
    }
}

// Function to register a member
void LibrarySystem::registerMember() {
    std::string name, contact;
    int membershipID;
    std::cout << "Enter member name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Enter contact information: ";
    std::getline(std::cin, contact);
    std::cout << "Enter membership ID: ";
    std::cin >> membershipID;
    Member newMember(name, contact, membershipID);
    libraryMembers.push_back(newMember);
    std::cout << "Member registered successfully!" << std::endl;
}

// Function to display all members
void LibrarySystem::displayMembers() {
    std::cout << "List of registered members:" << std::endl;
    for (const auto& member : libraryMembers) {
        member.displayInfo();
        std::cout << std::endl;
    }
}

// Function to borrow a book
void LibrarySystem::borrowBook() {
    std::string ISBN;
    int membershipID;
    std::cout << "Enter ISBN of the book to borrow: ";
    std::cin >> ISBN;
    std::cout << "Enter membership ID of the borrower: ";
    std::cin >> membershipID;
    bool bookFound = false;
    bool memberFound = false;
    for (auto& book : libraryBooks) {
        if (book.ISBN == ISBN) {
            bookFound = true;
            if (book.available) {
                for (auto& member : libraryMembers) {
                    if (member.membershipID == membershipID) {
                        memberFound = true;
                        Transaction transaction(book, member, "due_date_placeholder");
                        transactions.push_back(transaction);
                        book.available = false;
                        std::cout << "Book borrowed successfully!" << std::endl;
                        break;
                    }
                }
                if (!memberFound) {
                    std::cout << "Member with ID " << membershipID << " not found." << std::endl;
                    break;
                }
            } else {
                std::cout << "The book is already borrowed." << std::endl;
                break;
            }
        }
    }
    if (!bookFound) {
        std::cout << "Book with ISBN " << ISBN << " not found." << std::endl;
    }
}

// Function to return a book
void LibrarySystem::returnBook() {
    std::string ISBN;
    std::cout << "Enter ISBN of the book to return: ";
    std::cin >> ISBN;
    bool bookFound = false;
    for (auto& transaction : transactions) {
        if (!transaction.returned && transaction.book.ISBN == ISBN) {
            bookFound = true;
            transaction.markReturned();
            for (auto& book : libraryBooks) {
                if (book.ISBN == ISBN) {
                    book.available = true;
                    break;
                }
            }
            std::cout << "Book returned successfully!" << std::endl;
            break;
        }
    }
    if (!bookFound) {
        std::cout << "No active transaction found for book with ISBN " << ISBN << "." << std::endl;
    }
}

// Function to search for books
void LibrarySystem::searchBooks() {
    std::string searchTerm;
    std::cout << "Enter search term (title, author, or ISBN): ";
    std::cin.ignore();
    std::getline(std::cin, searchTerm);
    bool found = false;
    for (const auto& book : libraryBooks) {
        if (book.title.find(searchTerm) != std::string::npos ||
            book.author.find(searchTerm) != std::string::npos ||
            book.ISBN.find(searchTerm) != std::string::npos) {
            book.displayInfo();
            std::cout << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "No books found matching the search term." << std::endl;
    }
}

// Function to generate reports
void LibrarySystem::generateReports() {
    std::cout << "Borrowed Books Report:" << std::endl;
    for (const auto& transaction : transactions) {
        if (!transaction.returned) {
            std::cout << "Book: " << transaction.book.title << std::endl;
            std::cout << "Borrower: " << transaction.member.name << std::endl;
            std::cout << "Due Date: " << transaction.dueDate << std::endl;
            std::cout << std::endl;
        }
    }
}
