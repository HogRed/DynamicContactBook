// main.cpp
// Goal: provide a simple text-based menu to interact with the contact list
// We will:
//   - create a ContactList
//   - initialize it
//   - loop until the user chooses to exit
//   - on exit, free all memory with freeAll()

#include "contact_list.h" // include header file, which has all struct definitions and function prototypes
#include <iostream> // for input and output
#include <string> // for string operations and structure

// menu function
void displayMenu() {
	std::cout << "Contact List Menu:\n";
	std::cout << "1. Add Contact\n";
	std::cout << "2. Print Contacts\n";
	std::cout << "3. Find Contact\n";
	std::cout << "4. Delete Contact\n";
	std::cout << "5. Exit\n";
	std::cout << "Choose an option: ";
}

// main function
int main() {
	// create and initialize contact list
	ContactList myContacts;

	initList(myContacts);

	int choice; // for menu

	// call menu in a loop
	while (true) {
		displayMenu();
		std::cin >> choice;
		// add contact
		if (choice == 1) {
			std::string name, phone;
			std::cout << "Enter name: ";
			std::cin >> name;
			std::cout << "Enter phone: ";
			std::cin >> phone;
			addContact(myContacts, name, phone);
		}
		// print contacts
		else if (choice == 2) {
			printContacts(myContacts);
		}
		// find contact
		else if (choice == 3) {
			std::string name;
			std::cout << "Enter name to find: ";
			std::cin >> name;
			Contact* found = findContact(myContacts, name);
			if (found) {
				std::cout << "Found: " << found->name << ", Phone: " << found->phone << std::endl;
			}
			else {
				std::cout << "Contact not found." << std::endl;
			}
		}
		// delete contact
		else if (choice == 4) {
			std::string name;
			std::cout << "Enter name to delete: ";
			std::cin >> name;
			if (deleteContact(myContacts, name)) {
				std::cout << "Contact deleted." << std::endl;
			}
			else {
				std::cout << "Contact not found." << std::endl;
			}
		}
		// exit
		else if (choice == 5) {
			break; // exit loop
		}
		// invalid option
		else {
			std::cout << "Invalid option. Please try again." << std::endl;
		}
	}

	// free all memory before exiting
	freeAll(myContacts);

	return 0;
}