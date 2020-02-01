// a slow answer

class Solution {
public:
    string encode(string s)
    {
        string ret;
        char hash[26];
        memset(hash, 0, 26*sizeof(char));
        for(int i=0;i<s.length();i++)
        {
            hash[s[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            ret = ret+to_string(hash[i])+"#";
        }
        return ret;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;

        if(strs.empty())
            return ret;

        map<string, vector<int>> classifier;
        for(int i=0;i<strs.size();i++)
        {
            classifier[encode(strs[i])].push_back(i);
        }
        for(auto iter = classifier.begin();iter!=classifier.end();iter++)
        {
            vector<string> temp;
            for(int i=0;i<iter->second.size();i++)
            {
                temp.push_back(strs[iter->second[i]]);
            }
            ret.push_back(temp);
        }
        
        return ret;
    }
};
