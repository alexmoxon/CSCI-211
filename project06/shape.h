//Filename: shape.h
//Created By: Moxon, Alex
//Ecst_username: amoxon

#include "grid.h"
#ifndef SHAPE_H
#define SHAPE_H

//Shape class that holds x & y location of where shape is to be drawn
class Shape {
    
    public:
    
    Shape(int x, int y);
    virtual void draw(Grid &grid) = 0;
    
    protected:
    
    int m_x;
    int m_y;
    
};

#endif