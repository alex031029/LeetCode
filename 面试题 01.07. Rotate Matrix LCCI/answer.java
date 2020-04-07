// a java implementation
// it is interpreted from C++ code 
// this code outperforms 100% LeetCode Java users in both time and space overheads

class Solution {
    public void helper(int[][] matrix, int offset)
    {
        int size = matrix.length-offset;
        for(int i = size-1;i>=offset;i--)
        {
            // since there is no swap function in Java 
            // I have to implement swap by myself
            // it is due to the property that Java does not have pointer to modify parameters of function
            int temp = matrix[offset][i];
            matrix[offset][i] = matrix[matrix.length-1-i][offset];
            matrix[matrix.length-1-i][offset] = temp;
        }
        for(int i = offset+1;i<size;i++)
        {
            int temp = matrix[i][offset];
            matrix[i][offset] = matrix[size-1][i];
            matrix[size-1][i] = temp;
        }
        for(int i = offset+1;i<size-1;i++)
        {
            int temp = matrix[size-1][i];
            matrix[size-1][i] = matrix[matrix.length-1-i][size-1];
            matrix[matrix.length-1-i][size-1] = temp;
        }

    }
    public void rotate(int[][] matrix) {
        for(int i=0;i<matrix.length/2;i++)
            helper(matrix, i);
    }
}
