// a working but practically not very efficient solution
// given a string s and t, if s is the suffix of t, then s can be omitted
// here we can see taht the size of s must be smaller than t
// therefore, we sort the words array given the the size of each elements
// then construct the index 

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        auto comparator = [](string& s1, string& s2){ return s1.size()>s2.size();};
        
        // sort words, make sure that the longer elements are sorted in the front
        sort(words.begin(), words.end(), comparator);
        if(words.empty())
            return 0;
        if(words.size()==1)
            return words[0].size()+1;
        
        string index = words[0]+'#';
        for(int i=1;i<words.size();i++)
        {
            // if words[i]+'#' cannot be found, we add it into the index
            if(index.find(words[i]+'#')>=index.size())
                index+=words[i]+'#';
        }

        return index.size();

    }
};
