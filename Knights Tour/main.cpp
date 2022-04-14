// Alexander Wood, Taman Truong
// CSE 310 Honors Contract - Nakamura
// main.cpp
/**
 This is the main class. Nothing much is happening here. We introduce ourselves upon the start of the main.
 We then ask for user input to define the demensions of the mxn board, for which they
 wish to solve, then calls a helper function in the KnightsTour.h file to
 recursivley solve the problem.
 */

#include <iostream>
#include <iostream>
#include <string>

#include "KnightsTour.h"

int main(int argc, const char * argv[])
{
    // defining integers m,n for the size of the board
    int m,n;
    
    std::cout << "Welcome to the Knights Tour solution by Alexander Wood and Taman Truong\n" << "This program will produce an open Knights Tour Solution for a mxn size board" << std::endl;
    
    // grab dimensions
    std::cout << "Please enter size for m: " << std::endl;
    std::cin >> m;
    std::cin.ignore();
    
    std::cout << "Please enter size for n: " << std::endl;
    std::cin >> n;
    std::cin.ignore();
    
    // define board size
    KnightsTour * board1 = new KnightsTour(m, n);
    
    // solve tour
    board1->solveTour();
}
