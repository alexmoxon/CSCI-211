
#include "pqueue.h"
#include "cust.h"
#include <iostream>
using namespace std;

int main() {
    
    Pqueue q;
    
    cout << "q contains " << q.length() << " elements." << endl;
    cout << "the priority of the first element == " << q.first_priority() << "." << endl;
    
    q.enqueue(new Cust("One", 1, 1, true),1); 
    q.enqueue(new Cust("Two", 2, 2, false),2);
    q.enqueue(new Cust("Three", 3, 3,true),3);
    q.enqueue(new Cust("Four", 4, 4,false),4);
    
    
    cout << "removing and printing all elements on the priority queue" << endl;
    cout << "should be ordered One, Two, Three, Four" << endl;
    
    while (q.empty() == false) {
        
        Cust *cust = q.dequeue();
        cust->print(cout);
        delete cust;
        
    }
    
    cout << "q contains " << q.length() << " elements." << endl;
    
    
    q.enqueue(new Cust("Three", 3, 3,true),3);
    q.enqueue(new Cust("One", 1, 1, true),1);
    q.enqueue(new Cust("Four", 4, 4,false),4);
    q.enqueue(new Cust("Two", 2, 2, false),2);
    
    
    cout << endl;
    cout << "removing and printing all elements on the priority queue" << endl;
    cout << "should be ordered One, Two, Three, Four" << endl;
    
    while (q.empty() == false) {
        
        Cust *cust = q.dequeue();
        cust->print(cout);
        delete cust;
    }
    
    
    cout << "q contains " << q.length() << " elements." << endl;
    
    q.enqueue(new Cust("Four", false, 4, 4) ,40);
    cout << "q contains " << q.length() << " elements." << endl;
    cout << "the priority of the first element == " << q.first_priority() << "." << endl;
    
    q.enqueue(new Cust("Three", true, 3, 3),30);
    cout << "q contains " << q.length() << " elements." << endl;
    cout << "the priority of the first element == " << q.first_priority() << "." << endl;
    
    q.enqueue(new Cust("Two", false, 2, 2),20);
    cout << "q contains " << q.length() << " elements." << endl;
    cout << "the priority of the first element == " << q.first_priority() << "." << endl;
    
    q.enqueue(new Cust("One", true, 1, 1),10);
    cout << "q contains " << q.length() << " elements." << endl;
    cout << "the priority of the first element == " << q.first_priority() << "." << endl;
    
    
    cout << endl;
    cout << "removing and printing all elements on the priority queue" << endl;
    cout << "should be ordered One, Two, Three, Four" << endl;
    
    while (q.empty() == false) {
        
        Cust *cust = q.dequeue();
        cust->print(cout);
        delete cust;
        
    }
    
    cout << "q contains " << q.length() << " elements." << endl;
    q.enqueue(new Cust("One", true, 1, 1), 42);
    q.enqueue(new Cust("Two", false, 2, 2), 42);
    q.enqueue(new Cust("Three", true, 3, 3), 42);
    q.enqueue(new Cust("Four", false, 4, 4), 42);
    
    
    cout << endl;
    cout << "removing and printing all elements on the priority queue" << endl;
    cout << "should be ordered One, Two, Three, Four" << endl;
    
    while (q.empty() == false) {
        
        Cust *cust = q.dequeue();
        cust->print(cout);
        delete cust;
        
    }
    
    cout << "q contains " << q.length() << " elements." << endl;
    
    return 0;
    
}