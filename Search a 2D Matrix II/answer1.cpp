// O(n+m) solution
// it traverses the matrix from the left bottem corner


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return false;

        int i = matrix.size()-1;
        int j = 0;
        while(i>=0&&j<matrix[0].size())
        {
            // cout<<i<<j<<endl;
            if(matrix[i][j]==target)
            {
                return true;
            }
            else if(matrix[i][j]<target)
            {
                j++;
            }
            else
                i--;
        }
        return false;
    }
};
