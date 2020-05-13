// a worth noting wrong answer
// the wrong solution comes from the different implementation of 
// `List<T>.Add()` in C# and `vector<T>.push_back()` in C++

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
    public IList<IList<int>> LevelOrder(TreeNode root) {
    
        // new a 2d list
        IList<IList<int>> ret = new List<IList<int>>();
        if(root == null)
            return ret;
        Queue<TreeNode> odd = new Queue<TreeNode>();
        Queue<TreeNode> even = new Queue<TreeNode>();
        odd.Enqueue(root);

        while(odd.Count>0||even.Count>0)
        {
            List<int> temp = new List<int>();
            while(odd.Count>0)
            {
                if(odd.Peek().left!=null)
                    even.Enqueue(odd.Peek().left);
                if(odd.Peek().right!=null)
                    even.Enqueue(odd.Peek().right);

                temp.Add(odd.Peek().val);
                odd.Dequeue();
            }
            
            if(temp.Count>0)
            {
                // Console.WriteLine(temp.ToString());
                // temp.ForEach(item => Console.Write(item + ","));
                // Console.WriteLine();
                ret.Add(temp);
            }
            
            // NOTE THAT we have to new another List<int> temp2 
            // instead of calling `temp.Clear()` as in C++ implememtation 
            // it is because `List<T>.Add()` add the reference of the a `T` object
            // thus, we could modify the element in `ret` if we do a `List<T>.Clear()` operation
            // In comparison, n C++, the `push_back()` is a copy constructor
            
            temp.Clear();
            while(even.Count>0)
            {
                if(even.Peek().left!=null)
                    odd.Enqueue(even.Peek().left);
                if(even.Peek().right!=null)
                    odd.Enqueue(even.Peek().right);

                temp.Add(even.Peek().val);
                even.Dequeue();
            }
            if(temp2.Count>0)
            {
                // Console.WriteLine(temp.ToString());
                // temp2.ForEach(item => Console.Write(item + ","));
                // Console.WriteLine();
                ret.Add(temp);
            }
            
        }
        return ret;
    
    }
}
