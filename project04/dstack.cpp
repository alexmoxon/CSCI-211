//Filename: dstack.cpp
//Created By: Moxon, Alex
//Ecst_username: amoxon

#include "dstack.h"
#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

int num = 0; //Size of stack variable

//Linked list Constructor
Dstack::Dstack() {
    
    top = NULL;
    
}

//Linked list Desctructor
Dstack::~Dstack() {
    
    Node *ptr = top;
    
    while (ptr != NULL) {
        
        Node *temp;
        temp = ptr;
        ptr = ptr->m_next;
        delete temp;
        
    }
    
}

/*
void Dstack::error() {
    
    cerr << "Error: Invalid expression." << endl;
    
    exit(1);
    
}
*/

//Function that pushes new element to the top of the stack
void Dstack::push (double value) {
    
    num = num + 1;
    
    top = new Node(value, top);
    
}

//Function that removes top element from the stack
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

//Boolean Function that checks to see if stack is empty & returns true if empty & false if not empty
bool Dstack::empty() {
    
    if (top == NULL) {
        
        return true;
      
    }
    
    else {
        
        return false;
    
    }
}

//Function that returns size of stack
int Dstack::size() {
    
    return num;
    
}
