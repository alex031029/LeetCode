// 给定1个二维字符数组m和单词1个w，搜索w是否在m中。搜索的定义是从m的任意位置开始，可以上下左右移动，依次和w每个字符匹配，如果w能匹配完，则存在，否则不存在。

// - 例子："zoo"，"zoro"，"xtifx"都能够搜索成功，但"oto"搜索不成功。

// a c d z
// x t r o
// f i o o

#include<iostream>
#include<vector>

using namespace std;

bool dfs(vector<vector<char>>& chars, string& s, int offset, int x, int y)
{
    if(offset>=s.size()-1)
            return true;
     int paceX[] = {0,1,0,-1};
     int paceY[] = {1,0,-1,0};
     for(int i=0;i<4;i++)
     {
         int X = paceX[i]+x;
         int Y = paceY[i]+y;
         bool flag = false;
         if(X>=0&&X<chars.size()&&Y>=0&&Y<chars[0].size()&&chars[X][Y]==s[offset+1])
             flag = dfs(chars, s, offset+1, X, Y);
         if(flag)
             return true;
     }
     return false;
}

bool findWord(vector<vector<char>>& chars, string& s)
{
    if(chars.empty())
            return false;
    if(s.empty())
            return true;
    for(int i=0;i<chars.size();i++)
    {
        for(int j =0;j<chars[i].size();j++)
        {
            if(chars[i][j]==s[0]&&dfs(chars, s, 0, i, j))
                  return true;
        }
    }
    return false;
}


int main() {
     vector<vector<char>> chars = {{'a','c','d','z'},{'x','t','r','o'},{'f','i','o','o'}};
     string s = "xtifx";
     cout<<findWord(chars, s)<<endl;
}
