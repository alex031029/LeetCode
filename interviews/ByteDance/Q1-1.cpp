// number of islands

#include <iostream>
using namespace std;
int main() {
    //int a;
    //cin >> a;
    void dfs(vector<vector<int>>& nums, int x, int y)
    {
        nums[i][j] = 2;
        int paceX = {0,1,0,-1};
        int paceY = {1,0,-1,0};
        for(int i = 0;i<4;i++)
        {
            int X = x+pace[i];
            int Y = y+pace[y];
            if(X<nums.size()&&Y<nums[0].size()&&nums[x][y]==1)
                dfs(nums, X, Y);
        }
    }
    int countIslands(vector<vector<int>> &nums)
    {
        if(nums.empty())
                return 0;
        int ret = 0;
        for(int x=0;x<nums.size();x++)
        {
            for(int y=0;y<nums[x].size();y++)
            {
                if(nums[x][y]==1)
                {
                    ret++;
                    dfs(nums,x,y);
                }
            }
        }
        return ret;
    }
}
