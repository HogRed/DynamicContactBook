// contact_list.cpp
// Implementation of the linked list contact book
// This file will include the logic for all the functions declared in contact_list.h

// doing manual memory management using "new" and "delete".
// VERY IMPORTANT: Every Contact we create with "new" MUST be deleted either in deleteContact() or freeAll().
#include "contact_list.h"
#include <iostream>


// implement initList(ContactList& list)
void initList(ContactList& list) {
	list.head = nullptr;
}

// implement addContact(ContactList& list, const std::string& name, const std::string& phone)
void addContact(ContactList& list, const std::string& name, const std::string& phone) {
	Contact* newContact = new Contact; // dynamically allocate new Contact
	newContact->name = name; // fill in name
	newContact->phone = phone; // fill in phone
	newContact->next = list.head; // link new contact to current head
	list.head = newContact; // update head to new contact
}

// implement printContacts(const ContactList& list)
void printContacts(const ContactList& list) {
	if (list.head == nullptr) { // if list is empty
		std::cout << "[empty list]" << std::endl;
		return;
	}
	Contact* current = list.head; // use a pointer to walk the list
	while (current != nullptr) { // while we haven't reached the end
		std::cout << "Name: " << current->name << ", Phone: " << current->phone << std::endl;
		current = current->next;
	}
}

// implement findContact(const ContactList& list, const std::string& name)
Contact* findContact(const ContactList& list, const std::string& name) {
	Contact* current = list.head; // use a pointer to walk the list
	while (current != nullptr) { // while we haven't reached the end
		if (current->name == name) {
			return current;
		}
		current = current->next; // move to next contact
	}
	return nullptr; // not found
}

// implement deleteContact(ContactList& list, const std::string& name)
bool deleteContact(ContactList& list, const std::string& name) {
	Contact* current = list.head; // pointer to walk the list
	Contact* previous = nullptr; // pointer to keep track of previous contact
	while (current != nullptr) { //	while we haven't reached the end
		if (current->name == name) { // found the contact to delete
			if (previous == nullptr) { // if previous is null we make list.head point to current's next
				list.head = current->next;
			}
			else { // otherwise, we shift previous's next to use current's next
				previous->next = current->next;
			}
			delete current; // free memory & remove contact
			return true; // indicate successful deletion
		}
		previous = current; // move previous to current
		current = current->next; // move current to next contact
	}
	return false; // contact not found
}

// implement freeAll(ContactList& list)
void freeAll(ContactList& list) {
	Contact* current = list.head; // pointer to walk the list
	while (current != nullptr) { // while we haven't reached the end
		Contact* toDelete = current; // keep track of current to delete
		current = current->next; // move to next contact
		delete toDelete; // free memory & remove contact
	}
	list.head = nullptr; // set head to nullptr after memory is freed
}