//Filename: sim.cpp
//Created By: Moxon, Alex
//Ecst_username: amoxon

#include <iostream>
#include <fstream>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "pqueue.h"
#include "cust.h"
using namespace std;

//Required Checker Struct
struct Checker {
    
    Cust *cust;
    int cash;
    int available_time;
    int done_check;
    
};

//Function that runs simulation of Kwik-E-Mart but only if no errors are found
void run_simulation (Pqueue *arrival_q, int num_checkers, int checker_break, ostream &os) {
    
    int time = 1;
    int num_customers = arrival_q->length(); //initializing num_customers to equal the number of customers in arrival_q
    
    Pqueue *shopping_q = new Pqueue(); //Creating a queue for shoppers
    Pqueue *checker_q = new Pqueue(); //Creating a queue for checkers
    
    
    //Creating an array of checker structures
    Checker *checker = new Checker[num_checkers];
    
    //Loop initializing all elements of the Checker structure
    for (int i = 0; i < num_checkers; i++) {
        
        checker[i].cash = 100;
        checker[i].available_time = 1;
        
    }
    
    //For loop that runs until no more customers in queue
    for (int clock = 1; num_customers > 0; clock++) {
        
        time = clock;
        
        //For loop that iterates until length of queue is met
        for (int i = 0; i < arrival_q->length(); i++) {
            
            //Loop that dequeues customer if arrival time = clock
            if (arrival_q->first_priority() == clock) {
                
                Cust *cust = arrival_q->dequeue();
                
                cust->print_entered(os, clock);
                
                shopping_q->enqueue(cust, cust->get_time_shop(clock));
                
            }
            
        }
        
        //For loop that runs when customer is done shopping & ready for checkout
        for (int i = 0; i < shopping_q->length(); i++) {
            
            if (shopping_q->first_priority() == clock) {
                
                Cust *cust = shopping_q->dequeue();
                
                cust->finished_shopping(os, clock);
                
                checker_q->enqueue(cust,1);
                
            }
            
        }
        
        //For loop for checkout that checks whether customer or robber
        for (int i = 0; i < num_checkers; i++) {
            
            if (checker[i].done_check == clock && checker[i].cust != NULL) {
                
                //If customer is a robber, run this loop and set cash = 0
                if (checker[i].cust->is_robber()) {
                    
                    checker[i].cust->end_check(os, clock, checker[i].cash, i);
                    checker[i].cash = 0;
                    
                    delete checker[i].cust;
                    
                    num_customers--;
                    
                    checker[i].cust = NULL;
                    checker[i].available_time = checker_break + clock;
                    
                }
                
                //If customer is not a robber, run this loop and add cash from items into register
                else {
                    
                    checker[i].cust->end_check(os, clock, checker[i].cust->get_items()* 3, i);
                    checker[i].cash += checker[i].cust->get_items() * 3;
                    
                    delete checker[i].cust;
                    
                    num_customers--;
                    
                    checker[i].cust = NULL;
                    
                }
                
            }
            
        }
        
        //For loop that runs & determines the amount of time spent at register, determined on whether robber or shopper
        for (int i = 0; i < num_checkers && !checker_q->empty(); i++) {
            
            if (checker[i].cust == NULL && checker[i].available_time <= clock) {
                
                checker[i].cust = checker_q->dequeue();
                
                //Loop that runs if checkers next customer is a robber
                if (checker[i].cust->is_robber()) {
                    
                    checker[i].done_check = 7 + clock;
                    
                }
                
                //Loop that runs if checkers next customer is not a robber
                else {
                    
                    checker[i].done_check = checker[i].cust->get_items() * 1 + clock;
                    
                }
                
                checker[i].cust->start_check(os, clock, i); //Prints out that customer is starting checkout
                
            }
            
        }
        
    }
    
    //Loop that prints out each checkers total $ in register after simulation is over
    for (int i = 0; i < num_checkers; i++) {
        
        os << "registers[" << i << "] = $" << checker[i].cash << endl;
        
    }
    
    //Prints out time spent during simulation + 1
    os << "time = " << time + 1 << endl;
    
}

//Function used in finding whether valid int given from input file
bool is_int (char *str) {
    
    int length = strlen(str);
    
    for (int i = 0; i < length; i++) {
        
        if (!isdigit(str[i])) {
            
            return false;
            
        }
        
    }
    
    return true;
    
}


//Main function, used primarily to determine if error from input/output file
int main (int argc, char *argv[]) {
    
    string customer_name;
    string customer_type;
    
    int customer_arrival;
    int customer_item;
    int num_checkers;
    int checker_break;
    
    Pqueue *arrival_q = new Pqueue(); //Customer object that is inserted onto the priority queue
    
    //Loop making sure no more than 4 command line arguments are taken in
    if (argc != 5) {
        
        cerr << "Error: invalid number of command line arguments." << endl;
        
        exit(1);
    }
    
    //opening input file
    ifstream ifile;
    ifile.open(argv[3]);
    
    //Loop to determine if input file can be found
    if (!ifile) {
        
        cerr << "Error: could not open input file <" << argv[3] << ">." << endl;
        
        exit(1);
        
    }
    
    //opening output file
    ofstream os;
    os.open(argv[4]);
    
    //Loop to determine if output file can be found
    if (!os) {
        
        cerr << "Error: could not open output file <" << argv[4] << ">." << endl;
        
        exit(1);
        
    }
    
    num_checkers = atoi(argv[1]);
    
    //Loop to detemine if amount of checkers given is correct
    if (is_int(argv[1]) == false || num_checkers < 1) {
        
        cerr << "Error: invalid number of checkers specified." << endl;
        
        exit(1);
        
    }
    
    checker_break = atoi(argv[2]);
    
    //Loop to determine if amount for checkers break is correct
    if (is_int(argv[2]) == false || checker_break < 0) {
        
        cerr << "Error: invalid checker break duration specified." << endl;
        
        exit(1);
        
    }
    
    //While loop that gets customer information from input file
    while (ifile >> customer_name) {
        
        ifile >> customer_type;
        ifile >> customer_arrival;
        ifile >> customer_item;
        
        //Reading in customers to the queue
        arrival_q->enqueue(new Cust(customer_name, (customer_type == "robber" ? 1 : 0), customer_arrival, customer_item), customer_arrival);
        
    }
    
    //Once all information is read from the input file and pushed onto the queue, run simulation
    run_simulation(arrival_q, num_checkers, checker_break, os);
    
    return 0;
}


