// replace MY_OBJECT and My_object with the actual object name

// use all caps for these
#ifndef COURSE_H
#define COURSE_H
#include <string>

// put any includes here (such as #include <iostream>)

class Course
{
    public:
        void Data (string dept, int number, int time);
        void Print();
        
    private:
        string Department;
        int Class_Num;
        int Class_Time; 
        // member variables go here
        // member function used only by other member functions go here

}; // don't forget this ;

#endif



