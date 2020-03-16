// no much differencefrom Pascal's Triangle/answer.cpp

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0)
            return {1};
        vector<int> ret{1};
        for(int i=2;i<=rowIndex+1;i++)
        {
            vector<int> temp(i);
            temp[0] = 1;
            temp.back() = 1;
            for(int j=1;j<temp.size()-1;j++)
            {
                temp[j] = ret[j-1]+ret[j];
            }
            // use move to reduce copy overheads
            ret = move(temp);
        }
        return ret;
    }
};
