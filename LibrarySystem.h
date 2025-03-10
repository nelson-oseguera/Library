#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H

#include <vector>
#include "Book.h"
#include "Member.h"
#include "Transaction.h"

class LibrarySystem {
public:
    // Constructor
    LibrarySystem();
    // Menu function to display options to get user choice
    int displayMenu();
    // Functions to perform various operations
    void addBook();
    void updateBook();
    void displayBooks();
    void registerMember();
    void displayMembers();
    void borrowBook();
    void returnBook();
    void searchBooks();
    void generateReports();

private:
    // Vector to store books, members, and transactions
    std::vector<Book> libraryBooks;
    std::vector<Member> libraryMembers;
    std::vector<Transaction> transactions;
};

#endif
