// easy, nothing fancy

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i=digits.size()-1;i>=0&&carry==1;i--)
        {
            int val = digits[i]+carry;
            digits[i] = val%10;
            carry = val/10;
        }
        if(carry==0)
            return digits;
        else
        {
            vector<int> ret = {1};
            ret.insert(ret.end(), digits.begin(), digits.end());
            return ret;
        }
    }
};
