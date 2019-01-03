#include"video.h"
#include<iostream>
#include<cstring>
using namespace std;

void Video::Info (string name, string url, string comments, double time, int score) {
    
    title = name;
    
    link = url;
    
    comment = comments;
    
    length = time;
    
    rating = score;
    
    return;
}
// example of how functions are specified
void Video::Print()
{
    // the code for the print function goes here

    cout << title << ", " << link << ", " << comment << ", " << length << ", " << rating << endl;
    
    return;


}
