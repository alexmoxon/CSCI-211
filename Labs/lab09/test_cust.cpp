
#include "cust.h"
#include <iostream>

using namespace std;

int main() {
    
    Cust *cust = new Cust ("Homer", false, 42, 12);
    cust->print(cout);
    
    delete cust;
    
    cust = new Cust ("Bart", true, 86, 2);
    cust->print(cout);
    
    
    return 0;
}

