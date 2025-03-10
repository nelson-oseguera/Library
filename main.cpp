#include <iostream>
#include "LibrarySystem.h"

// Main Program 
int main() {
    // Create an instance of LibrarySystem
    LibrarySystem librarySystem;

    // Main loop for displaying the menu and executing user choices
    while (true) {
        // Display the menu and get the user's choice
        int choice = librarySystem.displayMenu();

        // Switch statement to handle user's choice
        switch (choice) {
            case 1:
                librarySystem.addBook();
                break;
            case 2:
                librarySystem.updateBook();
                break;
            case 3:
                librarySystem.displayBooks();
                break;
            case 4:
                librarySystem.registerMember();
                break;
            case 5:
                librarySystem.displayMembers();
                break;
            case 6:
                librarySystem.borrowBook();
                break;
            case 7:
                librarySystem.returnBook();
                break;
            case 8:
                librarySystem.searchBooks();
                break;
            case 9:
                librarySystem.generateReports();
                break;
            case 10:
                std::cout << "Exiting the program. Goodbye!" << std::endl; // Exit the program
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl; // Invalid Choice
                break;
        }
    }

    return 0;
}
