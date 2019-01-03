//Filename: main.cpp
//Created By: Moxon , Alex
//Ecst_username: amoxon


#include "video.h"
#include<iostream>
#include<string>
using namespace std;

int main () {
    
    //Global Variables
    
    const int MAX = 100;
    double length_movie = 0.0;
    string title = " ";
    string comment = " ";
    string link = " ";
    string sorting_method = " ";
    int rating = 0;
    int method = 0;
    int i = 0;
    int count = 0;
    
    //Creating an array of pointers to video
    Video *arr[MAX];

    
    //Taking in user input for sorting method & sets to variable method for later use in switch statement.
    cin >> sorting_method;

    if (sorting_method == "rating" || sorting_method == "Rating") {
        
        method = 1;

    }

    else if (sorting_method == "length" || sorting_method == "Length") {
        
        method = 2;

    }

    else if (sorting_method == "title" || sorting_method == "Title") {
        
        method = 3;

    }

    else {

        //standard error output for sorting_method incorrect input
        cerr << sorting_method << " is not a legal sorting method, giving up." << endl;

        return 1;
    }
    
    //While loop that gets a video description and points it to new video array for each iteration (w/ i)
    while (getline(cin, title)) {

        getline(cin, title);
        
        if (title.empty()) {
            
            break;
        }


        getline(cin, link);

        getline(cin, comment);

        cin >> length_movie;

        cin.ignore();

        cin >> rating;
        

        //Setting new video into pointer array at iteration i
        arr[i] = new Video (title, link, comment, length_movie, rating);

        //If loop that runs only if number of video descriptions has reached max volume, that produces stabdard error output
        if (i == MAX) {

            cerr << "Too many videos, giving up." << endl;
            break;

        }
        
        //Counting each itteration
        i++;
        count++;

    }

    //Switch statement used to determine which sorting method user wanted
    switch (method) {
        
        //Bubble sorting algorithm used to order videos from highest to lowest rating for print function
        case 1:
        for (int last = count-1; last > 0; last--) {
            for (int cur = 0; cur < last; cur++) {
                if (arr[cur]->Rating(arr[cur+1]))
                swap(arr[cur], arr[cur+1]);
            }
        }
        
        break;
        
        //Bubble sorting algorithm used to order videos from longest to shortest length for print function
        case 2:
        for (int last = count -1; last > 0; last--) {
            for (int cur = 0; cur < last; cur++) {
                if (arr[cur]->Longer(arr[cur+1]))
                swap(arr[cur], arr[cur+1]);
            }
        }
        
        break;
        
        //Bubble sorting algorithm used to order videos alphabetically by first letter in title, to be used in print function
        case 3:
        for (int last = count -1; last > 0; last--) {
            for (int cur = 0; cur < last; cur++) {
                if (arr[cur]->Name(arr[cur+1]))
                swap(arr[cur], arr[cur+1]);
            }
        }
        
        break;
        
        default:
        cout << "Sorry but we incountered an error, restarting program.." << endl;
    }
    
    
    //For loop to print out print function of each array of pointers
    for (i = 0; i < count; i++) {
        
        arr[i]->Print();
        
    }
    
    
    return 0;
}
