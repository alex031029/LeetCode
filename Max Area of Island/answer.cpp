// basically same as number of islands


class Solution {
public:
    void dfs(int x, int y, vector<vector<int>>& grid, int& cnt) 
    {
        // pace of x and y axis
        // -1 means back tracking 
        int xPace[] = {0,1,0,-1};
        int yPace[] = {1,0,-1,0};
        for(int i=0;i<4;i+=1)
        {
            int x2 = x+ xPace[i];
            int y2 = y+ yPace[i];
            if(x2<grid.size()&&y2<grid[x2].size()&&grid[x2][y2] == 1)
            {
                // setting to '2' means this coordinate has been visited.
                grid[x2][y2] = 2;
                cnt++;
                dfs(x2, y2, grid,cnt);
            }
        }
        return;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ret=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                {
                    grid[i][j]=2;
                    // whenever meet a new coordinate with value '1', it means a new island
                    int cnt = 1;
                    dfs(i,j,grid,cnt);
                    if(cnt>ret)
                        ret = cnt;
                }
            }
        }
        return ret;
    }
};
