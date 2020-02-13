// a dp solution
// an array leftMin[i] is record the largest index from 0 to i-1 whose heights is smaller than heigts[i]

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        // heights.insert(heights.begin(),0);
        // heights.push_back(0);
        if(heights.empty())
            return 0;
        int leftMin[heights.size()];
        int rightMin[heights.size()];
        leftMin[0] = -1;
        rightMin[heights.size()-1] = heights.size();

        // we iteratively find the value for leftMin[i]
        for(int i=1;i<heights.size();i++)
        {
            int temp = i-1;
            while(temp>=0&&heights[temp]>=heights[i])
                temp = leftMin[temp];
            leftMin[i] = temp;
        }   
        for(int i=heights.size()-2;i>=0;i--)
        {
            int temp = i+1;
            while(temp<heights.size()&&heights[temp]>=heights[i])
                temp = rightMin[temp];
            rightMin[i] = temp;
        }

        // traverse the heights to find the max value
        int ret = 0;
        for(int i=0;i<heights.size();i++)
        {
            int left = leftMin[i];
            int right = rightMin[i];
            int temp = heights[i]*(right-left-1);
            if(temp>ret)
                ret = temp;
        }
        return ret;
        
    }
};
