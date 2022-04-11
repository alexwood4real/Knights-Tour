// Alexander Wood, Taman Truong
// CSE 310 Honors Contract - Nakamura
// KnightsTour.h


// defined headers
#include "LinkedList.h"
#include "Queue.h"


class KnightsTour
{
private:
    int m, n, totalMoves;
    LinkedList ** board;
public:
    KnightsTour(int, int);
    bool isSafe(int, int);
    void createGraph();
    
};

// constructor
KnightsTour::KnightsTour(int l, int w)
{
    // defines m, n, and the total number of moves
    this->m = l;
    this->n = w;
    this->totalMoves = l * w;
    
    // define m-length board of linked lists
    board = new LinkedList*[this->m];
    
    // creates n-width board of linked lists
    for(int i = 0; i < m; i++)
    {
        board[i] = new LinkedList[this->n];
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

void KnightsTour::createGraph()
{
    // define possible x and y moves
    int xMoves[] = {1, 1, -1, -1, 2, 2, -2, -2};
    int yMoves[] = {2, -2, 2, -2, 1, -1, 1, -1};
    
    // fill out adjacency list (board)
    for(int i = 0; i < this->m; i++)
    {
        for(int j = 0; j < this->n; j++)
        {
            for(int k = 0; k < 8; k++)
            {
                // declare the move to be tested
                int newX = i + xMoves[k];
                int newY = j + yMoves[k];
                
                // check if it is valid
                if(isSafe(newX, newY))
                {
                    // in the board 
                }
            }
        }
    }
}

