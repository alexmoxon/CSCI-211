//Filename: triangle.h
//Created By: Moxon, Alex
//Ecst_username: amoxon

#include "grid.h"
#include "shape.h"
#ifndef TRIANGLE_H
#define TRIANGLE_H

//Triangle class that inherits Shape class
class Triangle : public Shape {
    
    public:
    
    Triangle(int x, int y);
    void draw(Grid &grid);
    
    private:
    
};

#endif