// same as Course Schedule/answer.cpp
// the only difference is for the returned value

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ret;
        if(numCourses==0)
            return ret;
        vector<int> inDegree(numCourses);
        vector<vector<int>> outNeighbors(numCourses);
        queue<int> zeroInDegree;
        for(int i=0;i<prerequisites.size();i++)
        {
            inDegree[prerequisites[i][0]]++;
            outNeighbors[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i=0;i<inDegree.size();i++)
        {
            if(inDegree[i]==0)
                zeroInDegree.push(i);
        }
        int cnt=0;
        
        
        while(!zeroInDegree.empty())
        {
            int index = zeroInDegree.front();
            // cout<<index<<endl;
            zeroInDegree.pop();
            ret.push_back(index);
            cnt++;
            for(int i=0;i<outNeighbors[index].size();i++)
            {
                int neighbor = outNeighbors[index][i];
                if(--inDegree[neighbor]==0)
                    zeroInDegree.push(neighbor);
            }
        }
        if(cnt==numCourses)
            return ret;
        else
        {
            ret.clear();
            return ret;
        }
    }
};
