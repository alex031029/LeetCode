// a backtracking method 
// it has a better designed hash


class Solution {
public:
    // row[i][num] is true if the i-th line has a number num
    bool row[9][9];
    bool col[9][9];
    bool square[9][9];
    
    // a dfs search helper
    bool helper(vector<vector<char>>& board, int i, int j) {
        
        // find the next blank
        while(board[i][j]!='.')
        {
            if (++j >= 9) {
                    i++;
                    j = 0;
                }
                if (i >= 9) {
                    return true;
                }
        }
        
        // check all possibles
        for(int num = 0;num<9;num++)
        { 
            int sqrIdx = (i/3)*3+j/3; 
            if(row[i][num]||col[j][num]||square[sqrIdx][num])
                continue;         
            
            // try each possible number
            char c = num+'1'; 
            board[i][j] = c;
            row[i][num] = true;
            col[j][num] = true;
            square[sqrIdx][num]= true;
            if(!helper(board, i, j))
            {
                // reset the board and hashes for wrong guess
                board[i][j] = '.';
                row[i][num] = false;
                col[j][num] = false;
                square[sqrIdx][num]= false;
            }
            else
            {
                return true;
            }    
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        // memset(row, 0, sizeof(bool)*81);
        // memset(col, 0, sizeof(bool)*81);
        // memset(square, 0, sizeof(bool)*81);

        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {                
                    int num = board[i][j]-'1';
                    row[i][num] = true;
                    col[j][num] = true;
                    int sqrIdx = (i/3)*3+j/3; 
                    square[sqrIdx][num]= true;
                }
            }
        }
        helper(board, 0, 0);
    }

};
