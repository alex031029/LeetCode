class Solution {
public:
    // a faster implementation without converting int to string
    bool isPalindrome(int x) {
        if(x==0)
            return true;
        if(x<0||x%10==0)
            return false;
        int reverse = 0;
        while(x>reverse)
        {
            reverse = reverse*10+x%10;
            x /= 10;
        }
        // cout<<x<<"\t"<<reverse<<endl;
        return (x==reverse||reverse/10==x);
    }
    
    // a slower implementatation using sstream/sscanf
    bool isPalindrome2(int x) {
        if(x<0)
            return false;
        stringstream ss;
        ss << x;
        string s;
        ss >> s;
        // cout<<s<<endl;
        int size = s.length();
        for(int i=0;i<size/2;i++)
        {
            if(s[i]!=s[size-1-i])
                return false;
        }
        return true;
    }
};
