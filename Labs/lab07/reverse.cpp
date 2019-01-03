// Alex Moxon
// Lab 7

#include <iostream>
using namespace std;
#include "dstack.h"

int main() {

    double value;
    Dstack stack;
    
    while (cin >> value) {
        
        stack.push(value);
    }
    
    cout << "There are " << stack.size() << " numbers in the stack." << endl;
    
    while (!stack.empty()) {
        
        stack.pop(value);
        
        cout << value << endl;
        
    }
    
    cout << "There are " << stack.size() << " numbers in the stack." << endl;
    
    return 0;
    
}