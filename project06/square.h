//Filename: square.h
//Created By: Moxon, Alex
//Ecst_username: amoxon

#include "grid.h"
#include "shape.h"
#ifndef SQUARE_H
#define SQUARE_H

//Square class that inherits Shape class
class Square : public Shape {
    
    public:
    
    Square(int x, int y, int size);
    void draw(Grid &grid);
    
    private:
    
    int m_size;
    
};

#endif