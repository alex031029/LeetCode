// a backtracking search
// it is not fast since it does not trim some branches

class Solution {
public:
    vector<vector<int>> ret;
    // the returned boolean value is actually not needed 
    bool helper(vector<int>& candidates, int target, int offset, vector<int>& path)
    {
        if(target==0)
        {
            ret.push_back(path);
            return true;
        }
        if(target<0)
            return false;
        bool flag = false;
        for(int i=offset;i<candidates.size();i++)
        {
            path.push_back(candidates[i]);
            // begin from i-th element, in order to eliminates identical answers in ret
            if(helper(candidates, target-candidates[i], i, path))
            {
                flag = true;
            }
            // no matter the returned value is true or false, we need to pop_back()
            // else
            path.pop_back();
        }
        return flag;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        helper(candidates, target, 0, path);
        return ret;
    }
};
