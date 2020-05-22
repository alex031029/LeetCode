// interpreted from c++ version

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
    public TreeNode Helper(int[] preorder, int l1, int r1, int[] inorder, int l2, int r2)
    {
        if(l1>r1||l2>r2)
            return null;
        
        TreeNode root = new TreeNode(preorder[l1]);
        int i = l2;
        for(i=l2;i<r2;i++)
        {
            if(inorder[i] == preorder[l1])
                break;
        }
        TreeNode left = Helper(preorder, l1+1, r1, inorder, l2, i-1);
        TreeNode right = Helper(preorder, l1+1+i-l2, r1, inorder, i+1, r2);
        root.left = left;
        root.right = right;
        return root;

    }
  
    public TreeNode BuildTree(int[] preorder, int[] inorder) {
        return Helper(preorder, 0, preorder.Length-1, inorder, 0, inorder.Length-1);
    }
}
