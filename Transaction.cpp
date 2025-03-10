#include "Transaction.h"

// Constructor definition
Transaction::Transaction(Book book, Member member, std::string dueDate)
    : book(book), member(member), dueDate(dueDate), returned(false) {}

// Method to mark a transaction as returned
void Transaction::markReturned() {
    returned = true;
}
