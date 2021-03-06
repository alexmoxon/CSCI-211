// Fill in the functions at the bottom of this file
// 
#include <iostream>
using namespace std;
#include "list.h"

// on some machines member variables are not automatically initialized to 0
List::List()
{
    m_head = NULL;
}

// delete all Nodes in the list
// since they are dynamically allocated using new, they won't go away
// automatically when the list is deleted
// Rule of thumb: destructor deletes all memory created by member functions
List::~List()
{
    while (m_head)
    {
        Node *tmp = m_head;
        m_head = m_head->m_next;
        delete tmp;
    }
}

// always insert at the front of the list
// Note: this works even in the SPECIAL CASE that the list is empty
void List::insert(int value)
{
    m_head = new Node(value, m_head);
}

// iterate through all the Nodes in the list and print each Node
void List::print()
{
    for (Node *ptr = m_head; ptr; ptr = ptr->m_next)
    {
        cout << ptr->m_value << endl; 
    }
}

void List::compare(int target, int &less_than, int &equal, int &greater_than)
{
    less_than = 0;
    greater_than = 0;
    equal = 0;
    
    Node *ptr = m_head;
    
    if (!ptr) {
        
        m_head = new Node(target, m_head);
        
    }
    
    while (ptr) {
        
        if (target == ptr->m_value) {
            
            equal++;
            
            ptr = ptr->m_next;
            
        }
        
        else if (ptr->m_value > target) {
            
            greater_than++;
            
            ptr = ptr->m_next;
            
        }
        
        else {
            
            less_than++;
            
            ptr = ptr->m_next;
            
        }
        
        //delete ptr;
    }
    // put your code here 
}




