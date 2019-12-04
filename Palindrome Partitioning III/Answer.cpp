class Solution {
public:
    int palindromePartition(string str, int k) {
        return recur(str, 0, str.length()-1, k);
    }
    
    // calculate the cost of a substring from s to t
    int cost(string str, int s, int t) {
        int ret = 0;
        for(int i=s,j=t; i<j;i++,j--)
        {
            if(str[i]!=str[j])
            {
                ret++;
            }
        }
        // printf("%s\t%d\t%d\t%d\n",str.c_str(),s,t,ret);
        return ret;
    }
    // without a map to record computed recurrence results, this code would be overtime
    map<pair<pair<int,int>,int>, int> matrix;
    int recur(string str, int s, int t, int k) 
    {
        if(matrix.find(pair(pair(s,t),k))!=matrix.end())
        {
            return matrix[pair(pair(s,t),k)];
        }
        if(k == t - s +1)
            return 0;
        if(k == 1)
            return cost(str, s, t);
        int ret=0x7fffffff;
        for(int i = s + k -1; i<=t ; i++)
        {
            int temp = recur(str,s,i-1,k-1)+cost(str,i,t);
            if (ret > temp)
                ret = temp;
        }
        matrix[pair(pair(s,t),k)] = ret;
        return ret;
    }
};
