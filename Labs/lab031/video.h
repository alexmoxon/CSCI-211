#include<iostream>
#ifndef VIDEO_H
#define VIDEO_H
#include <cstring>


class Video
{
    public:
        void Info (string name, string url, string comments, double time, int score);
        void Print();
        
    private:
        string title;
        string link;
        string comment;
        double length = 0.0;
        int rating = 0;
        
        // member variables go here
        // member function used only by other member functions go here

}; // don't forget this ;

#endif



