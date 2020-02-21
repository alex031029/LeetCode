// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    if(S.size()<=2)
        return 0;
        
    int ret = 0;
    for(int i=0;i<S.size();i++)
    {
        long long cnt = 1;
        int j = i;
        for(j=i+1;j<S.size();j++)
        {
            if(S[j]!=S[i])
                break;
            cnt++;
        }
        // i = j fails on cases like aaabbb
        i=j-1;
        ret+= cnt/3;
        // cout<<ret<<endl;
    }
    return ret;
}
