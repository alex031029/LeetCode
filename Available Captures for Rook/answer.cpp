// simulate the move of white rook
// this code is kinda wordy, can be futhure simplified

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int i=0,j=0;
        bool flag = false;
        for(;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                if(board[i][j]=='R')
                {
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }
        // cout<<i<<'\t'<<j<<endl;
        int ret = 0;
        for(int t=i;t>=0;t--)
        {
            if(board[t][j]=='.')
                continue;
            else if(board[t][j]=='B')
                break;
            else if(board[t][j]=='p')
            {
                ret++;
                break;
            }
        }
        for(int t=i;t<8;t++)
        {
            if(board[t][j]=='.')
                continue;
            else if(board[t][j]=='B')
                break;
            else if(board[t][j]=='p')
            {
                ret++;
                break;
            }
        }
        for(int t=j;t>=0;t--)
        {
            if(board[i][t]=='.')
                continue;
            else if(board[i][t]=='B')
                break;
            else if(board[i][t]=='p')
            {
                ret++;
                break;
            }
        }
        for(int t=j;t<8;t++)
        {
            if(board[i][t]=='.')
                continue;
            else if(board[i][t]=='B')
                break;
            else if(board[i][t]=='p')
            {
                ret++;
                break;
            }
        }
        return ret;
    }
};
