// a stack solution
// using a vector to simulate the stack
// this stack is strictly deceasing in terms of both tempature and index

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ret(T.size());
        if(T.empty())
            return ret;
        ret.back() = 0;
        
        // the stack
        vector<int> stk;
        stk.push_back(T.size()-1);
        for(int i=T.size()-2;i>=0;i--)
        {
            int temp = 0;
            
            // searching the stack to find the day hotter than T[i]
            // it can be optimizaed to binary search
            for(int j=stk.size()-1;j>=0;j--)
            {
                if(T[stk[j]]>T[i])
                {
                    temp = stk[j]-i;
                    break;
                }
            }
        
            ret[i]=temp;
            
            // update the stack
            // pop all days no hotter than T[i]
            while(!stk.empty()&&T[stk.back()]<=T[i])
            {
                stk.pop_back();
            }
            stk.push_back(i);
        }
        return ret;
    }
};
