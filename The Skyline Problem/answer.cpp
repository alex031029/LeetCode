// can hardly figure it out :(

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> all;
        vector<vector<int>> ret;
        
        // the left line is set to a negative number
        // in this manner, two buildings [L1,R1,H1] and [L2,R2,H2]
        // where R1==L1, we insert the left line of second building
        for(int i=0;i<buildings.size();i++)
        {
            all.emplace_back(buildings[i][0], -buildings[i][2]);
            all.emplace_back(buildings[i][1], buildings[i][2]);
        }
        
        // add all pairs of left/right line and height
        sort(all.begin(),all.end());
        int prev = 0;
        int cur = 0;
        multiset<int> m;
        m.insert(0);
        for(auto& p:all)
        {
            // cout<<*m.rbegin()<<endl;
            if(p.second<0)
            {    
                m.insert(-p.second);
            }
            else
            {
                m.erase(m.find(p.second));
                
                // the following statement cannot be used, since multimap::erase(val) will remove all elements with value val
                // m.erase(p.second);       
            } 
            
            // update ret if the current height is not as previous
            cur = *m.rbegin();  
            if(prev!=cur)
            {
                ret.emplace_back(vector<int>{p.first, cur});
                prev = cur;
            }
        }
        return ret;

    }
};
