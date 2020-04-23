Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents), and pennies (1 cent), write code to calculate the number of ways of representing n cents. (The result may be large, so you should return it modulo 1000000007)

Example1:

    Input: n = 5
    Output: 2
    Explanation: There are two ways:
    5=5
    5=1+1+1+1+1

Example2:

    Input: n = 10
    Output: 4
    Explanation: There are four ways:
    10=10
    10=5+5
    10=5+1+1+1+1+1
    10=1+1+1+1+1+1+1+1+1+1

Notes:

You can assume:

    0 <= n <= 1000000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/coin-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
