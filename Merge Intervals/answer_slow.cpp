class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto comparator = [](vector<int> a, vector<int> b)->bool{
            return a[0]<b[0];
        };

        if(intervals.size()<=1)
            return intervals;

        sort(intervals.begin(), intervals.end(),comparator);
        vector<vector<int>> ret;
        auto prev = intervals[0];
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]>prev[1])
            {
                ret.push_back(prev);
                prev = intervals[i];
            }
            else
            {
                prev[1] = max(prev[1], intervals[i][1]);
            }
        }
        ret.push_back(prev);
        return ret;
    }
};
