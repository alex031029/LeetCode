// a c# implementation interpreted from answer_dp.cpp

public class Solution {
    public int LargestRectangleArea(int[] heights) {

        // heights.insert(heights.begin(),0);
        // heights.push_back(0);
        if(heights.Length == 0)
            return 0;
        int[] leftMin = new int[heights.Length];
        int[] rightMin = new int[heights.Length];
        leftMin[0] = -1;
        rightMin[heights.Length-1] = heights.Length;

        // we iteratively find the value for leftMin[i]
        for(int i=1;i<heights.Length;i++)
        {
            int temp = i-1;
            while(temp>=0&&heights[temp]>=heights[i])
                temp = leftMin[temp];
            leftMin[i] = temp;
        }   
        for(int i=heights.Length-2;i>=0;i--)
        {
            int temp = i+1;
            while(temp<heights.Length&&heights[temp]>=heights[i])
                temp = rightMin[temp];
            rightMin[i] = temp;
        }

        // traverse the heights to find the max value
        int ret = 0;
        for(int i=0;i<heights.Length;i++)
        {
            int left = leftMin[i];
            int right = rightMin[i];
            int temp = heights[i]*(right-left-1);
            if(temp>ret)
                ret = temp;
        }
        return ret;
        
    }
}
