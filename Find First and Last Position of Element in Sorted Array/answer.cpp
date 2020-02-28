// O(log n) time 
// binary search for three times

class Solution {
public:
    // find the index that nums[i]==target
    int helper(vector<int>& nums, int left, int right, int target)
    {
        if(left>right)
            return -1;
        if(left==right)
            return nums[left]==target?left:-1;
        int mid = (left+right)/2;
        if(nums[mid]>target)
            return helper(nums, left, mid-1, target);
        else if(nums[mid]<target)
            return helper(nums, mid+1, right, target);
        else  
            return mid;

    }
    // find the index of the largest element before target
    int helperLeft(vector<int>& nums, int left, int right, int target)
    {
        // cout<<left<<"\t"<<right<<endl;
        
        // NOTE THAT the termination condition and return value
        if(left==right||left+1==right)
            return nums[right]==target?left:right;
        int mid = (left+right)/2;
        // cout<<left<<"\t"<<right<<"\t"<<mid<<endl;
        if(nums[mid]<target)
            return helperLeft(nums, mid, right, target);
        else
            return helperLeft(nums, left, mid-1, target);      
    }
    // find the index of smallest element after target
    int helperRight(vector<int>& nums, int left, int right, int target)
    {
        // cout<<left<<"\t"<<right<<endl;
        if(left==right||left+1==right)
            return nums[left]==target?right:left;
        int mid = (left+right)/2;
        // cout<<left<<"\t"<<right<<"\t"<<mid<<endl;
        if(nums[mid]>target)
            return helperRight(nums, left, mid, target);
        else
            return helperRight(nums, mid+1, right, target);      
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()||nums[0]>target||nums.back()<target)
            return vector<int>{-1,-1};
        if(nums[0]==target&&nums.back()==target)
            return vector<int>{0,int(nums.size()-1)};
        vector<int> ret;
        
        // find the pivot where nums[pivot]==target
        int pivot = helper(nums,0,nums.size()-1,target);
        // cout<<pivot<<endl;
        if(pivot==-1)
            return vector<int>{-1,-1};
            
        int left = helperLeft(nums, 0, pivot, target);
        // cout<<left<<endl
        
        int right = helperRight(nums, pivot, nums.size()-1, target);
        // cout<<right<<endl;
        
        // eliminate special cases where nums[0]==target
        if(nums[left]!=target)
            left+=1;
            
        // eliminate special cases where nums.back()==target
        if(nums[right]!=target)
            right-=1;
        
        ret.push_back(left);
        ret.push_back(right);
        return ret;
    }
};
