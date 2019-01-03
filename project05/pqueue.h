//Filename: pqueue.cpp
//Created By: Moxon, Alex
//Ecst_username: amoxon

#ifndef PQUEUE_H
#define PQUEUE_H
#include "cust.h"
#include <iostream>
using namespace std;

//Priority queue of Cust pointers (priority = time)
class Pqueue {
    
    public:
    
    Cust *dequeue ();
    bool empty ();
    int length ();
    int first_priority ();
    void enqueue (Cust *cust, int priority);
    
    
    private:
    
    //Linked-list for queue
    class Node {
        
        public:
        
        Node (Cust *cust, int priority, Node *next) {
            
            m_cust = cust;
            m_priority = priority;
            m_next = next;
            
        }
        
        Cust *m_cust;
        Node *m_next;
        int m_priority;
        
    };
    
    Node *m_head = NULL;
    
};

#endif