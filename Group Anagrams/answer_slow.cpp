// a slow answer

class Solution {
public:
    // encode the input string. 
    // Any anagram has identical output
    string encode(string s)
    {
        string ret;
        int hash[26];
        memset(hash, 0, 26*sizeof(int));
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

        // the classifier record each encoded string to indentify anagrams
        map<string, vector<int>> classifier;
        for(int i=0;i<strs.size();i++)
        {
            classifier[encode(strs[i])].push_back(i);
        }
        // traverse classifier
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
