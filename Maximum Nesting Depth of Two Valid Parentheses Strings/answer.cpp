// it basically a stack solution
// to save the space, we use a simulation of stack instead of a real one
// we set sizeof(A) == sizeof(B), such that we can has the minimal sizeof the larger one of A and B
// we for the even numbered ( and ) we give to A, and odd numbered to B


class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        // a counter to record the number of ( we have met
        int d = 0;
        vector<int> ret;
        for (char& c : seq)
            if (c == '(') {
                ++d;
                ret.push_back(d % 2);
            }
            else {
                ret.push_back(d % 2);
                --d;
            }
        return ret;
    }
};
