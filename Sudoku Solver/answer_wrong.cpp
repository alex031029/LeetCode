// a wrong solution
// although I knew it was wrong before submission
// it can only solve easy sudoku problems

class Solution {
public:

    vector<pair<int,int>> hash[128];
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
    void solveSudoku(vector<vector<char>>& board) {

        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                hash[board[i][j]].push_back(make_pair(i, j));
            }
        }
        // cout<<hash['9'][0].first<<hash['9'][0].second<<endl;
        int hashIdx =0;
        while(!hash['.'].empty())
        {        
            int i = hash['.'][hashIdx].first;
            int j = hash['.'][hashIdx].second;
            auto possibles = possibleNum(i, j);
            // cout<<i<<possibles.size()<<endl;
            if(possibles.size()!=1)
            {
                hashIdx=(hashIdx+1)%hash['.'].size();
            }
            else
            {
                board[i][j] = possibles[0];
                hash[possibles[0]].push_back(make_pair(i,j));
                hash['.'].erase(hash['.'].begin()+hashIdx);
            }
        }
    }
};
