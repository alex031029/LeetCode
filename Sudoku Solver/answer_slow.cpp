// a backtracking method
// it works slow sine the hash is not properly designed 

class Solution {
public:
    // a hash to store coordiate of given char
    vector<pair<int,int>> hash[128];
    // it returns all possible number inf (I,J) 
    vector<char> possibleNum(int I, int J)
    {
        vector<char> ret;
        for(int i='1';i<='9';i++)
        {
            int flag = true;
            for(int t=0;t<hash[i].size();t++)
            {
                bool sameSquare = (I/3==hash[i][t].first/3)&&(J/3==hash[i][t].second/3);
                if(hash[i][t].first==I||hash[i][t].second==J||sameSquare)
                {
                    flag = false;
                    break;
                }
            } 
            if(flag)
                ret.push_back(i);  
        }
        return ret;
    }
    
    // a dfs helper
    bool helper(vector<vector<char>>& board, int x, int y) {
       
        // find the first blanket from (i,j)
        while(board[x][y]!='.')
        {
            if (++y >= 9) {
                    x++;
                    y = 0;
                }
                if (x >= 9) {
                    return true;
                }
        }
        int i = x;
        int j = y;
        auto possibles = possibleNum(i, j);
        
        // backtracking all elements in possibles
        for(int t=0;t<possibles.size();t++)
        {
            board[i][j] = possibles[t];
            hash[possibles[t]].push_back(make_pair(i,j));
            if(!helper(board, x, y))
            {
                // for wrong answer we modify the hash and board
                board[i][j] = '.';
                hash[possibles[t]].pop_back();
            }
            else
            {
                return true;
            }
        }
        return false;
    }
    
    
    void solveSudoku(vector<vector<char>>& board) {
        
        // initialze the hash
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                hash[board[i][j]].push_back(make_pair(i, j));
            }
        }
        
        helper(board, 0, 0);
    }

};
