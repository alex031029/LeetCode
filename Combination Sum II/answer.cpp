// basically same as Combination Sum/answer.cpp


class Solution {
public:
    vector<vector<int>> ret;
    // we do no need the return value, thus we set helper as void function
    void helper(vector<int>& candidates, int target, int offset, vector<int>& path)
    {
        if(target==0)
        {
            ret.push_back(path);
            return;
        }
        if(target<0)
            return;
        // after sorting, we can early terminates the loop when the condition meets
        for(int i=offset;i<candidates.size()&&candidates[i]<=target;)
        {
            path.push_back(candidates[i]);
            // unlike Combination Sum/answer.cpp, we find the next element from i+1-th position
            helper(candidates, target-candidates[i], i+1, path);
            path.pop_back();
            
            // we omit same elements as candidates[i] in order to eliminates redundancy.
            while(i+1<candidates.size()&&candidates[i+1]==candidates[i])
                i++;
            i++;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // sort candidates for trimming branches
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        helper(candidates, target, 0, path);
        return ret;
    }
};
