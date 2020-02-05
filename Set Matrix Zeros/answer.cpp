// O(1) space solution

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        if(matrix.empty())
            return ;
        auto fillVerticalZeros = [&matrix](int column)
        {
            for(int i=0;i<matrix.size();i++)
                matrix[i][column] = 0;
        };
        
        auto fillHorizontalZeros = [&matrix](int row)
        {
            for(int i=0;i<matrix[0].size();i++)
                matrix[row][i] = 0;
        };
        bool verticalFlag = false, horizontalFlag = false;
        for(int i=0;i<matrix.size();i++)
        {
            if(matrix[i][0]==0)
            {
                verticalFlag = true;
                break;
            }
        }
        for(int j=0;j<matrix[0].size();j++)
        {
            if(matrix[0][j]==0)
            {
                horizontalFlag = true;
                break;
            }
        }
        
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=1;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                     matrix[0][j] = 0;
                     matrix[i][0] = 0;
                }
                   
            }
        }
        for(int i=1;i<matrix.size();i++)
        {
            if(matrix[i][0]==0)
                fillHorizontalZeros(i);
        }
        for(int j=1;j<matrix[0].size();j++)
        {
            if(matrix[0][j]==0)
                fillVerticalZeros(j);
        }
        if(verticalFlag)
        {
            fillVerticalZeros(0);
        }
        if(horizontalFlag)
            fillHorizontalZeros(0);
    }
};
