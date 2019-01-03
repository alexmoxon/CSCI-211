#include <iostream>
#include <string>
using namespace std;
#include "list.h"

List::List() {
    
    m_head = NULL;
    
}


List::~List() {
    
    Node *ptr = m_head;
    
    while (ptr != NULL) {
        
        Node *temp;
        
        temp = ptr;
        ptr = ptr->m_next;
        
        delete temp;
        
    }
}


void List::insert(int value) {
    
    m_head = new Node(value, m_head);
    
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










