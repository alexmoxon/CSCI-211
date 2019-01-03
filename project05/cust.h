//Filename: cust.h
//Created By: Moxon, Alex
//Ecst_username: amoxon

#ifndef CUST_H
#define CUST_H
#include <iostream>
#include <string>
using namespace std;

//Cust class that stores information about the customer
class Cust {
    
    public:
    
    Cust (string name, bool robber, int arr_time, int num_of_item);
    
    void print_entered (ostream &os, int clock);
    void finished_shopping (ostream &os, int clock);
    void start_check (ostream &os, int clock, int checker);
    void end_check (ostream &os, int clock, int money, int checker);
    void print (ostream &os);
    
    int get_items ();
    int get_time_shop (int clock);
    
    bool is_robber ();
    
    
    private:
    
    int m_arr_time;
    int m_num_of_item;
    int shop_time;
    string m_name;
    bool m_robber;
    
};

#endif
    