//Filename: path.cpp
//Created By: Moxon, Alex
//Ecst_username: amoxon

#include <iostream>
#include <vector>
#include "location.h"
using namespace std;





int main () {
    
    double lat;
    double longi;
    
    vector<Location*> loc; // declares a vector of pointers to class Location

    while (cin >> lat) {
        
        cin >> longi;
            
        loc.push_back(new Location(lat, longi)); // create a new Location object and insert it at end of vecto
        
    }

    for (int i = 0; i < (signed)loc.size(); i++) {
        
        loc[i]->print(cout);
        
        cout << endl;
        
    }
    
    return 0;
}