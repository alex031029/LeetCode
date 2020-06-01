// a recursive O(n) solution

class Solution {
public:
    int sumNums(int n) {
        // use n as a boolean variable to make a base case for recursion
        n && (n+=sumNums(n-1));
        return n;
    }
};
