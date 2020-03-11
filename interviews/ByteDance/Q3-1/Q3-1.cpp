#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int differentSquareElement(vector<int>& nums)
{
	if(nums.empty())
		return 0;
	int i = 0;
	int j = nums.size()-1;
	int ret = 0;
	while(j>i)
	{
		if(abs(nums[i])>abs(nums[j]))
		{
			ret++;
			while(i+1<j&&nums[i]==nums[i+1])
				i++;
			i++;
		}
		else if(abs(nums[i])<abs(nums[j]))
		{
			ret++;
			while(j-1>i&&nums[j]==nums[j-1])
				j--;
			j--;
		}
		else
		{
			ret++;
			while(i+1<j&&nums[i]==nums[i+1])
				i++;
			i++;
			while(j-1>i&&nums[j]==nums[j-1])
				j--;
			j--;
		}
	}
	return ret;
}

int main()
{
	vector<int> nums1 = {-5, -4, -2, -2, -1, 1, 1, 1, 2, 2, 3, 3, 4};
	cout<<differentSquareElement(nums1)<<endl;
}
