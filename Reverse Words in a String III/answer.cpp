// use string::find() to find the delimiter ' ' 

class Solution {
public:
    string reverseWords(string s) {
        if(s.empty())
            return s;
        // cout<<s.size()<<endl;
        int pos = 0;
        int prev = 0;
        while((pos = s.find(' ', prev))<s.size())
        {
            // cout<<pos<<endl;
            reverse(s.begin()+prev,s.begin()+pos);
            prev = pos+1;
        }
        reverse(s.begin()+prev, s.end());
        return s;
    }
};
