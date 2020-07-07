// a c# version

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
    int sum;
    bool ret = false;
    public void Dfs(TreeNode root, int offset)
    {
        if(root== null||ret)
            return;
        offset += root.val;
        if(offset==sum&&root.left==null&&root.right==null)
        {
            ret = true;
            return;
        }
        Dfs(root.left, offset);
        Dfs(root.right, offset);
    }
    public bool HasPathSum(TreeNode root, int sum) {
        if(root==null)
            return false;
        this.sum = sum;
        Dfs(root, 0);
        return ret;
    }
}
