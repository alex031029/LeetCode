// a divide and conquer method
// the averag time complexity is O(n log n)
// but it is degraded to O(n^2) for increasing/decreasing order (no need for strictness)
// thus, this solution cannot pass LeetCode when running an edge case where all heights are indentical

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
        
        int minIndex = findMin();
        
        int result1 = helper(heights, left, minIndex-1);
        int result2 = helper(heights, minIndex+1, right);
        int result3 = heights[minIndex]*(right-left+1);
        // cout<<left<<"\t"<<right<<"\t"<<minIndex<<endl;
        // cout<<left<<"\t"<<right<<"\t"<<result1<<"\t"<<result2<<"\t"<<result3<<endl;
        return max(result3,max(result1,result2));

    }
    int largestRectangleArea(vector<int>& heights) {
        return helper(heights, 0, heights.size()-1);
    }
};
