// a BFS search implementation

class Solution {
public:
    int m;
    int n;
    int k;
    int moveI[4] = {0,1,0,-1};
    int moveJ[4] = {1,0,-1,0};
    int ret = 0;
    vector<vector<bool>> flag;
    
    // possible() is true if (i,j) is walkable for the robot
    bool possible(int i, int j)
    {
        int sum = 0;
        while(i>0)
        {
            sum+=i%10;
            i/=10;
        }
        while(j>0)
        {
            sum+=j%10;
            j/=10;
        }
        return sum<=k;
    }
    
    // bfs traversal
    void bfs(int i,int j)
    {
        // cout<<i<<j<<endl;
        flag[i][j] = true;
        if(!possible(i,j))
            return;
        ret++;
        for(int t=0;t<4;t++)
        {
            int I = moveI[t] + i;
            int J = moveJ[t] + j;
            if(I>=0&&I<m&&J>=0&&J<n&&!flag[I][J])
                bfs(I,J);
        }
    }
    
    // initialize some variables
    int movingCount(int m, int n, int k) {
        this->m = m;
        this->n = n;
        this->k = k;
        vector<vector<bool>> flag(m,vector<bool>(n,false));
        this->flag = move(flag);
        bfs(0,0);
        return ret;
    }
};
