//Filename: bst.h
//Created By: Moxon , Alex
//Ecst_username: amoxon

#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//Binary Search Tree Class w/ Node sub-class
class BST {
    
    public:
    
    BST();
    ~BST();
    
    int balanced();
    int size();
    int distance(int level);
    
    bool find(string target);
    bool insert(string value);
    bool print_depth(vector <string> &values);
    
    void breadth(vector <string> &values);
    void rebalance(vector <string> &elements, int start_index, int end_index);
    
    private:
    
    class Node {
        
        public:
        
        Node(string value) {
            
            m_value = value;
            m_left = NULL;
            m_right = NULL;
            
        }
        
        string m_value;
        Node *m_left;
        Node *m_right;
        ~Node(){delete m_left; delete m_right;}
        
    };
    
    Node *m_root = NULL;
    
    bool find(string target, Node *cur_root);
    bool insert(string value, Node *&cur_root);
    bool print_depth(vector <string> &values, Node *cur_root);
    //bool breadth(vector <string> &values, Node *cur_root);
    
    int distance(Node *cur_root, int level);
    int balanced(Node *cur_root);
    int m_length = 0;
    
    //void print_breadth(vector <string> &values);
    void insert_from_vector(vector <string> &strings, int start_index, int end_index);
    
    
};

#endif

