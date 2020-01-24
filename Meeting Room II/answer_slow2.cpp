// another O(n log n) time answer
// but the worst case of this answer is also O(n log n)
// I use priority queue instead of an array 

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.empty())
            return 0;
            
        auto comparator = [](vector<int> x, vector<int>y)->bool{
            return x[0] < y[0];
        };
        sort(intervals.begin(),intervals.end(),comparator);

        int ret = 1;
        
        auto printIntervals = [&](){
            for(int i =0;i<intervals.size();i++)
            {
                cout<<intervals[i][0]<<", "<<intervals[i][1]<<endl;
            }
        };

        // printIntervals();

        priority_queue<int, vector<int>, greater<int>> record;
        record.push(intervals[0][1]);

        auto updateRecord = [&](vector<int> room){
            if(record.top()<=room[0])
            {
                record.pop();
                record.push(room[1]);
            }
            else
            {
                ret++;
                record.push(room[1]);
            }
        };

        for(int i = 1; i<intervals.size();i++)
        {
             updateRecord(intervals[i]);
        }

        return ret;
    }
};
