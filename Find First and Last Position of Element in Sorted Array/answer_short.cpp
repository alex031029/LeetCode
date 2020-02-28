// a short version of answer.cpp

class Solution {
public:
    // find the smallest index whose value in nums is target
    int helperLeft(vector<int>& nums, int left, int right, int target)
    {
        // cout<<left<<"\t"<<right<<endl;

        if(left==right||left+1==right)
        {
            if(nums[left]==target)
                return left;
            else if(nums[right]==target)
                return right;
            else 
                return -1;
        }
        int mid = (left+right)/2;
        // cout<<left<<"\t"<<right<<"\t"<<mid<<endl;
        if(nums[mid]<target)
            return helperLeft(nums, mid+1, right, target);
        else if(nums[mid]>target)
            return helperLeft(nums, left, mid-1, target);
        else 
            return helperLeft(nums, left, mid, target);
    }
    // find the larget index whose value in nums is target
    int helperRight(vector<int>& nums, int left, int right, int target)
    {
        // cout<<left<<"\t"<<right<<endl;
        if(left==right||left+1==right)
        {
            if(nums[right]==target)
                return right;
            else if(nums[left]==target)
                return left;
            else 
                return -1;
        }
        int mid = (left+right)/2;
        // cout<<left<<"\t"<<right<<"\t"<<mid<<endl;
        if(nums[mid]>target)
            return helperRight(nums, left, mid-1, target);
        else if(nums[mid]<target)
            return helperRight(nums, mid+1, right, target);  
        else 
            return helperRight(nums, mid, right, target);    
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()||nums[0]>target||nums.back()<target)
            return vector<int>{-1,-1};
        if(nums[0]==target&&nums.back()==target)
            return vector<int>{0,int(nums.size()-1)};
        vector<int> ret;
        
        // find the left index
        int left = helperLeft(nums, 0, nums.size()-1, target);
        // cout<<left<<endl;
        
        // find the right index
        int right = helperRight(nums, 0, nums.size()-1, target);
        // cout<<right<<endl;
        ret.push_back(left);
        ret.push_back(right);
        return ret;
    }
};
