//Filename: video.cpp
//Created By: Moxon , Alex
//Ecst_username: amoxon


#include "video.h"
#include<iostream>
#include <string>
using namespace std;

//Default Constructor
Video::Video() {
    
    name = " ";
    url = " ";
    comments = " ";
    length = 0.0;
    score = 0;
}

//Constructor
Video::Video (string title, string link, string comment, double length_movie, int rating) {

    name = title;

    url = link;

    comments = comment;

    length = length_movie;

    score = rating;

}

//Print Function
void Video::Print() {
    

    cout << name << ", " << url << ", " << comments << ", " << length << ", " << score << endl;


}

//Function used to sort videos from highest to lowest rating
bool Video::Rating (Video *scores) {
    
    return score<scores->score;
    
}

//Function used to sort videos from longest to shortest length
bool Video::Longer (Video *other) {


    return length>other->length;

}

//Function used to sort videos based off of first letter in title
bool Video::Name (Video *title) {
    
    return name>title->name;
    
}
