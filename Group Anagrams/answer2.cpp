// an alter answer, with the same idea of answer.cpp 
// the difference is the encode funcion
// here we use the first 26 prime numbers as the hash function
// but this function can be easily overflowed.

class Solution {
public:
    int primes[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

    // only unsignd long long int will not overfloew for all leetcode test cases
    // even long long int will fail a case
    unsigned long long encode(string s)
    {
        unsigned long long ret = 1;
        for(int i=0;i<s.length();i++)
        {
            ret *= primes[s[i]-'a'];
        }
        return ret;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;

        if(strs.empty())
            return ret;

        map<unsigned long long, int> classifier;
        for(int i=0;i<strs.size();i++)
        {
            unsigned long long code = encode(strs[i]);
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
