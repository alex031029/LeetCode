// reuse Word Search/answer.cpp
// it can be improved by using Trie 

class Solution {
public:
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
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ret;
        for(int i=words.size()-1;i>=0;i--)
        {
            if(exist(board, words[i]))
            {
                ret.push_back(words[i]);
            }
        }
        return ret;
    }
};
