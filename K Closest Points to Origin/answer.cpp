// here I define a struct and overlord the operator < 
// operator < is to change the priority queue to min heap
// another idea is to set a comparator function for the third parameter of priority_queue
// this comparator function can be a lambda function

class Solution {
public:
    struct point{
        vector<int> coordinate;
        
        // note that `const` is compulsory here.
        // otherwise the compiler would raise an error
        bool operator<(const point & y) const
        {
            return this->coordinate[0]*this->coordinate[0]+this->coordinate[1]*this->coordinate[1]>y.coordinate[0]*y.coordinate[0]+y.coordinate[1]*y.coordinate[1];
        }

        point(vector<int> v)
        {
            coordinate = v;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> ret;

        // point * p1 = new point(points[0]);
        // point * p2 = new point(points[1]);
        // cout<<(*p2<*p1)<<endl;
        priority_queue<point> heap;
        for(int i=0;i<points.size();i++)
        {
            point * temp = new point(points[i]);
            heap.push(*temp);
        }
        for(int i=0;i<K;i++)
        {
            ret.push_back(heap.top().coordinate);
            heap.pop();
        }
        return ret;
    }
};
