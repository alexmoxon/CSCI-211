//Filename: circle.h
//Created By: Moxon, Alex
//Ecst_username: amoxon

#include "grid.h"
#include "shape.h"
#ifndef CIRCLE_H
#define CIRCLE_H

//Circle class that inherits Shape class
class Circle : public Shape {
    
    public:
    
    Circle(int x, int y);
    void draw(Grid &grid);
    
    private:
    
};

#endif