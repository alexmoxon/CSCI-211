//Filename: grid.cpp
//Created By: Moxon, Alex
//Ecst_username: amoxon

#include <iostream>
#include "grid.h"
using namespace std;


//Constructor for Grid
Grid::Grid() {
    
    for (int row = 0; row < ROWS; row++) {
        
        for (int col = 0; col < COLS; col++) {
            
            base_grid[col][row] = ' ';
            
        }
        
    }
    
}

//Set function used so shapes can set individual characters on grid
void Grid::set(int x, int y, char c) {
    
    if (x >= 0 && x < COLS && y >= 0 && y < ROWS) {
        
        base_grid[x][y] = c;
        
    }
    
}

//Print function that iterates by each row, starting at row 0
void Grid::print() {
    
    for (int row = 0; row < ROWS; row++) {
        
        for (int col = 0; col < COLS; col++) {
            
            cout << base_grid[col][row];
            
        }
        
        cout << endl;
        
    }
    
}