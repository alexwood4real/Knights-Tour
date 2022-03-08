#include <vector>

/**
 Right now I am defining the class in general
 I will make the functions as we go, right now I will create the constructor and will define
 the destuctor at the end probably.
 
 Some things I will include tho will be a dictionary which I figured out how to do for the moves
 
 Future methods we will need (on going list):
 - check if a move is legal
 - recursive function that will fill up the board
 - printing the table
 */

class KnightsTour
{
private:
    int totalMoves;
    std::vector<std::vector<int>> board;
public:
    KnightsTour(int, int);
    ~KnightsTour(); // will be defined later
    // functions will be added as we go
};

KnightsTour::KnightsTour(int m, int n)
{
    // initializes every position to -1
    // logic is if the position # > 0 then the move has been made
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            board[i][j] = -1;
        }
    }
    
    // will start in the first index (0,0)
    board[0][0] = 0;
}
