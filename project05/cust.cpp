//Filename: cust.cpp
//Created By: Moxon, Alex
//Ecst_username: amoxon

#include "cust.h"
#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
using namespace std;

//Cust Constructor
Cust::Cust (string name, bool robber, int arr_time, int num_of_item) {
    
    m_name = name;
    m_arr_time = arr_time;
    m_num_of_item = num_of_item;
    m_robber = robber;
    
}

//Function that prints output when customer enters store
void Cust::print_entered (ostream &os, int clock) {
    
    assert (clock == m_arr_time);
    
    os << clock << ": " << m_name << " entered store" << endl;
    
}

//Function that prints output when customer is done shopping
void Cust::finished_shopping (ostream &os, int clock) {
    
    assert (clock == shop_time);
    
    os << clock << ": " << m_name << " done shopping" << endl;
    
}

//Function that prints output when customer starts checkout
void Cust::start_check (ostream &os, int clock, int checker) {
    
    os << clock << ": " << m_name << " started checkout with checker " << checker << endl;
    
}

//Function that prints output when customer is done with checkout
void Cust::end_check (ostream &os, int clock, int money, int checker) {
    
    if (m_num_of_item > 1) {
        
        if (m_robber) {
            
            os << clock << ": " << m_name << " stole $" << money << " and " << m_num_of_item << " items from checker " 
            << checker << endl;
            
        }
        
        else {
                
            os << clock << ": " << m_name << " paid $" << money << " for " << m_num_of_item << " items to checker " 
            << checker << endl;
                
        }
        
    }
    
    else {
        
        if (m_robber) {
            
            os << clock << ": " << m_name << " stole $" << money << " and " << m_num_of_item << " item from checker " 
            << checker << endl;
            
        }
        
        else {
            
            os << clock << ": " << m_name << " paid $" << money << " for " << m_num_of_item << " item to checker " 
            << checker << endl;
            
        }
        
    }
    
}

//Function that returns number of items in customers basket
int Cust::get_items () {
    
    return m_num_of_item;
    
}

//Function that calculates the amount of time a customer spends shopping based on number of items in basket
int Cust::get_time_shop (int clock) {
    
    shop_time = (m_num_of_item * 2) + clock;
    return shop_time;
    
}

//Function that determines if customer is in fact a customer or a robber
bool Cust::is_robber () {
    
    if (m_robber) {
        
        return true;
        
    }
    
    else {
        
        return false;
        
    }
    
}

//Standard print function that prints output of customer
void Cust::print (ostream &os) {
    
    os << m_name << " " << (m_robber? "robber" : "shopper") << " " << 
    m_arr_time << " " << m_num_of_item << endl;
    
}

