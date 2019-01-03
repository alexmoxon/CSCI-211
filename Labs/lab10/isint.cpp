
#include <iostream>
#include <ctype.h>
#include <assert.h>
using namespace std;

bool is_int (char str[]) {
    
    if (isdigit(str[0]) && str[0] != 0) {
        
        return true;
        
    }
    
    else {
        
        return false;
        
    }
    
}


int main() {
    
    const int MAX = 1000;
    char buf[MAX];
    
    cout << "Enter a string: ";
    cin >> buf;
    
    if (is_int(buf) == true) {
        
        cout << "<" << buf << "> is an integer.\n";
        
    }
    
    else {
        
        cout << "<" << buf << "> is NOT an integer.\n";
        
    }
    
}
