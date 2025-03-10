#ifndef MEMBER_H
#define MEMBER_H

#include <string>

class Member {
public:
    // Attributes
    std::string name;
    std::string contact;
    int membershipID;

    // Constructor
    Member(std::string name, std::string contact, int membershipID);
    // Method to display member information
    void displayInfo() const;
};

#endif
