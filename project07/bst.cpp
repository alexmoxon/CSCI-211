//Filename: bst.cpp
//Created By: Moxon , Alex
//Ecst_username: amoxon

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <math.h>
#include "bst.h"

using namespace std;

//BST Constructor
BST::BST() {
    
    m_root = NULL;
    
}

//BST Destructor
BST::~BST() {
    
    delete m_root;
    
    m_root = NULL;
    
}


//BST Command balanced, public function
int BST::balanced() {
    
    return balanced(m_root);
    
}

//BST Command balanced, private function
int BST::balanced(Node *cur_root) {
    
    if (cur_root == NULL) {
        
        return 0;
        
    }
    
    int left = balanced(cur_root->m_left);
    int right = balanced(cur_root->m_right);
    
    if (left == -1 || right == -1) {
        
        return -1;
    }
    
    if (abs(left - right) > 1) {
        
        return -1;
    }
    
    else {
        
        return (left > right ? left+1 : right+1);
    }
    
}

//BST Command to find size (# of elements in tree) of tree
int BST::size() {
    
    return m_length;
    
}

//BST Command to find distance from nodes to root, public function
int BST::distance(int level) {
    
    return distance(m_root, level);
    
}

//BST Command to find distance from nodes to root, private function
int BST::distance(Node *cur_root, int level) {
    
    if (cur_root != NULL) {
        
        return level + distance(cur_root->m_left, level + 1) + distance(cur_root->m_right, level + 1);
        
    }
    
    else {
        
        return 0;
        
    }
    
}

//BST Command to see if target is already in tree, public function
bool BST::find(string target) {
    
    return find(target, m_root);
    
}

//BST Command to see if target is already in tree, private function
bool BST::find(string target, Node *cur_root) {
    
    if (cur_root == NULL) {
        
        return false;
        
    }
    
    if (cur_root->m_value == target) {
        
        return true;
        
    }
    
    if (target < cur_root->m_value) {
        
        return find(target, cur_root->m_left);
        
    }
    
    else {
        
        return find(target, cur_root->m_right);
        
    }
    
}

//BST command used to insert values into tree, public function
bool BST::insert(string value) {
    
    return insert(value, m_root);
    
}

//BST Command used to insert values into tree, private function
bool BST::insert(string value, Node *&cur_root) {
    
    if (cur_root == NULL) {
        
        m_length++;
        cur_root = new Node(value);
        
        return true;
        
    }
    
    if (cur_root->m_value == value) {
        
        return false;
        
    }
    
    if (value < cur_root->m_value) {
        
        return insert(value, cur_root->m_left);
        
    }
    
    else {
        
        return insert(value, cur_root->m_right);
        
    }
    
}

//BST Command used to print all elements of tree in DFT, public function
bool BST::print_depth(vector <string> &values) {
    
    return print_depth(values, m_root);
    
}

//BST Command used to print all elements of tree in DFT, private function
bool BST::print_depth(vector <string> &values, Node *cur_root) {
    
    if (cur_root == NULL) {
        
        return false;
        
    }
    
    else {
        
        print_depth(values, cur_root->m_left);
        values.push_back(cur_root->m_value);
        print_depth(values, cur_root->m_right);
        
        return true;
    }
    
}

//BST Command used to print all elements of tree in BFT, public function which doesn't work
void BST::breadth(vector <string> &values) {
    
    values.clear();
    
    queue <Node*> node_queue;
    node_queue.push(m_root);
    
    while (!node_queue.empty()) {
        
        Node *tmp = node_queue.front();
        node_queue.pop();
        
        values.push_back(tmp->m_value);
        
        if (tmp->m_left != NULL) {
            
            node_queue.push(tmp->m_left);
            
        }
        
        if (tmp->m_right != NULL) {
            
            node_queue.push(tmp->m_right);
            
        }
        
    }
    
}

//BST Command used to modify tree so that it's rebalanced, public function 
void BST::rebalance(vector <string> &elements, int start_index, int end_index) {
    
    delete m_root;
    
    m_root = NULL;
    
    insert_from_vector(elements, start_index, end_index);
    
}

//BST Command that runs from rebalance command, rebalancing tree with calls to insert function
void BST::insert_from_vector(vector <string> &strings, int start_index, int end_index) {
    
    if (start_index <= end_index) {
        
        int middle_index = ( (start_index + end_index) / 2 );
        
        insert(strings[middle_index]);
        
        insert_from_vector(strings, start_index, middle_index - 1);
        insert_from_vector(strings, middle_index + 1, end_index);
        
    }
    
}