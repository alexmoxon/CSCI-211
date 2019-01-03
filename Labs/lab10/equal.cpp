
#include <iostream>
using namespace std;

bool equal_strings(const char str1[], const char str2[]) {
    
    if (str1[0] == 0 && str2[0] == 0) {
        
        return true;
        
    }
    
    else if (str1[0] != str2[0]) {
        
        return false;
        
    }
    
    else {
        
        return equal_strings(str1+1, str2+1);
    }
    
    
}

int main() {
    
    const int MAX = 1000;
    
    char str1[MAX];
    char str2[MAX];
    
    str1[0] = 0;
    str2[0] = 0;
    
    cout << "enter first string: ";
    cin >> str1;

    cout << "enter second string: ";
    cin >> str2;
    
    if (equal_strings(str1, str2)) {
        
        cout << "<" << str1 << "> is equal to <" << str2 << ">\n";
        
    }
    
    else {
        
        cout << "<" << str1 << "> is NOT equal to <" << str2 << ">\n";
        
    }
    
}