//Filename: dstack.h
//Created By: Moxon, Alex
//Ecst_username: amoxon


#ifndef DSTACK_H
#define DSTACK_H
#include <iostream>
#include <string>
using namespace std;

//Stack Class
class Dstack {
    
    public:
    
    Dstack(); //Constructor
    ~Dstack(); //Destructor
    //void error();
    void push (double value); //Push a new element on top of the stack
    bool pop (double &value); //Remove and return the top element from the stack
    bool empty(); //Return true if stack is empty, false otherwise
    int size(); //Returns size of stack
    
    private:
    
    //Node Class
    class Node {
        
        public: 
        Node (double value, Node *next)
        {m_value = value; m_next = next;}
        double m_value;
        Node *m_next;
        
    };
    
    Node *top = NULL;
    
    
    
};

#endif