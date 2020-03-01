// 6个小朋友踢足球，
// 规则：每个人只能踢给别人，不能自己踢给自己。
// 开始足球在小朋友A脚下，经过10次踢球传递，求最后球还在小朋友A脚下的所有踢法数目。
// 可以联想到的数据结构或数学知识？


// 这个算法包含两个解法
// 一是使用queue来模拟树的BFS
// 二是利用递推公式的递归解法

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int ret;
// 树结构
struct node{
	vector<node*> next;
	int val; // 小朋友编号，取值0~5，表示A~F
	bool end; // end==true 如果遍历了10层，同时val==0
	node(int x):val(x),end(false){};
};
node * helper(int k)
{
	node * root = new node(0);
	node * p = root;
   
	// 奇数与偶数层的BFS遍历
	queue<node*> odd; 
	queue<node*> even;
	odd.push(root);
	for(int i=0;i<k-1;)
	{
		//cout<<"odd size"<<i<<"\t"<<odd.size()<<endl;
        	// 踢第奇数次球
		while(!odd.empty())
		{
			p=odd.front();
			odd.pop();
			for(int j=0;j<6;j++)
			{
				if(j==p->val)
					continue;
				else
				{
					node* temp = new node(j);
                    			// 我们并不需要真正保留树结构，所以并不对next进行修改
					// p->next.push_back(temp);
					even.push(temp);
				}
			}
		}
		i++;
		if(i>=k-1)
			break;
		// cout<<"even size"<<i<<"\t"<<even.size()<<endl;
		
		// 踢第偶数次球
        	while(!even.empty())
		{
			p=even.front();
			even.pop();
			for(int j=0;j<6;j++)
			{
				if(j==p->val)
					continue;
				else
				{
					node * temp = new node(j);
					// p->next.push_back(temp);
					odd.push(temp);
				}
			}
		}
		i++;
	}
  
    	// 最后一层的特殊处理
	while(!even.empty())
	{
		p=even.front();
		even.pop();
		if(p->val!=0)
		{
			p->end = true;
			ret++;
		}
	}
	while(!odd.empty())
	{
		p=odd.front();
		odd.pop();
		if(p->val!=0)
		{
			p->end = true;
			ret++;
		}
	}
	return root;
}

// 第二种解法
// 递归解法。可以使用DP减少时间开销。这里为了展示思路采用递归解法。
// 同时，可以求出通项公式来最后达到O(1)时间求解的目的
int helper2(int k)
{
	// 两个base cases
	if(k==1)
		return 0;
	if(k==2)
		return 5;
	// 这里即分情况讨论
	// 即，第k-2次传球是传给A，还是A以外的人
	// 如果是传给A，第k-1次传给5种可能，最后传给A，即helper2(k-2)*5
	// 如果是传给A以外的人，那么相当于第k-1次传给除了A与第k-2次持球的人以外四个人
  	// 这个结果等同于helper2(k-1)*4
	return helper2(k-2)*5+helper2(k-1)*4;
}

int main()
{
	auto root = helper(10);
	cout<<ret<<endl;  // 模拟树BFS遍历，结果为1627605
	cout<<helper2(10)<<endl;  // 递归解法，结果同样是1627605
  
	// 这里我们可以尝试输出传球i次，球回到第一个孩子的所有的结果
	for(int i=1;i<=10;i++)
	{
		ret=0;
		helper(i);
		int ret2 = helper2(i);
		cout<<ret<<"\t"<<ret2<<endl;
	}
}


// 我能想到的解题思路：
// 1. 构造一颗11层的树，其中root为第一个持球的A孩子。然后每个节点包含除了自己以外的所有的5个孩子作为子节点。然后遍历树
// 2. 构造一个6个节点的完美图。在其中从A孩子出发进行BFS（可以走已经走过的节点），清点最后依旧抵达A孩子的所有路径数量
// 3. 利用队列来模拟树的遍历过程，从而减少空间开销。即上述代码中的helper（）函数
// 4. 递归算法，ans(n)=ans(n-2)*5+ans(n-1)*4。即上述的helper2()函数。具体思路详见helper2()函数中的注释
// 5. DP算法, 对上述递归算法的延伸。从而减少时间与空间开销。
// 6. 纯数学：求递归算法所需的递推公式的通项公式。求解过程类似于斐波那契数列，本质上是一个矩阵计算，即
// [F_n,         [0,1    [ F_{n-1} 
//  F_{n+1} ]  =  5,4 ]    F_{n} ]
  
// 这里设M =[0,1
//          5,4]
         
// 我们需要将M进行特征分解，求出特征值，最后计算出关于n的通项公式。
