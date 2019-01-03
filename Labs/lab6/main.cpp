#include <iostream>
using namespace std;
#include "list.h"

int main() {
    
    List list;
    
    int value;
    
    while (cin >> value) {
        
        list.insert_at_end(value);
        
    }
    
    list.print();
    
    cout << "Sum = " << list.sum() << endl;
    
    
    return 0;
}