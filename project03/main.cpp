//Filename: main.cpp
//Created By: Moxon , Alex
//Ecst_username: amoxon


#include <iostream>
using namespace std;

#include "vlist.h"
#include "video.h"

int main () {
    
    //Global Variables
    string command;
    string title;
    string link;
    string comment;
    double length_movie;
    int rating;
    
    //Creating list object
    Vlist list;
    
    //Loop that reads and executes set of commands
    while (getline(cin, command)) {
        
        if (command == "insert") { //Loop for inserting video command that adds new video to linked list
            
            
            getline(cin, title);
            
            getline(cin, link);
            
            getline(cin, comment);
            
            cin >> length_movie;
            
            cin >> rating;
            
            cin.ignore();
            
            Video *video = list.lookup(title); //Checking for duplicate title
            
            if (video == NULL) {
            
                list.insert(new Video(title, link, comment, length_movie, rating)); //If not duplicate title, pass new video object to Vlist insert
            
            }
            
            else {
                
                //Error output if title is already in linked list
                cerr << "Could not insert video <" << title << ">, already in list." << endl;
            }
        }
        
        else if (command == "print") { //Printing all videos in linked list
            
            list.print();
            
        }
        
        else if (command == "length") { //Prints integer of number of videos
            
            cout << list.leng() << endl;
            
        }
        
        else if (command == "lookup") { //If given title is in linked list -> print video
            
            getline(cin, title);
            
            Video *video = list.lookup(title);
            
            if (video != NULL) { //If given title is in video linked list -> print video
                
                video->print();
                
            }
            
            else {
                
                //Error output if title isn't found with lookup command
                cerr << "Title <" << title << "> not in list." << endl;
                
            }
            
        }
        
        else if (command == "remove") { //If given title is in the linked list, remove video
            
            getline(cin, title);
            
            if (list.remove(title) == false) {
                
                //Error output if title is not found in linked list
                cerr << "Title <" << title << "> not in list, could not delete." << endl;
                
            }
        }
        
        else {
            
            //Error output if input command is not valid
            cerr << "<" << command << "> is not a legal command, giving up." << endl;
            
            return 1;
            
        }
        
    }


   
    return 0;
}
