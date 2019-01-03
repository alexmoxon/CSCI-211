// replace my_object and My_object with the actual object name

// an object's .cpp file always includes that objects .h file
// never include a .cpp file!
#include <iostream>
using namespace std;
#include "course.h" 

void Course::Data(string dept, int number, int time) {
    
    Department = dept;
    
    Class_Num = number;
    
    Class_Time = time;
    
    return;
}
// example of how functions are specified
void Course::Print()
{
    // the code for the print function goes here

    cout << Department << " " << Class_Num << " at " << Class_Time << endl;
    
    return;


}
