// a C# solution
// interpreted from answer_short.cpp


public class Solution {
    
    // a helper method to use a list as input
    public IList<IList<int>> Helper(List<int> nums) {
    
        // new List<List<int>> is not a proper initialization, 
        // since the compiler cannot convert a List<List<int>> into IList<IList<int>> 
    
        IList<IList<int>> ret = new List<IList<int>>();
        if(nums.Count()==1)
        {
            ret.Add(new List<int>(){nums[0]});
            return ret;
        }

        for(int i=0;i<nums.Count();i++)
        {
            // List<int> nums2 = nums it not a proper initialization
            // if you initialize nums2 as the statement above, nums2 simply refers to nums
            // what we wish is a shallow (or deep) copy of nums
            // thus, we have to use a new statement 
            
            List<int> nums2 = new List<int>(nums);
            nums2.RemoveAt(i);
            var result = Helper(nums2);
            for(int j=0;j<result.Count();j++)
            {
                List<int> temp = new List<int>();
                temp.Add(nums[i]); 
                temp.AddRange(result[j]);
                ret.Add(temp);
            } 
        }
        return ret;        
    }
    public IList<IList<int>> Permute(int[] nums) {
        return Helper(new List<int>(nums));        
    }
}
