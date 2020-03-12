// Two arrays, greedy algorithm

class Solution {
public:
    int candy(vector<int>& ratings) {
        // record from left to right
        vector<int> left(ratings.size(),1);
        // record from right to left
        vector<int> right(ratings.size(),1);
        
        // greedy 
        for(int i=1;i<left.size();i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                left[i] = left[i-1]+1;
            }
        }
        for(int i=right.size()-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
            {
                right[i] = right[i+1]+1;
            }
        }

        int ret=0;
        for(int i=0;i<left.size();i++)
        {
            // cout<<max(left[i],right[i])<<endl;
            ret+=max(left[i],right[i]);
        }
        return ret;
    }   
};
