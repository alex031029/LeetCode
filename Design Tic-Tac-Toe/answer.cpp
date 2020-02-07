class TicTacToe {
public:
    /** Initialize your data structure here. */
    // no need to store the board
    // vector<vector<int>> board;
    
    // these variables stores the sum of horizontal, vertical and diagonal elements
    vector<int> ifWinHorizontal;
    vector<int> ifWinVertical;
    vector<int> ifWinDiagonal;
    TicTacToe(int n) {
        // board = vector<vector<int>>(n, vector<int>(n, ' '));
        ifWinHorizontal = vector<int>(n, 0);
        ifWinVertical = vector<int>(n, 0);
        ifWinDiagonal = vector<int>(2, 0);
    }
    

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if(player == 2)
            player = -1;
        ifWinHorizontal[row] += player;
        ifWinVertical[col] += player;
        
        if(row == col)
            ifWinDiagonal[0] += player;
        
        // the other diagonal line 
        // note that the row + col = n - 1 here 
        if(row + col == ifWinHorizontal.size()-1)
            ifWinDiagonal[1] += player;

        int n = ifWinHorizontal.size()*player;
        if(ifWinHorizontal[row]==n||ifWinVertical[col]==n||ifWinDiagonal[0]==n||ifWinDiagonal[1]==n)
            return player == -1?2:1;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
