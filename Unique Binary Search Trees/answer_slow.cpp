// a recursive method
// slow, but straightforward

class Solution {
public:
    int numTrees(int n) {
        if(n==0)
            return 1;
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        int ret=0;
        for(int i=0;i<=n-1;i++)
        {
            // pick the i-th element as the root, 
            // the there are i nodes in left subtree and n-1-i nodes in right sustree
            ret+=numTrees(i)*numTrees(n-1-i);
        }
        return ret;
    }
};
