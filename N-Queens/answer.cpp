// a backtracking N queens solution


class Solution {
public:
    vector<vector<string>> ret;
    int n;
    // a vector storing coordinate of queens
    vector<pair<int,int>> queens;
    
    // the backtracking algorithm
    // offset is the value of allocated queens
    void helper(vector<string>& board, int offset)
    {
        auto printBoard = [&board]{
            for(int i=0;i<board.size();i++)
                cout<<board[i]<<endl;
            cout<<endl;
        };
        // check if board[i][j] is an available postion given all elements in queens
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
            ret.push_back(board);
            return;
        }
        bool flag = false;
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
    vector<vector<string>> solveNQueens(int n) {
        if(n==0)
            return {};
        this->n = n;
        
        for(int i=0;i<n;i++)
        {
            // set the first queen
            queens.push_back(make_pair(0,i));
            // initialize the board
            vector<string> board(n, string(n,'.'));
            board[0][i] = 'Q';
            helper(board, 1);
            queens.clear();
        }
        return ret;
    }
};
