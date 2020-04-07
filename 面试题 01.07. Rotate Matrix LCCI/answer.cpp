// better than 100% LeetCode user in both time and space overheads
// it is same as Rotate Image/answer.cpp
// the only difference is that I remove swap function


class Solution {
public:

    void helper(vector<vector<int>>& matrix, int offset)
    {
        int size = matrix.size()-offset;
        for(int i = size-1;i>=offset;i--)
        {
            swap(matrix[offset][i],matrix[matrix.size()-1-i][offset]);
        }
        for(int i = offset+1;i<size;i++)
        {
            swap(matrix[i][offset],matrix[size-1][i]);
        }
        for(int i = offset+1;i<size-1;i++)
        {
            swap(matrix[size-1][i],matrix[matrix.size()-1-i][size-1]);
        }
        // for(int i = matrix.size()-2-offset;i>=offset;i--)
        // {
        //     swap(matrix[i][matrix.size()-1-offset]);
        // }
    }
    void rotate(vector<vector<int>>& matrix) {
        // helper(matrix, 0);
        for(int i=0;i<matrix.size()/2;i++)
            helper(matrix, i);
    }
};
