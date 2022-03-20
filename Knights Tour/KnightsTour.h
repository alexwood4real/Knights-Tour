#include <vector>

class KnightsTour
{
private:
    int totalMoves;
    std::vector<std::vector<int>> board;
public:
    KnightsTour(int, int);
    ~KnightsTour(); // will be defined later
    void printBoard();
    bool isValid(int, int, int);
    bool solveTourBacktracking(int, int, int, std::vector<std::vector<int>>::size_type, std::vector<std::vector<int>>::size_type, std::vector<int>, std::vector<int>);
    void solveTour();
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

// prints board at end
void KnightsTour::printBoard()
{
    // grabs dimensions of board - may have mixed them up
    std::vector<std::vector<int>>::size_type xSize = board.size();
    std::vector<std::vector<int>>::size_type ySize = board[0].size();
    
    for(int i = 0; i < xSize; i++)
    {
        for(int j = 0; j < ySize; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
}

// checks if a move is in bounds and is not the final move
bool KnightsTour::isValid(<#int#> x, <#int#> y, <#int#> moveNum)
{
    // grabs dimensions of board - may have mixed them up
    std::vector<std::vector<int>>::size_type xSize = board.size();
    std::vector<std::vector<int>>::size_type ySize = board[0].size();
    
    // check bounds
    if(( (0 <= x && x < xSize) && (0 <= y && y < ySize) ) && (moveNum <= totalMoves))
    {
        // in bounds and is in count limit
        // check if the sqaure has been visited
        if(board[x][y] > 0)
        {
            // has been visited
            return false;
        }
        else
        {
            // either the beginning or has not been visited
            return true;
        }
    }
    
    // move not valid
    return false;
}

// recursive call for backtracking
bool KnightsTour::solveTourBacktracking(int startX, int startY, int moveNum, std::vector<std::vector<int>>::size_type xSize, std::vector<std::vector<int>>::size_type ySize, std::vector<int> xMoves, std::vector<int> yMoves)
{
    if(moveNum == totalMoves)
    {
        // we are done
        return true;
    }
    else // recursion
    {
        // will hold if a move is safe and if the next move is safe
        bool isSafe, nextTrue;
        
        // iterate through the eight x,y moves
        for(int i = 0; i < 8; i++)
        {
            // checks if a move is safe
            isSafe = isValid(startX + xMoves[i], startY + yMoves[i], moveNum);
            if(isSafe == true)
            {
                // updates move
                board[startX + xMoves[i]][startY + yMoves[i]] = moveNum;
                
                // check if the next move is true
                // recursion
                nextTrue = solveTourBacktracking(startX + xMoves[i], startY + yMoves[i], moveNum++, xSize, ySize, xMoves, yMoves);
                if(nextTrue == true)
                {
                    return true;
                }
                else
                {
                    // back tracking
                    board[startX + xMoves[i]][startY + yMoves[i]] = -1;
                }
            }
        }
    }
    return 0;
}

// driver function
void KnightsTour::solveTour()
{
    // define all the ways a knight can move on a board
    std::vector<int> xMoves = {1, -1, 2, 2, -2, -2, 1, -1};
    std::vector<int> yMoves = {2, 2, 1, -1, 1, -1, -2, -2};
    
    // grabs dimensions of board - may have mixed them up
    std::vector<std::vector<int>>::size_type xSize = board.size();
    std::vector<std::vector<int>>::size_type ySize = board[0].size();
    
    /**
     will hold the result if solved or not
     we are starting at (0,0)
     we are making the first move
     passing the size of the array
     will test all the possible moves
     */
    bool isSolved = solveTourBacktracking(0, 0, 1, xSize, ySize, xMoves, yMoves);
    
    // spits the result of backtracking
    if(isSolved == true)
    {
        std::cout << "The Solution exists!" << std::endl;
        printBoard();
    }
    else
    {
        std::cout << "This size of board does not have a solution." << std::endl;
    }
}
