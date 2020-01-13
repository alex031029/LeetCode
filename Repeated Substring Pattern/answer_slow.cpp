class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.length()<=1)
                return false;
        string substr = s.substr(0,1);

        auto simpleRepeat = [&]()->bool{
                if(s.size()%substr.length()!=0)
                        return false;
                for(int i=0;i<s.length();i++)
                {
                        int j = i % substr.length();
                        if(s[i]!=substr[j])
                                return false;
                }
                return true;
        };

        for(int i=0;i<s.length();i++)
        {
                if(substr.length()>s.length()/2)
                        return false;
                if(simpleRepeat())
                {
                        // cout<<substr<<endl;
                        return true;
                }
                substr = s.substr(0,substr.length()+1);
        }
        return false;
    }
};
