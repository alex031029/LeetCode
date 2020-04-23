// a C# implementation of answer.py
// basically a bucket method


public class Solution {
    public bool ContainsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        if(t < 0)
            return false;
            
        // equivalent of unsorted_map in c++
        Dictionary<long,long> bucket = new Dictionary<long,long>();
        
        // long w is to prevent overflow of 0x7ffffff+1
        long w = t+1;
        
        for(int i=0;i<nums.Length;i++)
        {
            // prevent from overflow
            long num = nums[i];
            
            // the index of bucket
            long m = num/w;
            
            // abs condition here is to prevent a minus value 
            if(bucket.ContainsKey(m)&&Math.Abs(num - nums[bucket[m]]) <= t)
                return true;
            if(bucket.ContainsKey(m-1)&&Math.Abs(num - nums[bucket[m-1]]) <= t)
                return true;
            if(bucket.ContainsKey(m+1)&&Math.Abs(num - nums[bucket[m+1]]) <= t)
                return true;
            bucket[m] = i;
            if(i>=k)
            {
                bucket.Remove(nums[i-k]/w);
            }
                
        }
        return false;
    }
}
