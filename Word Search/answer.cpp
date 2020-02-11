// a backtracking algorithm, via recursive function

class Solution {
public:

    // offset is for word, to check which char is examined
    // flag is to make sure each word is used once 
    // x and y is for the coordinate of the input char
    bool helper(vector<vector<char>>& board, string& word, int offset, vector<vector<bool>>& flag, int x, int y)
    {
        
        if(x<0||x>=board.size()||y<0||y>=board[0].size()||!flag[x][y]||board[x][y]!=word[offset])
            return false;
        // cout<<x<<y<<board[x][y]<<offset<<endl;
        if(offset>=word.size()-1)
            return true;

        flag[x][y]=false;
        bool statement = helper(board, word, offset+1, flag, x+1, y)||
        helper(board, word, offset+1, flag, x-1, y)||
        helper(board, word, offset+1, flag, x, y+1)||
        helper(board, word, offset+1, flag, x, y-1);
        flag[x][y]=true;
        return statement;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty())
            return false;
        vector<vector<bool>> flag(board.size(),vector<bool>(board[0].size(),true));
        
        /// for each element in board that is equal to word[0], we call helper funciton
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0])
                {
                    if(helper(board, word, 0, flag, i, j))
                        return true;
                }
            }
        }
        return false;
    }
};
