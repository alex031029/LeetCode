// average O(n log n) solution, but the worst case can be O(n^2)
// it first sort all elements in intervals, based on the beginning time of this element
// then use the greedy method

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

        int record[100];
        memset(record, 0, 100*sizeof(int));
        record[0] = intervals[0][1];

        auto updateRecord = [&](vector<int> room){
            bool flag = false;
            for(int i=0;i<ret;i++)
            {
                if(room[0]>=record[i])
                {
                    record[i] = room[1];
                    // ret++;
                    flag = true;
                    break;
                }
            }
            if(!flag)
            {
                record[ret] = room[1];
                ret++;
            }
        };

        for(int i = 1; i<intervals.size();i++)
        {
             updateRecord(intervals[i]);
        }

        return ret;
    }
};
