class Solution {
public:
    // it is trying to find, if there exist the string s
    // in s + s, starting from index 1 (not 0), that occurs before index s.size() 
    // (in other word, before the second half of s + s ) 
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) != s.size();
    }
};
