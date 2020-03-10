// basically a binary search algorithm
// nothing fancy

class Solution {
  public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) 
        return false;
    int n = matrix[0].size();

    // 二分查找
    int left = 0, right = m * n - 1;
    int mid, pivotElement;
    while (left <= right) {
      mid = (left + right) / 2;
      pivotElement = matrix[mid / n][mid % n];
      if (target == pivotElement) 
        return true;
      else {
        if (target < pivotElement) 
            right = mid - 1;
        else 
            left = mid + 1;
      }
    }
    return false;
  }
};
