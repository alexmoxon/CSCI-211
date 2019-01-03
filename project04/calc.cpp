//Filename: calc.cpp
//Created By: Moxon, Alex
//Ecst_username: amoxon

#include <iostream>
#include <cmath>
#include <cstdlib>
#include "stdio.h"
#include "dstack.h"
using namespace std;


//Function that runs if input is not valid. Prints to standard error & terminates program
void error() {
    
    cerr << "Error: Invalid expression." << endl;
    
    exit(1);
}



int main() {
    
    //Creating object in stack using dynamic allocation
    Dstack stack;
    
    char op; //Operator variable taken from cin
    double number; //Operand variable taken from cin
    double operand1, operand2; //Operand variables popped from stack 
    double total; //Result of calculation
    
    
    //While loop that runs until end of file is reached
    while (cin.peek() != EOF) {
        
        
        //If loop that ignores all spaces
        if (isspace(cin.peek())) {
            
            cin.ignore();
            
        }
        
        
        //Else if loop that runs if next character in the input is a number or decimal
        else if (isdigit(cin.peek()) == true || cin.peek() == '.') {
            
            cin >> number;
           
           
            //If loop that pushes number onto stack if input was valid and next character isn't a decimal
            if (cin.good() == true && cin.peek() != '.') {
                
                stack.push(number);
                
            }
            
            
            //Else loop that prints standard error if input is not a valid post-fix expression.
            else {
                
                error();
                
            }
            
        }
        
        //Loop that runs if two operands on stack & next input is an operator
        else if ((stack.size() >= 2) && (cin.peek() == '+' || cin.peek() == '-' 
                 || cin.peek() == '*' || cin.peek() == '/' || cin.peek() == '^')) {
                     
                    cin >> op;
                     
                    //Switch statement that gives specific application on operands, based off operator
                    switch (op) {
                         
                        //Special case if operator is Addition
                        case '+':
                         
                        stack.pop(operand1);
                        stack.pop(operand2);
                         
                        total = operand2 + operand1;
                         
                        stack.push(total);
                         
                        break;
                         
                         
                        //Special case if operator is Subtraction
                        case '-':
                         
                        stack.pop(operand1);
                        stack.pop(operand2);
                         
                        total = operand2 - operand1;
                         
                        stack.push(total);
                         
                        break;
                         
                         
                        //Special case if operator is multiplication
                        case '*':
                         
                        stack.pop(operand1);
                        stack.pop(operand2);
                         
                        total = operand2 * operand1;
                         
                        stack.push(total);
                         
                        
                         
                        break;
                         
                         
                        //Special case if operator is division
                        case '/':
                         
                         
                        //Special case for division by 0
                        if (operand2 == 0) {
                             
                            error();
                             
                        }
                         
                        else {
                             
                            stack.pop(operand1);
                            stack.pop(operand2);
                             
                            total = operand2 / operand1;
                             
                            stack.push(total);
                             
                        }
                         
                        break;
                         
                         
                        //Special case if operator is power function
                        case '^':
                         
                        //Special case if denominator is 0
                        if (operand1 == 0) {
                             
                            total = 1;
                             
                            stack.push(total);
                             
                        }
                        
                        //Special case if denominator is set to the power of 0   
                        else if (operand2 == 0) {
                                 
                            total = 0;
                                 
                            stack.push(total);
                                 
                        }
                             
                         
                         
                        else {
                             
                            stack.pop(operand1);
                            stack.pop(operand2);
                             
                            total = pow(operand2, operand1);
                             
                            stack.push(total);
                             
                        }
                         
                        break;
                         
                         
                    }
                }
                 
                //Error statement if invalid post-fix expression in EOF while loop 
                else {
                    
                    error();
                     
                }
                 
    }
    
    //Loop that prints total only if one value left on stack
    if (stack.size() == 1) {
        
        cout << total << endl;
        
    }
    
    //Error statement if invalid post-fix expression in main function
    else 
        
        error();
        
    
    return 0;
    
}