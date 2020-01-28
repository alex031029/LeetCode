// a slow solution with O(m*n) time complexity
// divide and conquer 
// divide a matrix into four sub matrix
// and explorer three of these four matrix recursively

class Solution {
public:
    bool PartialSearchMatrix(vector<vector<int>>& matrix, int target, int left, int right, int floor, int ceil)
    {

        // cout<<left<<right<<floor<<ceil<<endl;
        int midRow = (left+right)/2;
        int midCol = (ceil+floor)/2;
        
        if(floor == midCol&&left == midRow)
        {
            return matrix[ceil][left]==target||matrix[floor][left]==target||matrix[ceil][right]==target||matrix[floor][right]==target;
        }
        if(matrix[midCol][midRow]>target)
        {
            // cout<<"case 1:"<<matrix[midCol][midRow]<<]<<endl;
            bool b1 = PartialSearchMatrix(matrix, target, left, midRow, floor, midCol);
            bool b2 = PartialSearchMatrix(matrix, target, midRow, right, floor, midCol);
            bool b3 = PartialSearchMatrix(matrix, target, left, midRow, midCol, ceil);
            return b1||b2||b3;
        }
        else   
        {
            bool b1 = PartialSearchMatrix(matrix, target, midRow, right, floor, midCol);
            bool b2 = PartialSearchMatrix(matrix, target, midRow, right, midCol, ceil);
            bool b3 = PartialSearchMatrix(matrix, target, left, midRow, midCol, ceil);
            return b1||b2||b3;
        }
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()||matrix[0].empty())
            return false;
        return PartialSearchMatrix(matrix, target, 0, matrix[0].size()-1, 0, matrix.size()-1);
    }
};
