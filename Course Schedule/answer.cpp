// it is also a topological sort algorithm
// O(M+N) solution

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.empty())
            return true;
        
        // inDegree counts the in degree value of each node
        vector<int> inDegree(numCourses);
        
        // outNeighbors records all out neighbors of a node
        vector<vector<int>> outNeighbors(numCourses);
        
        // it keeps all nodes with 0 in degree
        queue<int> zeroInDegree;
        
        // initialize inDegree and outNeighbors
        for(int i=0;i<prerequisites.size();i++)
        {
            inDegree[prerequisites[i][1]]++;
            outNeighbors[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        // initialize zeroInDegree
        for(int i=0;i<inDegree.size();i++)
        {
            if(inDegree[i]==0)
                zeroInDegree.push(i);
        }
        int cnt=0;
        
        while(!zeroInDegree.empty())
        {
            int index = zeroInDegree.front();
            zeroInDegree.pop();
            cnt++;
            // update inDegree and zeroInDegree
            for(int i=0;i<outNeighbors[index].size();i++)
            {
                int neighbor = outNeighbors[index][i];
                if(--inDegree[neighbor]==0)
                    zeroInDegree.push(neighbor);
            }
        }
        return cnt==numCourses;
    }
};
