// an optimized divide and conquer solution

class Solution {
public:
    int helper(vector<int>& heights, int left, int right)
    {
        auto findMin = [&heights, &left, &right]()->int{
            int ret = left;
            for(int i=left+1;i<=right;i++)
            {
                if(heights[i]<heights[ret])
                    ret = i;
            }
            return ret;
        };
        if(left>right)
            return 0;
        if(left==right)
            return heights[left];
        
        // the optimization is here 
        // instead of finding [left, minIndex-1]
        // we find the leftIndex, where heights[leftIndex] is larger than heights[minIndex]
        // although this optimization cannot handle strictly increasing/decreasing input
        // for input with a large numberof indentical numbers, the code can terminate earlier
        
        int minIndex = findMin();
        int leftIndex = minIndex-1;
        int rightIndex = minIndex+1;
        while(leftIndex>=left&&heights[leftIndex]==heights[minIndex])
            leftIndex--;
        while(rightIndex<=right&&heights[rightIndex]==heights[minIndex])
            rightIndex++;

        int result1 = helper(heights, left, leftIndex);
        int result2 = helper(heights, rightIndex, right);
        int result3 = heights[minIndex]*(right-left+1);
        // cout<<left<<"\t"<<right<<"\t"<<minIndex<<endl;
        // cout<<left<<"\t"<<right<<"\t"<<result1<<"\t"<<result2<<"\t"<<result3<<endl;
        return max(result3,max(result1,result2));

    }
    int largestRectangleArea(vector<int>& heights) {
        return helper(heights, 0, heights.size()-1);
    }
};
