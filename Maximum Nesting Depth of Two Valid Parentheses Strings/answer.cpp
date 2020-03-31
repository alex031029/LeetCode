// it basically a stack solution
// to save the space, we use a simulation of stack instead of a real one
// we set sizeof(A) == sizeof(B), such that we can has the minimal sizeof the larger one of A and B
// we for the even numbered ( and ) we give to A, and odd numbered to B


class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int d = 0;
        vector<int> ans;
        for (char& c : seq)
            if (c == '(') {
                ++d;
                ans.push_back(d % 2);
            }
            else {
                ans.push_back(d % 2);
                --d;
            }
        return ans;
    }
};
