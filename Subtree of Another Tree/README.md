Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
    Given tree s:

         3
        / \
       4   5
      / \
     1   2
    Given tree t:
       4 
      / \
     1   2
    Return true, because t has the same structure and node values with a subtree of s.

Example 2:
    Given tree s:

         3
        / \
       4   5
      / \
     1   2
        /
       0
    Given tree t:
       4
      / \
     1   2
    Return false.


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subtree-of-another-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
