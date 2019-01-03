//Filename: main.cpp        
//Created By: Moxon , Alex
//Ecst_username: amoxon

#include <iostream>
#include <queue>
#include <vector>
#include "bst.h"

//Vector array of string values
vector <string> values;

using namespace std;

int main() {
    
    //BST object
    BST tree;
    
    bool commandError;
    
    string command; 
    string str;
    string targ;
    
    //While loop that takes command from input and checks else if statements for matches
    //Then implements strings in BST functions for the command taken from input
    while (cin >> command) {
        
        if (cin.peek() == '\n') {
            
            commandError = true;
            
        }
        
        else if (isspace(cin.peek())) {
            
            cin.ignore();
            
        }
        
        if (command == "echo") {
            
            getline(cin, str);
            
            cout << str << endl;
            
        }
        
        else if (command == "insert") {
            
            getline(cin, str);
            
            if (tree.insert(str) == true) {
                
                tree.insert(str);
            }
            
            else {
                
                cerr << "insert <" << str << "> failed. String already in tree." << endl;
                
            }
            
        }
        
        else if (command == "size") {
            
            cout << tree.size() << endl;
            
        }
        
        else if (command == "breadth") {
            
            tree.breadth(values);
            
            cout << "{";
            
            for (unsigned int i = 0; i < values.size() -1; i++) {
                
                cout << values[i] << ", ";
                
            }
            
            cout << values[values.size()-1] << "}" << endl;
            
        }
        
        else if (command == "find") {
            
            
            getline(cin, str);
            
            if (tree.find(str) == true) {
                
                cout << "<" << str << "> is in tree." << endl;
                
            }
            
            else {
                
                cout << "<" << str << "> is not in tree." << endl;
                
            }
            
        }
        
        else if (command == "print") {
            
            tree.print_depth(values);
            
            if (tree.print_depth(values) == false) {
                
                cout << "{}" << endl;
                
            }
        
        }

        else if (command == "distance") {
            
            if (tree.size() == 0) {
                
                cout << "Average distance of nodes to root = 0" << endl;
                
            }
            
            else {
                
                cout << "Average distance of nodes to root = " << tree.distance(0) / (double)tree.size() << endl;
                
            }
            
        }
        
        else if (command == "balanced") {
            
            if (tree.balanced() == -1) {
                
                cout << "Tree is not balanced." << endl;
                
            }
            
            else {
                
                cout << "Tree is balanced." << endl;
                
            }
            
        }
        
        else if (command == "rebalance") {
            
            values.clear();
            
            //tree.print_depth(values);
            
            tree.rebalance(values, 0, values.size() - 1);
            
        }
        
        //Standard error output if illegal command taken from input
        else {
            
            cerr << "Illegal command <" << command << ">." << endl;
            
            if (commandError == true) {
                
                
                
            }
            
            else if (!isspace(cin.peek())) {
                
                getline(cin, str);
                
            }
            
        }
        
        commandError = false;
    }
    
    return 0;
}