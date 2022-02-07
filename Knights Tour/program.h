//
//  program.h
//  Knights Tour
//
//  Created by OG Brown Skin on 2/6/22.
//

#ifndef program_h
#define program_h

#include <string.h>
#include <stdio.h>

// first function 
void startProgram()
{
    // variables that hold the mxn size chess board
    int m,n;
    
    // collects mxn
    std::cout << "Please enter dimensions for m x n size chess board\n";
    std::cin >> m;
    std::cin >> n;
    
    // creates mxn board
    int chessBoard[m][n];
    
    // initializes the chess board that will be used
    // for some reason there is an error here idky
    initializeBoard(chessBoard, m, n);
}

// will intialize board
void initializeBoard(int* board, int* x, int* y)
{
    /**
     main idea here:
     1. set board[0][0] = 0
     2. set every other point to -1
     the point of that is so when we are runnning our function to find the path
     we can test every value of the board. if it is > 0, then it hasn't been used and is availabe
     otherwise, it is going to have an integer value greater than 0
     the only point that will have 0 will be the first quadrant. When we are farther in this project,
     we can have the ending be where the only possible next move is 0 to create a closed
     knights tour.
     */
    
    // initialize starting point - issue here maybe i am being dumb
    *board[0][0] = 0;
    
    // will traverse through the whole array and set every value
    for(int i = 0; i < *x; i++)
    {
        for(int j = 0; j < *y; j++)
        {
            
        }
    }
}



#endif /* program_h */
