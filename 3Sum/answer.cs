// interpreted from answer.cpp
// a C# version

public class Solution {
    public IList<IList<int>> ThreeSum(int[] nums) {
        IList<IList<int>> ret = new List<IList<int>>();
        
        if(nums.Length<3)
            return ret;
        
        Array.Sort(nums);
              
        for(int i=0;i<nums.Length-2;i++)
        {
            int j = i+1;
            int t = nums.Length-1;
            while(t>j)
            {
                int sum = nums[i]+nums[j]+nums[t];
                if(sum==0)
                {
                    ret.Add(new List<int>(){nums[i],nums[j],nums[t]});
                    // omit same values
                    while(j<t&&nums[j]==nums[j+1])
                        j++;
                    while(j<t&&nums[t]==nums[t-1])
                        t--;
                    j++;
                    t--;
                }
                else if(sum>0)
                    t--;
                else
                    j++;
            }
            // omit same values
            while(i<nums.Length-2&&nums[i]==nums[i+1])
                i++;
        }
        return ret;

    }
}
