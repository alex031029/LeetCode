Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

* The same word in the dictionary may be reused multiple times in the segmentation.
* You may assume the dictionary does not contain duplicate words.

Example 1:

    Input:
    s = "catsanddog"
    wordDict = ["cat", "cats", "and", "sand", "dog"]
    Output:
    [
      "cats and dog",
      "cat sand dog"
    ]
Example 2:

    Input:
    s = "pineapplepenapple"
    wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
    Output:
    [
      "pine apple pen apple",
      "pineapple pen apple",
      "pine applepen apple"
    ]
    Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

    Input:
    s = "catsandog"
    wordDict = ["cats", "dog", "sand", "and", "cat"]
    Output:
    []

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-break-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
