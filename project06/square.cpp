//Filename: square.cpp
//Created By: Moxon, Alex
//Ecst_username: amoxon

#include <iostream>
#include "square.h"
using namespace std;

//Function that gets the size of square
Square::Square(int x, int y, int size):Shape(x,y) {
    
    m_size = size;
    
}

//Function that will draw size X size square onto grid
void Square::draw(Grid &grid) {
    
    //Loop the draws out size X size square on grid using '*' character
    for (int row = m_y; row != m_size + m_y; row++) {
        
        grid.set(m_x, row, '*');
        
        grid.set(m_x + m_size - 1, row, '*');
        
    }
    
    for (int col = m_x; col != m_size + m_x; col++) {
        
        grid.set(col, m_y, '*');
        
        grid.set(col, m_y + m_size - 1, '*');
        
    }
    
}