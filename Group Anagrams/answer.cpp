// a improved version of answer_slow.cpp

class Solution {
public:
    string encode(string s)
    {
        string ret;
        // using char instead of int as hash function
        char hash[26];
        memset(hash, 0, 26*sizeof(char));
        for(int i=0;i<s.length();i++)
        {
            hash[s[i]-'a']++;
        }
        // since hash[] is a char[] function, we can directly use push_back function to reduce time
        for(int i=0;i<26;i++)
        {
            ret.push_back(hash[i]);
        }
        return ret;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;

        if(strs.empty())
            return ret;
        
        // here we also optimize classifier 
        // the value of classifier is int, indicating the index of ret of the corresponding group of anagrams
        map<string, int> classifier;
        for(int i=0;i<strs.size();i++)
        {
            string code = encode(strs[i]);
            if(classifier.find(code)==classifier.end())
            {
                classifier[code] = ret.size();
                vector<string> temp = {strs[i]};
                ret.push_back(temp);
            }
            else
            {
                ret[classifier[code]].push_back(strs[i]);
            }
        }
        
        return ret;
    }
};
