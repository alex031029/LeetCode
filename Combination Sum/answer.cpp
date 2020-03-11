// an improved backtracking method

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
        for(int i=offset;i<candidates.size()&&candidates[i]<=target;i++)
        {
            path.push_back(candidates[i]);
            helper(candidates, target-candidates[i], i, path);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // sort candidates for trimming branches
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        helper(candidates, target, 0, path);
        return ret;
    }
};
