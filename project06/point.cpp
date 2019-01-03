//Filename: point.cpp
//Created By: Moxon, Alex
//Ecst_username: amoxon

#include "point.h"
#include <iostream>
using namespace std;

//Constructor
Point::Point(int x, int y, char c):Shape(x,y) {
    
    m_c = c;
    
}

//Function that sets and draws character at specified point on grid
void Point::draw(Grid &grid) {
    
    grid.set(m_x, m_y, m_c);
    
}