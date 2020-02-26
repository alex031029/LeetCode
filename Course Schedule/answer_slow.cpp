// basically this algorithm is to determine if the graph is a DAG
// I am using topological sort to determine it
// the algorithm I use below to find the node with 0 indegree is rather naive 
// thus, this algorithm is relatively slow

class Solution {
public:
    // delete the node i from indegree
    void adjustInDegree(vector<vector<int>>& inDegree, int i)
    {
        for(int j=0;j<inDegree.size();j++)
        {
            if(j==i)
                continue;
            for(int t=0;t<inDegree[j].size();t++)
            {
                if(inDegree[j][t]==i)
                {
                    // cout<<"delete:"<<inDegree[j][t]<<endl;
                    inDegree[j].erase(inDegree[j].begin()+t);
                    break;
                }
            }
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.empty())
            return true;
            
        // store incoming neighbor of a given node
        vector<vector<int>> inDegree(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            inDegree[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        // a deleted function to record if it has been deleted
        int cnt=0;
        bool deleted[numCourses];
        memset(deleted, false, sizeof(bool)*numCourses);
        while(1)
        {
            bool flag = false;
            for(int i=0;i<numCourses;i++)
            {
                if(inDegree[i].size()==0&&!deleted[i])
                {
                    // cout<<inDegree[0].size()<<endl;
                    adjustInDegree(inDegree, i);
                    cnt++;
                    deleted[i]=true;
                    // cout<<i<<"\t"<<cnt<<endl;
                    // cout<<inDegree[0].size()<<endl;
                    // return true if all nodes have been deleted
                    if(cnt==numCourses)
                        return true;
                    flag = true;
                }
            }
            // if no node has 0 in-degree, return false
            if(!flag)
                return false;
        }
        return false;
    }
};
