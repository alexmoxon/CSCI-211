//Filename: point.h
//Created By: Moxon, Alex
//Ecst_username: amoxon

#include "grid.h"
#include "shape.h"
#ifndef POINT_H
#define POINT_H

//Point class that inherit Shape class
class Point : public Shape {
    
    public:
    
    Point(int x, int y, char c);
    void draw(Grid &grid);
    
    private:
    
    char m_c;
    
};

#endif