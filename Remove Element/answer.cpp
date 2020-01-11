class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // special case of nums.size()==0 or 1
        if(nums.empty())
            return 0;
        if(nums.size()==1)
        {
            return nums[0]==val?0:1;
        }
        // two pointers, traversing forward and backward respecitvely
        int f=0;
        int b=nums.size()-1;
        
        // a lambda function to move backward pointer
        auto moveBackPointer = [&]()->bool{
            while(b>f&&nums[b]==val)
            {
                b--;
            }
            return (b>f);
        };
        while(b>f)
        {
            // swap nums[f] if it is equal to val
            if(nums[f]==val)
            {
                if(!moveBackPointer())
                {
                    break;
                }
                nums[f]=nums[b];
                // cout<<f<<" "<<b<<endl;
                b--;
                // the continue statement assures each iteration move only one step (either b or f)
                continue;
            }
            f++;
        }
        // cout<<f<<" "<<b<<endl;
        
        // if nums[f]!= val, return f+1
        // otherwise returns f
        return f+(nums[f]!=val);
    }
};
