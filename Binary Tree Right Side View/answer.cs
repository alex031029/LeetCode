// a C# implementation
// interpreted from C++ version

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
    
    // returned value is an interface 
    public IList<int> RightSideView(TreeNode root) {
        IList<int> ret = new List<int>();
        
        // in C# null is different from an empty list
        if(root==null)
            return ret;
    
        Queue<TreeNode> even = new Queue<TreeNode>();
        Queue<TreeNode> odd = new Queue<TreeNode>();
        
        // Enqueue is push()
        odd.Enqueue(root);
        while(odd.Count()>0||even.Count()>0)
        {
            // Peak is top()
            // there is no empty() function, thus I use Count()
            if(odd.Count()>0)
                ret.Add(odd.Peek().val);
            while(odd.Count()>0)
            {
                // Dequeue is top() and pop()
                TreeNode temp = odd.Dequeue();
                if(temp.right!=null)
                    even.Enqueue(temp.right);
                if(temp.left!=null)
                    even.Enqueue(temp.left);
            }
            if(even.Count()>0)
                ret.Add(even.Peek().val);
            while(even.Count()>0)
            {
                TreeNode temp = even.Dequeue();
                if(temp.right!=null)
                    odd.Enqueue(temp.right);
                if(temp.left!=null)
                    odd.Enqueue(temp.left);
             }
        }
        return ret;
    }
}
