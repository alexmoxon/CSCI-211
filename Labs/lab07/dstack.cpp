
#include <iostream>
#include <cstring>
using namespace std;
#include "dstack.h"

int num = 0;

Dstack::Dstack() {
    
    top = NULL;
}


Dstack::~Dstack() {
    
    Node *ptr = top;
    
    while (ptr != NULL) {
        
        Node *temp;
        temp = ptr;
        ptr = ptr->m_next;
        delete temp;
        
    }
    
}

void Dstack::push (double value) {
    
    num = num + 1;
    
    top = new Node(value, top);
    
}

bool Dstack::pop (double &value) {
    
    if (top == NULL) {
        
        return false;
    }
    
    Node *temp = top;
    
    top = top->m_next;
    
    value = temp->m_value;
    
    delete temp;
    
    num = num - 1;
    
    return true;
    
}


bool Dstack::empty() {
    
    if (top == NULL) {
        
        return true;
      
    }
    
    else {
        
        return false;
    
    }
}


int Dstack::size() {
    
    return num;
    
}



