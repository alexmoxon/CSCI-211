#include <iostream>
using namespace std;

#include "course.h"

int main()
{
    
    Course programming;
    Course english;
    Course physics;
    
    programming.Data ("CSCI", 211, 1000);
    english.Data ("ENGL", 130, 1400);
    physics.Data ("PHYS", 204, 800);
    
    programming.Print();
    english.Print();
    physics.Print();
    
    return 0;
  
}
