// generate a binary search tree

struct Node
{
	int val;
  Node * left;
  Node * right;
  Node(int x):val(x),left(NULL),right(NULL){};
  Node():val(0),left(NULL),right(NULL){};
};

void helper(Node * root, int& x)
{
	if(root->val>x)
  {
  	if(root->left==NULL)
    	root->left = new Node(x);
    else{
    	helper(root->left, x);
    }
  }
  else
  {
  	if(root->right==NULL)
			root->right = new Node(x);
    else
    	helper(root->right, x);
  }
}

Node * generateBinaryTree(vector<int>& nums)
{
	if(nums.empty())
  	return NULL;
  Node * root = new Node(nums[0]);
  for(int i=1;i<nums.size();i++)
  {
  	helper(root, nums[i]);
  }
	return root;
}
