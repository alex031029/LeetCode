// an O(mn+k(m+n)) time solution, with worst case space complexity O(mn)
// where k is the number of zeros in matrix

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        auto fillZeros = [&matrix](int x, int y)
        {
            for(int i=0;i<matrix.size();i++)
                matrix[i][y] = 0;
            for(int j=0;j<matrix[0].size();j++)
                matrix[x][j] = 0;
        };

        vector<pair<int,int>> zeros;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                    zeros.push_back(pair<int,int>(i,j));
            }
        }
        for(int i=0;i<zeros.size();i++)
        {
            fillZeros(zeros[i].first,zeros[i].second);
        }
    }
};
