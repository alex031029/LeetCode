// a naive O(n^2) solution
// it iteratively enumerates all possible combination of buying and selling dates
// and returns the maxmimum among all above combinations

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        
        int ret = 0;
        for(int i=0; i<prices.size()-1;i++)
        {
            for(int j=i+1;j<prices.size();j++)
            {
                int sum = -prices[i]+prices[j];
                if(sum>ret)
                    ret = sum;
            }
        }

        return ret;
    }
};
