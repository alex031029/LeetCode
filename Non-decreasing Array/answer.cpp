// This problem is pretty trcicky, even though it is labelled as an easy one
// the trikcy part is that you may omit some special casees
// I list cases in ./cases.md for references

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size()<=2)
            return true;
        
        int previous = 0x80000000;
        int next = 0x7fffffff;
        int i=0;
        int j=nums.size()-1;
        for(;i<nums.size();i++)
        {
            if(nums[i]<previous)
            {
                cout<<i<<nums[i]<<previous<<endl;
                break;
            }
            previous = nums[i];
        }
        if(i == nums.size())
            return true;
        for(;j>=0;j--)
        {
            if(nums[j]>next)
            {
                cout<<j<<nums[j]<<next<<endl;
                break;
            }
            next = nums[j];
        }
            
        if(i!=j+1)
            return false;
        // if(j>0&&j<nums.size()-2&&nums[j-1]>nums[j+1])
        //     return false;
        else
        {
            if(j==0||j>nums.size()-2||i==0||i>nums.size()-2)
                return true;
            bool statement1 = j>0&&j<nums.size()-2&&nums[j-1]<nums[j+1];
            bool statement2 = i>0&&i<nums.size()-2&&nums[i-1]<nums[i+1];
            if(statement1||statement2)
                return true;
            else
                return false;
        }
    }
};
