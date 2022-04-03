// defined headers
#include "LinkedList.h"
#include "Queue.h"


class KnightsTour
{
private:
    int totalMoves;
    LinkedList ** board[];
public:
    KnightsTour(int, int);
};

KnightsTour::KnightsTour(int m, int n)
{
    // defines the total number of moves
    this->totalMoves = m * n;
    
    // define mxn board of linked lists
    // board = new LinkedList*[totalMoves];
    
    //initialize linked lists
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            // board[m][n] = new LinkedList();
        }
    }
}

