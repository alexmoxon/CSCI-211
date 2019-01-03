
#ifndef DSTACK_H
#define DSTACK_H

#include <string>

class Dstack {
    
    public:
    
    Dstack(); //Constructor
    ~Dstack(); //Destructor
    void push (double value); //Push a new element on top of the stack
    bool pop (double &value); //Remove and return the top element from the stack
    bool empty(); //Return true if stack is empty, false otherwise
    int size(); //Returns size of stack
    
    private:
    
    class Node {
        
        public: 
        Node (double value, Node *next)
        {m_value = value; m_next = next;}
        double m_value;
        Node *m_next;
        
    };
    
    Node *top;
    
    
    
};

#endif