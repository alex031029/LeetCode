// O(n^2) solution
// Brute and Force

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.empty())
            return -1;
        for(int i=0;i<gas.size();i++)
        {
            int sum=0;
            for(int j=0;j<gas.size();j++)
            {
                int x = (i+j)%gas.size();
                sum = sum + gas[x] - cost[x];
                if(sum<0)
                    break;
            }
            if(sum>=0)
                return i;
        }
        return -1;
    }
};
