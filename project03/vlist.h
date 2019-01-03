//Filename: vlist.h
//Created By: Moxon , Alex
//Ecst_username: amoxon

#ifndef VLIST_H
#define VLIST_H

using namespace std;

#include "video.h"

//Linked list of Video objects
class Vlist {
    
    //Public member functions
    public:
    
    Vlist(); //Constructors
    ~Vlist(); //Destructor
    void insert(Video *video);
    void print();
    int leng();
    bool remove(string title);
    Video *lookup(string title);
    
    //Private member variables
    private:
    
    //Class Node defined within Vlist class
    class Node {
        
        public:
        
        Node(Video *video, Node *next)
        {m_video=video; m_next = next;}
        
        
        Video *m_video;
        Node *m_next;
        
    };
    
    Node *m_head = NULL;

    
};

#endif