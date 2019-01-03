//Filename: grid.h
//Created By: Moxon, Alex
//Ecst_username: amoxon

#ifndef GRID_H
#define GRID_H

//Grid class, setting base grid width/height
class Grid {
    
    public:
    
    Grid();
    void set(int x, int y, char c);
    void print();
    
    private:
    
    static const int ROWS = 24;
    static const int COLS = 60;
    
    char base_grid[COLS][ROWS];
    
    
};

#endif