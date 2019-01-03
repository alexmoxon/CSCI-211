//Filename: pqueue.cpp
//Created By: Moxon, Alex
//Ecst_username: amoxon

#include "pqueue.h"
#include "cust.h"
#include <iostream>
#include <assert.h>
using namespace std;

int size = 0; //size of queue
const int EMPTY = -1; //if priority is 0

//Function used to remove customers off queue
Cust *Pqueue::dequeue () {
    
    if (m_head == NULL) {
        
        return NULL;
        
    }
    
    else {
        
        size--;
        Node *tmp = m_head;
        m_head = m_head->m_next;
        
        return tmp->m_cust;
        
    }
    
}

//Function used to determine if queue is empty
bool Pqueue::empty () {
    
    if (m_head == NULL) {
        
        return true;
        
    }
    
    else {
        
        return false;
        
    }
    
}

//Function used to determine length of queue
int Pqueue::length () {
    
    return size;
    
}

//Function used to set priority of customers (based off of time)
int Pqueue::first_priority () {
    
    if (m_head == NULL) {
        
        return EMPTY;
        
    }
    
    else {
        
        return m_head->m_priority;
        
    }
    
}

//Function used to push customers onto the queueue based on priority (time)
void Pqueue::enqueue (Cust *cust, int priority) {
    
    if (m_head == NULL || priority < m_head->m_priority) {
        
        m_head = new Node (cust, priority, m_head);
        
    }
    
    else {
        
        Node *ptr = m_head;
        
        while (ptr->m_next != NULL) {
            
            if (ptr->m_next->m_priority <= priority) {
                
                ptr = ptr->m_next;
                
            }
            
            else {
                
                break;
                
            }
            
        }
        
        ptr->m_next = new Node (cust, priority, ptr->m_next);
        
    }
    
    size++;
    
}