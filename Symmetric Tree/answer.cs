// recursive C# solution
// interpreted from C++ version

public class Solution {
    public bool IsMirror(TreeNode p1, TreeNode p2)
    {
        if(p1==null&&p2==null)
            return true;
        if(p1==null||p2==null)
            return false;
        if(p1.val!=p2.val)
            return false;
        return IsMirror(p1.left, p2.right)&&IsMirror(p2.left, p1.right);
    }
    public bool IsSymmetric(TreeNode root) {
        if(root==null)
            return true;
        return IsMirror(root.left, root.right);
    }
}
