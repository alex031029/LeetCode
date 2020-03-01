// O(n) solution
// similar to naive implementation
// but it has optimization

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
                {
                    // THE VITAL PART
                    // i will assigned as x 
                    // it is because all numbers in range [i,x] cannot be the answer
                    i=max(x,i);
                    break;
                }
            }
            if(sum>=0)
                return i;
        }
        return -1;
    }
};
