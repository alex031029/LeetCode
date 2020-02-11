// trivial implementation

class Solution {
public:
    string convertToTitle(int n) {
        string ret;
        while(n>0)
        {
            ret.push_back((n-1)%26+'A');
            n=(n-1)/26;
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
