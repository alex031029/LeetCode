// an iterative solution, using some idea of BFS search

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        if(grid.empty())
            return -1;
        int N = grid.size();
        
        // constrcut the list of all islands
        vector<pair<int,int>> islands;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(grid[i][j]==1)
                {
                    islands.emplace_back(i,j);
                }
            }
        }
        if(islands.size()==N*N||islands.empty())
            return -1;
        int ret = 0;
         
         
        // the directions of four possible moves
        int moveI[] = {0,1,0,-1};
        int moveJ[] = {1,0,-1,0};
        
        // loop until the whole grid are islands
        while(1)
        {
            vector<pair<int,int>> newIslands;
            for(auto& island:islands)
            {
                // check four directions, if they are still oceans
                // if so, push it into newIslands
                for(int t=0;t<4;t++)
                {
                    int I = island.first+moveI[t];
                    int J = island.second+moveJ[t];
                    if(I>=0&&I<N&&J>=0&&J<N&&grid[I][J]==0)
                    {
                        grid[I][J]=1;
                        newIslands.emplace_back(I,J);
                    }
                }
            }
            
            // if no more islands can be found, break;
            if(newIslands.empty())
                break;
            ret++;
            islands = move(newIslands);
        }
        return ret;
    }
};
