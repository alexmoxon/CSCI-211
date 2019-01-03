//Filename: video.h
//Created By: Moxon , Alex
//Ecst_username: amoxon

#ifndef VIDEO_H
#define VIDEO_H
#include <string>
using namespace std;

class Video {
    
    //Public member functions
    public:
        Video (string title, string link, string comment, double length_movie, int rating);
        Video();
        void Print();
        bool Rating (Video *scores);
        bool Longer (Video *other);
        bool Name (Video *title);
        
    //Private member variables    
    private:
        string name;
        string url;
        string comments;
        double length;
        int score;
        int meth;

};

#endif
