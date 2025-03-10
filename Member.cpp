#include "Member.h"
#include <iostream>

// Constructor definition
Member::Member(std::string name, std::string contact, int membershipID)
    : name(name), contact(contact), membershipID(membershipID) {}

// Method to display member information
void Member::displayInfo() const{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Contact: " << contact << std::endl;
    std::cout << "Membership ID: " << membershipID << std::endl;
}
