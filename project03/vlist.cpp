//Filename: vlist.cpp
//Created By: Moxon , Alex
//Ecst_username: amoxon

#include "vlist.h"
#include "video.h"
#include <iostream>
using namespace std;

//Variable for counting number of videos in linked list
int num_vids = 0;


Vlist::Vlist() //constructor
{
}



Vlist::~Vlist() { //destructor
    
    Node *ptr = m_head;
    
    while(ptr != NULL) {
        
        Node *temp;
        temp = ptr;
        ptr = ptr->m_next;
        delete temp;
    }
}


//Vlist of Video objects that inserts new Video object ordered alphabetically
void Vlist::insert(Video *video) {
    
    if (m_head == NULL || m_head->m_video->get_title()>video->get_title()) {
        m_head = new Node(video, m_head);
        num_vids = num_vids + 1;
    }
    
    else {
        
        Node *ptr = m_head;
        
        while (ptr->m_next != NULL && ptr->m_next->m_video->get_title() <video->get_title()) {
            
            ptr = ptr->m_next;
            
        }
        
        ptr->m_next = new Node(video, ptr->m_next);
        num_vids = num_vids + 1;
            
    } 
}



//Function that returns number of videos in linked list
int Vlist::leng() {
    
    return num_vids;
}



//Function that looks through linked list for identical video, if found print video object
Video *Vlist::lookup(string title) {
    
    Node *ptr = m_head;
    
    while (ptr != NULL) {
        
        if (ptr->m_video->get_title() == title) {
            
            return ptr->m_video;
            
        }
        
        ptr = ptr->m_next;
    }
    
    return NULL;
}



//Function that outputs all of the videos in Video linked list
void Vlist::print() {
    
    Node*ptr = m_head;
    while(ptr) {
        
        ptr->m_video->print();
        ptr = ptr->m_next;
    }
    
}

//Function that removes video from linked list if title is identical and re-alphabetizes linked list of Videos
bool Vlist::remove(string title) {
    
    if(m_head==NULL) {
        
        return false;
    }
    
    if (m_head->m_video->get_title()==title) {
        
        Node *tmp=m_head;
        
        m_head = m_head->m_next;
        
        delete tmp;
        
        num_vids = num_vids - 1;
        
        return true;
    }
    
    Node *ptr = m_head;
    
    while (ptr->m_next != NULL && ptr->m_next->m_video->get_title() != title) {
        
        ptr = ptr->m_next;
    }
    
    if (ptr->m_next == NULL) {
        
        return false;
    }
    
    Node *tmp = ptr->m_next;
    
    ptr->m_next = ptr->m_next->m_next;
    
    delete tmp;
    
    num_vids = num_vids - 1;
    
    return true;
    
}