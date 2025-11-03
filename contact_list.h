// contact_list.h
// Goal: define the core data structures and function prototypes for a simple contact book
// the contact book will be implemented as a singly linked list using raw pointers
// will manage memory manually with new/delete in the .cpp file

// Define a struct Contact that represents one person in the list.
// Fields we want:
// - name (std::string)
// - phone (std::string)
// - next (a Contact* pointer to the next Contact in the list, or nullptr if this is the last one)

// Add include guards to prevent double-inclusion of this header file.
#ifndef CONTACT_LIST_H
#define CONTACT_LIST_H
#endif // CONTACT_LIST_H
#include <string> // for std::string

// Define the Contact struct
// this houses data needed for linked list (e.g., name, phone, next pointer)
struct Contact {
	std::string name;
	std::string phone;
	Contact* next;
};

// Define a struct ContactList that just holds a pointer called head
// - head should be a Contact*
// - head will point to the first Contact in the list, or nullptr if the list is empty
struct ContactList {
	Contact* head;
};

// Function prototypes we will need:
// 1. initList(ContactList& list)
//    - set list.head to nullptr to initialize an empty list
void initList(ContactList& list);

// // 2. addContact(ContactList& list, const std::string& name, const std::string& phone)
//    - dynamically allocate a new Contact on the heap using "new"
//    - fill in its data
//    - insert it at the FRONT of the linked list
//    - update list.head
void addContact(ContactList& list, const std::string& name, const std::string& phone);

// 3. printContacts(const ContactList& list)
//    - walk the linked list starting from list.head
//    - print each contact's name and phone
//    - print "[empty list]" if there are no nodes
void printContacts(const ContactList& list);

// 4. findContact(const ContactList& list, const std::string& name)
//    - walk the linked list
//    - return a pointer to the Contact whose name matches
//    - if not found, return nullptr
Contact* findContact(const ContactList& list, const std::string& name);

// 5. deleteContact(ContactList& list, const std::string& name)
//    - remove ONE matching contact from the list
//    - must correctly relink the list so there is no "hole"
//    - must call delete on the removed node to free its memory
//    - return true if something was deleted, false if no match
bool deleteContact(ContactList& list, const std::string& name);

// 6. freeAll(ContactList& list)
//    - walk the list node-by-node
//    - delete every Contact we allocated with new
//    - set list.head back to nullptr at the end
void freeAll(ContactList& list);