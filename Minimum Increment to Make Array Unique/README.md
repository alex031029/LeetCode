Given an array of integers A, a move consists of choosing any A[i], and incrementing it by 1.

Return the least number of moves to make every value in A unique.

 

Example 1:

    Input: [1,2,2]
    Output: 1
    Explanation:  After 1 move, the array could be [1, 2, 3].
Example 2:

    Input: [3,2,1,2,1,7]
    Output: 6
    Explanation:  After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
It can be shown with 5 or less moves that it is impossible for the array to have all unique values.
 

Note:

* 0 <= A.length <= 40000
* 0 <= A[i] < 40000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-increment-to-make-array-unique
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
