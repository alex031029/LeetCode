// three hashes for row, column and square verification

class Solution {
public:
    // 9 rows for 9 possible numbers
    bool row[9][9];
    bool col[9][9];
    bool square[9][9];

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {                
                    int num = board[i][j]-'1';
                    int sqrIdx = (i/3)*3+j/3; 
                    // if this row/column/square has this number,
                    // return false
                    if(row[i][num]||col[j][num]||square[sqrIdx][num])
                        return false;
                    row[i][num] = true;
                    col[j][num] = true;
                    square[sqrIdx][num]= true;
                }
            }
        }
        return true;
    }
};
