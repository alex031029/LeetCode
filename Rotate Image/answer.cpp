class Solution {
public:
    void swap(int& x, int& y)
    {
        int temp = x;
        x = y;
        y = temp;
    }
    void helper(vector<vector<int>>& matrix, int offset)
    {
        int size = matrix.size()-offset;
        for(int i = size-1;i>=offset;i--)
        {
            swap(matrix[offset][i],matrix[matrix.size()-1-i][offset]);
        }
        for(int i = offset+1;i<size;i++)
        {
            swap(matrix[i][offset],matrix[matrix.size()-1-offset][i]);
        }
        for(int i = offset+1;i<size-1;i++)
        {
            swap(matrix[matrix.size()-1-offset][i],matrix[matrix.size()-1-i][matrix.size()-1-offset]);
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
