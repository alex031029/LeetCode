// 这题没啥意思，懒得做
// 直接看的答案
// 一个数学解法

class Solution {
public:
    int lastRemaining(int n, int m) {
        int f = 0;
        for (int i = 2; i != n + 1; ++i)
            f = (m + f) % i;
        return f;
    }
};
