// straightforward implementation

class Solution {
public:

    vector<vector<int>> generate(int numRows) {
        if(numRows==0)
            return {};
        vector<vector<int>> ret;
        ret.push_back(vector<int>{1});
        for(int i=2;i<=numRows;i++)
        {
            vector<int> temp(i);
            temp[0] = 1;
            temp.back() = 1;
            for(int j=1;j<temp.size()-1;j++)
            {
                temp[j] = ret[i-2][j-1]+ret[i-2][j];
            }
            ret.push_back(temp);
        }
        return ret;
    }
};
