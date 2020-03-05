#include<iostream>
#include<vector>

using namespace std;

int helper(int n, int k, int h, bool& flag)
{
	flag = false;
	int ret = 0;
	// a wrong case
	if(k<h)
	{
		flag = false;
		return 0;
	}
	// when the heigh of h is reached in a certain subtree
	if(n==1&&k==h)
	{
		flag = true;
		// ret=(++ret)%9901;
		return 1;

	}
	// the heigh of h is not reached, thus we set flag as false
	if(n==1&&k>h)
	{
		return 1;
	}
	for(int i=1;i<=n-1;i+=2)
	{
		bool flag1 = false;
		bool flag2 = false;
		int a = helper(i,k,h+1,flag1);
		int b = helper(n-i-1,k,h+1,flag2);	
		// if and only if one of the subtrees reaches the height of h, we accumulate the result
		if(flag1||flag2)
		{
			// if any case if true, we set the flag to true
			flag = true;
			ret = (ret+a*b)%9901;
			// cout<<n<<k<<h<<":"<<a<<"\t"<<b<<"\t"<<ret<<endl;
		}
	}
	// if(k==h)
	// 	flag = true;
	return ret;
}
int main()
{
	bool flag = false;
	cout<<helper(7,4,1,flag)<<endl;   
	// output is 4, the left tree of 5 nodes and right tree of 1 node or vise versa. 
	// the left tree and right tree contain both 3 nodes is not calculated since the tree does not reached the height of 4
}
