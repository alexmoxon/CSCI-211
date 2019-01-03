//Filename: circle.cpp
//Created By: Moxon, Alex
//Ecst_username: amoxon

#include "circle.h"
#include <iostream>
using namespace std;

//Circle Constructor
Circle::Circle(int x, int y):Shape(x,y) {
    
    
}

//Function that sets and draws circle based on user input
void Circle::draw(Grid &grid) {
    
    grid.set(m_x + 1, m_y, 'o');
    grid.set(m_x + 2, m_y, 'o');
    grid.set(m_x, m_y + 1, 'o');
    grid.set(m_x + 3, m_y + 1, 'o');
    grid.set(m_x, m_y + 2, 'o');
    grid.set(m_x + 3, m_y + 2, 'o');
    grid.set(m_x + 1, m_y + 3, 'o');
    grid.set(m_x + 2, m_y + 3, 'o');
    
}