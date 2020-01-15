// interview question from Wurong
// the method below is O(n) time and O(1) space complexity
// there are several other method that are pretty interesting, especiall the one using stack

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<=2)
            return 0;
        
        // two pointers traverse the array from two directions
        int left = 0;
        int right = height.size()-1;

        int left_max = height[0];
        int right_max = height[height.size()-1];

        int ret = 0;
        while(right>left)
        {
            // cout<<left<<" "<<right<<" ";
            // without a loss of generality, assume height[less] < height[right]
            // position left is considered of traping the amount of water as the min(leftmost[left], rightmost[left])-height[left]
            // where leftmost[left] is the highest block from 0...left-1
            // we assures that leftmost[left] == leftmost 
            // and we assures that height[right]>height[less]
            // thus, we can simply use height[right] as the rightmost[left]
            if(height[left] < height[right])
            {
                // cout<<"left"<<endl;
                if(left_max>height[left])
                     ret += left_max-height[left];
                else
                    left_max = height[left];
                left++;
            }
            else
            {
                / cout<<"right"<<endl;
                if(right_max > height[right])
                    ret += right_max - height[right];
                else
                    right_max = height[right];
                right--;
            }
            // cout<<ret<<endl;
        }
        return ret;
    }
    
};
