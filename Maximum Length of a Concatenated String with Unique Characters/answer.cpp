// a backtracking method

class Solution {
public:
    // hash for check if the node has appeared
    int hash[26];
    // store the maximum value
    int ret=0;
    // update hash after adding a string s
    // return true if some letters of s have appeared
    bool hashAdd(string& s)
    {
        bool ret = false;
        for(int i=0;i<s.size();i++)
        {
            int index = s[i]-'a';
            if(hash[index]++!=0)
                ret = true;
        }
        return ret;
    }
    // update hash after reduce a string s from it
    void hashMinus(string &s)
    {
        for(int i=0;i<s.size();i++)
        {
            hash[s[i]-'a']--;
        }
    }
    
    // i is the that we are going to examine arr[i]
    // l is the length of given this flag 
    void helper(vector<bool>& flag, vector<string>& arr, int i, int l)
    {
        // cout<<"ret:"<<ret<<"\t"<<"l:"<<l<<"\t";
        // for(int j=0;j<flag.size();j++) 
        //     cout<<flag[j]<<"\t";
        // cout<<endl;
        
        // update ret if l is larger
        if(l>ret)
        {
            // cout<<"ret:"<<ret<<"\t";
            // for(int j=0;j<flag.size();j++) 
            //     cout<<flag[j]<<"\t";
            // cout<<endl;
            ret = l;
        }
        if(i==arr.size())
            return;
        // if some letters in arr[i] appeared before
        // we examine the next string
        if(hashAdd(arr[i]))
        {
            hashMinus(arr[i]);
            helper(flag, arr, i+1, l);
        }
        // otherwise, we examine two possibilities
        // that add arr[i] into ret or not 
        else
        {
            flag[i]=true;
            helper(flag, arr, i+1, l+arr[i].size());
            flag[i]=false;
            hashMinus(arr[i]);
            helper(flag, arr, i+1, l);
        }
    }
    int maxLength(vector<string>& arr) {
        if(arr.empty())
            return 0;
        memset(hash,0,sizeof(int)*26);
        vector<bool> flag(arr.size(), false);
        helper(flag,arr,0,0);
        return ret;
    }
};
