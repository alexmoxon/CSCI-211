//Filename: triangle.cpp
//Created By: Moxon, Alex
//Ecst_username: amoxon

#include "triangle.h"
#include <iostream>
using namespace std;

//Constructor
Triangle::Triangle(int x, int y):Shape(x,y) {
    
    
}

//Function that sets and draws triangle on grid based on user input specification
void Triangle::draw(Grid &grid) {
    
    grid.set(m_x + 2, m_y, '+');
    grid.set(m_x + 1, m_y + 1, '+');
    grid.set(m_x + 3, m_y + 1, '+');
    
    //loop that prints the bottom 5 '+' of triangle
    for (int col = m_x; col != 5 + m_x; col++) {
        
        grid.set(col, m_y + 2, '+');
        
    }
    
}