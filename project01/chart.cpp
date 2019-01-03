//Filename: chart.cpp
//Created By: Moxon , Alex
//Ecst_username: amoxon
//Created On: 1/24/2018
/*This program reads a set of integers form standard input and draws a bar chart to standard output
using asterisks and spaces.  The user can specify up to 100 integers greater than 0. When the user
enters a 0, the program will stop reading standard inputand print the chart.*/

#include<iostream>
using namespace std;

//Function that finds the largest integer in an array
int find_largest (int values[], int size) {
    
    int largest = 0; //Declaring the variable that will store the largest number in the array  

//For loop that runs through an array comparing numbers to find the largest    
    for (int i = 0; i < size; i++) {

        if (values[i] > largest) { //Comparing integers in an array to find the largest number

            largest = values[i];  //If loop that runs and stores new integer in largest variable, if bigger than previous largest variable  
        }
    }
        
    return largest; //Returning largest variable
}
    

int main() {
    
//Declaring constant int to set the size of the values array  
    const int MAX = 100;
    
    int values[MAX]; //Array variable
    int i,r,c; // Iteration, collum and row variables
    int size; //Variable that keeps track of total numbers cin'd
    
//For loop that takes in user input up to 100 and breaks when value is less than 1
    for (int i = 0; i < MAX; i++) {
        
        cin >> values[i]; //Taking in numbers from user
        
        ++size;
        
        if (values[i] < 1) { //If loop that breaks for loop if less than 1 is entered
            
            cout << endl;
            break;
        }
        
    }
    
    
    int largest = find_largest(values, size); //Sending user input array to function to find the largest number
    
/*For loop that starts with the largest input and compares each value during each iteration.
If the number is greater or equal to largest, we put a "*". If the number is less than the 
largest variable we put a space " ". */
    for (r = largest; r >= 1; r--) {
        
        for (int c = 0; c <= size - 1; c++) {
            
            if (values[c] >= r) {
            
                cout << "*";
            
            }
            
            else {
                
                cout << " ";
                
            }
            
        }
        
        cout << endl; //New line created during each iteration of the rows
        
    }
    
    return 0;
    
}
