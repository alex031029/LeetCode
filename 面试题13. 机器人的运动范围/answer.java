// a Java implementation
// it is interpreted from C++ verison

class Solution {
    int m;
    int n;
    int k;
    
    // int moveI[] = {0,1,0,-1} is also a correct statement in Java
    int[] moveI = {0,1,0,-1};
    int[] moveJ = {1,0,-1,0};
    int ret = 0;
    
    // boolean flag[][] is also a correct statement
    boolean[][] flag;
    
    // possible() is true if (i,j) is walkable for the robot
    public boolean possible(int i, int j)
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
    public void bfs(int i,int j)
    {
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

    public int movingCount(int m, int n, int k) {
        this.m = m;
        this.n = n;
        this.k = k;
        
        // the default value of boolean variable is false
        this.flag = new boolean[m][n];
        bfs(0,0);
        return ret;
    }
}
