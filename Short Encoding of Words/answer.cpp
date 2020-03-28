// this code is also utilize the property that 
// if t is the suffix of string s, then t can be omitted
// here we contruct a special comparator function, which return the dictionary order from the end to the front


class Solution {
public:
    // return true if t is the suffix of s
    bool endsWith(string& s, string& t) {
        int N1 = s.length();
        int N2 = t.length();
        if (N1 < N2) {
            return false;
        }
        for (int i = 0; i < N2; i++) {
            if (s[N1-N2+i] != t[i]) {
                return false;
            }
        }
        return true;
    }
    int minimumLengthEncoding(vector<string>& words) {
        
        // dictionary order from the end of the string to the beginning
        auto comparator = [](string& s1, string& s2){ 
            int N1 = s1.length();
            int N2 = s2.length();
            for (int i = 0; i < min(N1, N2); i++) {
                char c1 = s1[N1-1-i];
                char c2 = s2[N2-1-i];
                if (c1 != c2) {
                    return c1 < c2;
                    }
            }
            return N1 < N2;
        };
        int N = words.size();
        // 逆序字典序排序    
        sort(words.begin(), words.end(), comparator);

        int ret = 0;
        for (int i = 0; i < N; i++) {
            if (i+1 < N && endsWith(words[i+1], words[i])) {
                // 当前单词是下一个单词的后缀，丢弃
            } else {
                ret += words[i].length() + 1; // 单词加上一个 '#' 的长度
            }
        }
        return ret;

    }
};
