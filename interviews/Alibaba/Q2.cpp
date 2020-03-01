#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int ret;
struct node{
	vector<node*> next;
	int val;
	bool end;
	node(int x):val(x),end(false){};
};
node * helper(int k)
{
	node * root = new node(0);
	node * p = root;
	queue<node*> odd;
	queue<node*> even;
	odd.push(root);
	for(int i=0;i<k-1;)
	{
		//cout<<"odd size"<<i<<"\t"<<odd.size()<<endl;
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
					// p->next.push_back(temp);
					even.push(temp);
				}
			}
		}
		i++;
		if(i>=k-1)
			break;
		// cout<<"even size"<<i<<"\t"<<even.size()<<endl;
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

int helper2(int k)
{
	if(k==1)
		return 0;
	if(k==2)
		return 5;
	return helper2(k-2)*5+helper2(k-1)*4;
}
int main()
{
	auto root = helper(10);
	cout<<ret<<endl;
	cout<<helper2(10)<<endl;
	for(int i=1;i<=10;i++)
	{
		ret=0;
		helper(i);
		int ret2 = helper2(i);
		cout<<ret<<"\t"<<ret2<<endl;
	}
}
