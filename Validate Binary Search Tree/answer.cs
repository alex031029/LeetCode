// interpreted from answer.cpp

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
 
public class Solution {
    public bool Helper(TreeNode root, long floor, long ceil) {
        if(root == null)
        {
            return true;
        }
        if(floor>=root.val||ceil<=root.val)
            return false;
        return Helper(root.left, floor, root.val)&&Helper(root.right, root.val, ceil);

    }
    public bool IsValidBST(TreeNode root) {
        // long int min and max value
        return Helper(root, Int64.MinValue, Int64.MaxValue);
    }
}
