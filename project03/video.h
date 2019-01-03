//Filename: video.h
//Created By: Moxon , Alex
//Ecst_username: amoxon

#ifndef VIDEO_H
#define VIDEO_H

#include <string>
using std::string;

//Linked list of video objects
class Video {
    
    //Public member functions
    public:
    
    Video (string title, string link, string comment, double length_movie, int rating); //Constructor
    ~Video(); //Destructor
    void print();
    bool rating(Video *scores);
    bool longer(Video *other);
    bool naming(Video *title);
    string get_title();
        
    //Private member variables    
    private:
    
    string name;
    string url;
    string comments;
    double length;
    int score;

};

#endif
