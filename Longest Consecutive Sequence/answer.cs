// a C # implementation
// interpreted from c++ version


public class Solution {
    public int LongestConsecutive(int[] nums) {
    	// HashSet is similart to unordered_set in cpp
        HashSet<int> st = new HashSet<int>();
        foreach(int n in nums) 
            st.Add(n);

        int ans = 0;
        foreach(int i in st)
        {
            // 假如一个数在哈希表中存在比他小的，那么它不是可以作为开头的数字
            if(i != Int32.MinValue && st.Contains(i-1))
            {
                continue;
            }
            int cnt = 1;

	    // here we add another integer j is because i is the iterator of foreach loop
	    // and it cannot be modifed by other statement
            int j = i;
            while(j != Int32.MaxValue && st.Contains(j+1))
            {
                cnt ++;
                j++;
            }
            ans = Math.Max(ans, cnt);
        }
        return ans;
    }
}
