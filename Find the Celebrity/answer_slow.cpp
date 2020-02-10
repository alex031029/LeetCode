// a brute and forece O(n^2) solutoin

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {

        for(int i=0;i<n;i++)
        {
            int flag = true;
            for(int j=0;j<n&&flag;j++)
            {
                if(i==j)
                    continue;
                if(!knows(j, i)||knows(i, j))
                    flag = false;
            }
            if(flag)
                return i;
        }
        return -1;
    }
};
