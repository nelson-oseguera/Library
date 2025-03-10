#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Book.h"
#include "Member.h"

class Transaction {
public:
    // Attributes
    Book book;
    Member member;
    std::string dueDate;
    bool returned;

    // Constructor
    Transaction(Book book, Member member, std::string dueDate);
    // Method to display transaction information
    void markReturned();
};

#endif
