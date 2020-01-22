// my solution is to draw the outermost spiral of a given matrix
// then shrink the size of the matrix and repeat it iteratively


class Solution {
public:

    // this function add the values into ret
    // from the outermost of matrix within the rectangle ceil, floor, left and right
    void partialSpiralOrder(vector<vector<int>>& matrix, vector<int> &ret, int ceil, int floor, int left, int right)
    {
        ret.insert(ret.end(), matrix[ceil].begin()+left, matrix[ceil].begin()+right+1);
        
        // return if it contains only a row
        if(floor == ceil)
            return;
        for(int i = ceil+1;i<=floor;i++)
        {
            ret.push_back(matrix[i][right]);
        }
        
        // return if it contains only a column
        if(left == right)
            return;
        
        // reverse the `floor`-th row of matrix, and insert into ret
        reverse(matrix[floor].begin()+left, matrix[floor].begin()+right);
        ret.insert(ret.end(), matrix[floor].begin()+left, matrix[floor].begin()+right);
        
        // return if it contains only two rows
        if(floor == ceil+1)
            return;
        for(int i = floor-1;i>=ceil+1;i--)
        {
            ret.push_back(matrix[i][left]);
        }
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if(matrix.empty())
            return ret;
        if(matrix.size() == 1)
            return matrix[0];
        
        
        int ceil = 0, floor = matrix.size()-1;
        int left = 0, right = matrix[0].size()-1;

        auto printRet = [&](){
            for(int i =0;i<ret.size();i++)
                cout<<ret[i]<<"\t";
            cout<<endl;
        };

        // iterativey invoke partialSpiralOrder
        while(right>=left&&floor>=ceil)
        {
            partialSpiralOrder(matrix,ret,ceil,floor,left,right);
            // printRet();
            ceil++;
            floor--;
            left++;
            right--;
        }
        
        return ret; 
    }
};
