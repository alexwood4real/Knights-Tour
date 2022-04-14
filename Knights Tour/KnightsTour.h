// Alexander Wood, Taman Truong
// CSE 310 Honors Contract - Nakamura
// KnightsTour.h
/**
 In this header file, we have defined our KnightsTour class which has the private variables m, n, totalMoves,
 and board. This variables hold the length of the board, width of the board, the total number of
 possible moves that can be made, and the 2D matrix that represents our board.
 We also define two size 8 matrixes that represent all the ways a knight can move. We use these two
 arrays several times in the code to check the validity of moves.
 
 We then have the public functions: constructor, isSafe, printBoard, solveTourRecursive, solveTour.
 I wll describe the logic behind each function.
 
 Constructor: KnightsTour(int, int)
 First, this method takes in two integers and defines an mxn board from them.
 It then uses these two numbers to define the total number of moves that can be made.
 We then declare the size of the rows (m). We then enter a for-loop that creates
 a new array for every index of the array, thus making the size of the columns (n).
 We then enter a nested for-loop (mn) to set the value of each posiiton to the smallest
 integer value as possible. This is supposed to represent negative infinity. 
 */

#include <iostream>
#include <iostream>
#include <string>

class KnightsTour
{
private:
    int m, n, totalMoves;
    int ** board;
public:
    KnightsTour(int, int);
    bool isSafe(int, int);
    void printBoard();
    bool solveTourRecursive(int, int, int);
    void solveTour();
    
};

// define possible x and y moves
int xMoves[] = {1, 2, -2, -1, -1, 1, -2, 2};
int yMoves[] = {-2, -1, -1, 2, -2, 2, 1, 1};

// constructor
KnightsTour::KnightsTour(int l, int w)
{
    // defines m, n, and the total number of moves
    this->m = l;
    this->n = w;
    this->totalMoves = l * w;
    
    // create mxn board
    board = new int*[this->m];
    for(int i = 0; i < this->m; i++)
    {
        board[i] = new int[this->n];
    }
    
    // set every spot to negative infinity
    for(int i = 0; i < this->m; i++)
    {
        for(int j = 0; j < this->n; j++)
        {
            board[i][j] = INT_MIN;
        }
    }
    
}

// checks whether a given piece is good or not
bool KnightsTour::isSafe(int x, int y)
{
    // checks if the move is in bounds or not
    if(((x >=0) && (x < this->m)) && ((y >=0) && (y < this->m)))
    {
        // in bounds
        return true;
    }
    // not in bounds
    return false;
}

// print board
void KnightsTour::printBoard()
{
    for(int i = 0; i < this->m; i++)
    {
        for(int j = 0; j < this->n; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// the recursive call made to solve the tour
bool KnightsTour::solveTourRecursive(int moveCount, int x, int y)
{
    // will hold the moves being tested
    int nextX, nextY;
    
    // base case
    if(moveCount == this->totalMoves)
    {
        // solution found
        return true;
    }
    
    // else, solve recursivley by iterating through moves
    for(int i = 0; i < 8; i++)
    {
        // set next moves
        nextX = x + xMoves[i];
        nextY = y + yMoves[i];
        
        // check if move is in bounds AND is negative infinity
        if((isSafe(nextX, nextY) == true) && (board[nextX][nextY] == INT_MIN))
        {
            // move is valid, so make that edge
            board[nextX][nextY] = moveCount;
            moveCount++;
            
            // recursive step - solve next step
            if(solveTourRecursive(moveCount, nextX, nextY))
            {
                return true;
            }
            
            // else, if move is not valid for the future, back track
            board[nextX][nextY] = INT_MIN;
            moveCount--;
        }
    }
    
    // no solution
    return 0;
}

// solve tour - called from main
void KnightsTour::solveTour()
{
    // start at (0, 0)
    board[0][0] = 0;
    
    // call recursive solution
    if(solveTourRecursive(1, 0, 0) == true)
    {
        // if solution found, prints the board with move numbers
        printBoard();
    }
    else
    {
        std::cout << "Something went wrong here..." << std::endl;
    }
    
}
