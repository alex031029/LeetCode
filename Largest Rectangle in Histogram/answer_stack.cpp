// similar to dp solutin
// this one use a stack
// the basic idea is also to find the indices j and t, where j<i, t>i, heights[j]<heigts[i] and heights[t]<heigts[i]

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty())
            return 0;
        
        // add a 0 at the beginning and ending respectively of heights 
        heights.insert(heights.begin(),0);
        heights.push_back(0);

        int ret = 0;
        
        
        // the stack workds as followings
        // if heigts[i] is no less than stk.top(), we just push it in the stack
        // otherwise, we have find j and t (which is i) for the stk.top()
        
        stack<int> stk;
        for(int i=0;i<heights.size();i++)
        {
            if(stk.empty()||heights[stk.top()]<=heights[i])
                stk.push(i);
            else
            {
                while(heights[stk.top()]>heights[i])
                {
                    int prev = stk.top();
                    stk.pop();
                    int temp = (i-stk.top()-1)*heights[prev];
                    if(ret<temp)
                        ret = temp;
                }
                stk.push(i);
            }
        }
        
        return ret;
        
    }
};
