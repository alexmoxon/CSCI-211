//Alex Moxon Lab 08

#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
#include <stdlib.h>

using namespace std;


bool legal_int(char *str) 
{
    
    while (*str) 
    {
        if (isdigit(*str) == false)
        {
            
            cerr << "Error: illegal integer." << endl;
            
            return false;
        
        }
        
        else 
        {
            str++;
        }
    }
    
    return true;
    
}

int main(int argc, char *argv[]) 
{
    int value = 0;
    
    if (argc < 2)
    {
        
        cerr << "Error: illegal integer." << endl;
        
        return 1;
        
    }
    
    for (int i = 1; i < argc; i++) 
    {
        
        if (legal_int(argv[i]) == true)
        {
            
            value = value + atoi(argv[i]);
            
        }
        
        else {
            
            return 1;
        }
        
    }
    
    cout << value << endl;
    
    
    return 0;
}