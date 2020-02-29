// 给定一个数组a[0, n-1]，如果相邻的元素不能同时入选，如何选择一个和最大的子数组并返回他们的和？
#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

int maxSubset(vector<int> nums)
{
    if(nums.empty())
      	return 0;
    if(nums.size()==1)
      	return nums[0];
    if(nums.size()==2)
      	return max(nums[0],nums[1]);
  
  	int n = nums.size()+1;
    int dp[n];
  	memset(dp,0,sizeof(int)*n);
  	dp[0] = 0;
  	dp[1] = nums[0];
    dp[2] = max(nums[0],nums[1]);
    
                
    // dp[i] means the maxmum value of subset of nums[0,...i-1], such that no subset has two adjacent elements
    for(int i=3;i<n;i++)
    {
      	dp[i] = max(dp[i-1],dp[i-2]+nums[i-1]);
    }
    // 假设dp[i-1]中并没使用nums[i-2]这项
    // 但是这个其实已经被包括在了dp[i-2]之中
  	// 因为nums[i-2]并未使用，所以dp[i-2]==dp[i-1]
    // dp[i-2]+nums[i-1]将必然被赋值给dp[i]
                
                
    return dp[n-1];
}

int main()
{
	vector<int> nums = {1,3,5,0,4,9};
	cout<<maxSubset(nums)<<endl;	
}
