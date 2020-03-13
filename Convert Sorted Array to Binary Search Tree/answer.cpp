// a recursive solution

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(int left, int right, vector<int>& nums)
    {
        if(left > right)
            return NULL;
        // pick the mid element as the root from left to right
        int mid = (left+right)/2;
        TreeNode * p = new TreeNode(nums[mid]);
        p->left = helper(left, mid-1, nums);
        p->right = helper(mid+1, right, nums);
        return p;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty())
          return NULL;
        return helper(0, nums.size()-1, nums);
    }
};
