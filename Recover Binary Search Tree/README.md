Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Example 1:

    Input: [1,3,null,null,2]

       1
      /
     3
      \
       2

    Output: [3,1,null,null,2]

       3
      /
     1
      \
       2
Example 2:

    Input: [3,1,4,null,null,2]

      3
     / \
    1   4
       /
      2

    Output: [2,1,4,null,null,3]

      2
     / \
    1   4
       /
      3
    Follow up:

* A solution using O(n) space is pretty straight forward.
* Could you devise a constant space solution?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/recover-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
