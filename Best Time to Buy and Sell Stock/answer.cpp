// O(n) solution with O(1) space consumption


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        
        int ret = 0;
        
        // leftMin means the smallest value in the interval [0,i-1]
        int leftMin = prices[0];
        for(int i=1;i<prices.size();i++)
        {
            ret = max(ret, prices[i]-leftMin);
            leftMin = min(prices[i], leftMin);
        }
        return ret;
    }
};
