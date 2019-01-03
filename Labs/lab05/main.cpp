#include <iostream>
using namespace std;
#include "list.h"

int main() {

	//instantiate a List class (the constructor takes NO arguements)

	List list;
	
	int value;
	
	while (cin >> value) {
	    
	    list.insert_at_end(value);
	    
	}
	
	list.print();
	
	cout << "sum = " << list.sum() << endl;
	

	//Note: List list(); is incorrect, when there are no arguments don't use ()

	//Insert numbers into the list


	return 0;

}
