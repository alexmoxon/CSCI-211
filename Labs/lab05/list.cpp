#include <iostream>
#include <string>
using namespace std;
#include "list.h"

// on some machines, member variables are not automaically initialized to 0

List::List() {

	m_head = NULL;

}

//Delete all Nodes in the list, since they're dynamically allocated using new, they won't go away
//Automatically when the list is deleted
//Rule of thumb: desctructor deletes all memeory created by member functions

List::~List() {

	// cout << "List::~List() was called" << endl;

	Node *ptr = m_head;
	while (ptr != NULL) {

		Node *temp;

		temp = ptr;
		ptr = ptr->m_next;
		delete temp;

	}

}

//Always insert at the front of the list
//Note: this works even in the SPECIAL CASE that the list is empty

void List::insert(int value) {

	m_head = new Node(value, m_head);

}

//Iterate through all the Nodes in the list and print each Node

void List::print() {

	Node *ptr = m_head;

	while (ptr != NULL) {

		cout << ptr->m_value << endl;
		
		ptr = ptr->m_next;

	}
	
}

int List::sum() {
    
    int sum = 0;
    
    Node *hold = m_head;
    
    while (hold != NULL) {
        
        sum = sum + hold->m_value;
        
        hold = hold->m_next;
        
    }
    
    return sum;
}

void List::insert_at_end(int value) {
    
    if (m_head == NULL) {
        
        m_head = new Node(value, NULL);
    }
    
    else {
        
        Node *temp = m_head;
        
        while (temp->m_next != NULL) {
            
            temp = temp->m_next;
            
        }
        
        temp->m_next = new Node (value, NULL);
        
    }
}