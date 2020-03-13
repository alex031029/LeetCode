// a self-explained brute force solutin
// but it is not slow!

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        for(int a=1;a<4;a++)
        {
            for(int b=1;b<4;b++)
            {
                for(int c=1;c<4;c++)
                {
                    for(int d=1;d<4;d++)
                    {
                        if(a+b+c+d!=s.size())
                            continue;
                        int s1 = stoi(s.substr(0, a));
                        int s2 = stoi(s.substr(a, b));
                        int s3 = stoi(s.substr(a + b, c));
                        int s4 = stoi(s.substr(a+b+c));
                        if(s1<=255&&s2<=255&&s3<=255&&s4<=255)
                        {
                            // it is to remove the meaning less 0 in the integers 
                            string ip = to_string(s1)+'.'+to_string(s2)+'.'+to_string(s3)+'.'+to_string(s4);
                            if(ip.size() == s.size()+3)
                                ret.push_back(ip);
                        }
                    }
                }
            }
        }
        return ret;
    }
};
