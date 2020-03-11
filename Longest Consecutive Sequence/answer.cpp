// a hash solution
// using unorder_set as a hash function

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int n: nums) st.insert(n);
        int ans = 0;
        for(auto iter = st.begin();iter!=st.end();iter++)
        {
            int i = *iter;
            // 假如一个数在哈希表中存在比他小的，那么它不是可以作为开头的数字
            // count can be used as find
            if(i != INT_MIN && st.count(i-1)){
                continue;
            }
            int cnt = 1;
            while(i!=INT_MAX && st.count(i+1)){
                cnt ++;
                i++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
