//Filename: video.cpp
//Created By: Moxon , Alex
//Ecst_username: amoxon

#include <iostream>
#include <cstring>
using namespace std;

#include "video.h"
#include "vlist.h"

//Constructor
Video::Video (string title, string link, string comment, double length_movie, int rating) {

    name = title;

    url = link;

    comments = comment;

    length = length_movie;

    score = rating;

}

//Print Function
void Video::print() {
    
    cout << name << ", " << url << ", " << comments << ", " << length << ", ";
    
    //Switch statement allowing for * output of score
    switch (score) {
        
        case 1:
        cout << "*" << endl;
        break;
        
        case 2:
        cout << "**" << endl;
        break;
        
        case 3:
        cout << "***" << endl;
        break;
        
        case 4:
        cout << "****" << endl;
        break;
        
        case 5:
        cout << "*****" << endl;
        break;
    
    }


}


//Function used in Linked List to determine ordering alphabetically by video title
string Video::get_title() {
    
    return name;
}




//Function used to sort videos from highest to lowest rating
bool Video::rating(Video *scores) {
    
    return score<scores->score;
    
}

//Function used to sort videos from longest to shortest length
bool Video::longer(Video *other) {


    return length>other->length;

}

//Function used to sort videos based off of first letter in title
bool Video::naming(Video *title) {
    
    return name>title->name;
    
}
