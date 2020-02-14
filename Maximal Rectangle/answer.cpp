// this solution uses answer.cpp of Largest Rectangle in Histogram 
// for each line, we contruct a histrogram, and find the largest rectangle


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) { 
        // add a 0 at the beginning and ending respectively of heights 
        // heights.insert(heights.begin(),0);
        // heights.push_back(0);

        int ret = 0;

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
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        
        vector<int> heights(matrix[0].size()+2, 0);
        int ret = 0;
        for(int i=0;i<matrix.size();i++)
        {
            // construct the histogram
            for(int j=0;j<matrix[0].size();j++)
            {
                heights[j+1] = matrix[i][j]=='0'?0:heights[j+1]+1;
            }
            int temp = largestRectangleArea(heights);
            if(temp>ret)
                ret = temp;
        }
        return ret;
    }
};
