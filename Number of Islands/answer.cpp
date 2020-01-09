class Solution {
public:
    void dfs(int x, int y, vector<vector<char>>& grid) 
    {
        int xPace[] = {0,1,0,-1};
        int yPace[] = {1,0,-1,0};
        for(int i=0;i<4;i+=1)
        {
            int x2 = x+ xPace[i];
            int y2 = y+ yPace[i];
            if(x2<grid.size()&&y2<grid[x2].size()&&grid[x2][y2] == '1')
            {
                grid[x2][y2] = '2';
                dfs(x2, y2, grid);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int ret=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    grid[i][j]=='2';
                    ret++;
                    dfs(i,j,grid);
                }
            }
        }
        return ret;
    }
    
    
};
