// same as N-Queens/answer.cpp, it is a backtracking algorithm
// the only difference is the returned value type

class Solution {
public:
    int ret;
    int n;
    // an array of found queens
    vector<pair<int,int>> queens;
    
    // backtracking main code
    void helper(vector<string>& board, int offset)
    {
        auto printBoard = [&board]{
            for(int i=0;i<board.size();i++)
                cout<<board[i]<<endl;
            cout<<endl;
        };
        
        // return true if board[i][j] is available
        auto isOkay = [&board,this](int i, int j)->bool
        {
            for(int x = 0;x<queens.size();x++)
            {
                if(queens[x].first == i||queens[x].second == j)
                    return false;
                if(queens[x].first-queens[x].second == i-j)
                    return false;
                if(queens[x].first+queens[x].second == i+j)
                    return false;
            }
            return true;
        };
        // cout<<offset<<endl;
        // printBoard();
        if(offset==n)
        {
            ret++;
            return;
        }
        int i = offset;
        for(int j=0;j<n;j++)
        {
            // cout<<j<<endl;
            if(isOkay(i,j))
            {
                queens.emplace_back(i,j);
                board[i][j] = 'Q';
                helper(board, offset+1);
                board[i][j] = '.';
                queens.pop_back();
            }
        }
        return;
    }
    int totalNQueens(int n) {
        if(n<=1)
            return n;
        this->n = n;
        
        for(int i=0;i<n;i++)
        {
            queens.emplace_back(0,i);
            vector<string> board(n, string(n,'.'));
            board[0][i] = 'Q';
            helper(board, 1);
            queens.clear();
        }
        return ret;
    }
};
