// a TLE code 
// it is a brute force solution

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        if(grid.empty())
            return -1;
        int N = grid.size();
        
        // a vector store all element in grid that is 1
        vector<pair<int,int>> islands;
        
        // a lambda function that return true
        // if an island is surround by other island
        // I wished to use this improvement to circumvent TLE problem
        // which turns out not working 
        auto omitIsland = [&grid,&N](int& i, int& j)
        {
            int moveI[] = {0,1,0,-1};
            int moveJ[] = {1,0,-1,0};
            for(int t=0;t<4;t++)
            {
                int I = i+moveI[t];
                int J = j+moveJ[t];
                if(I>=0&&I<N&&J>=0&&J<N&&grid[I][J]==0)
                    return false;
            }
            return true;
        };
        
        
        // contruct the islands list
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(grid[i][j]==1&&!omitIsland(i,j))
                {
                    islands.emplace_back(i,j);
                }
            }
        }
        
        // return false if all elements is island or ocean
        if(islands.size()==N*N||islands.empty())
            return -1;
        int ret = 0;
        
        // the brute and force main algorithm 
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(grid[i][j]==0)
                {
                    // for each ocean element, find the nearest island
                    int dis = INT_MAX;
                    for(auto& island:islands)
                    {
                        int temp = abs(island.first-i)+abs(island.second-j);
                        if(temp<dis)
                            dis = move(temp);
                        // early termination 
                        if(dis<=ret)
                            break;
                    }
                    
                    // update ret if necessary
                    if(dis>ret)
                        ret = move(dis);
                }
            }
        }
        return ret;
    }
};
