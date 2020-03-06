// examine if an sorted array in included in a binary search tree;


/************************************************
                                                  8
                                           /           \
                                          3             10
                                       /     \            \
                                      1       6            14
                                            /    \        /
                                         4         7     13

Input : array[] = {4, 6, 8, 14}
Input : array[] = {4, 6, 8, 12, 13}
*************************************************/
#include <iostream>
#include<vector>

using namespace std;

struct Node
{
    int val;
    Node * left;
    Node * right;
    Node(int x):val(x),left(NULL),right(NULL){};
    Node():val(0),left(NULL),right(NULL){};
};

vector<int> inOrder;

// a in-order dfs to traverse the binary search tree
void dfs(Node * root)
{
    if(root->left!=NULL)
        dfs(root->left);
    inOrder.push_back(root->val);
    if(root->right!=NULL)
        dfs(root->right);
}

bool ifContain(Node * root, vector<int>& arr)
{
    dfs(root);
//     for(int i=0;i<inOrder.size();i++)
//         cout<<inOrder[i]<<endl;
  
    int j=0;
    for(int i=0;i<arr.size();)
    {
        // cout<<i<<"\t"<<arr[i]<<"~~"<<j<<"\t"<<inOrder[j]<<endl;
        if(j>=inOrder.size())
            return false;
        if(arr[i]==inOrder[j])
        {
          i++;j++;
        }
        else if(arr[i]<inOrder[j])
        {
            return false;
        }
        else 
        {
            j++;
        }
    }
    return true;
}

// a dfs search without incurring extra space overheads
void dfs(Node * root, vector<int>& arr, int& offset, bool& flag)
{
    // cout<<arr[offset]<<"\t"<<root->val<<"\t"<<flag<<endl;
    if(offset >= arr.size())
        return;
    if(root->left!=NULL)
        dfs(root->left, arr, offset, flag);
    if(offset >= arr.size())
          return;
    if(arr[offset]==root->val)
        offset++;
    else if(arr[offset]<root->val)
        flag = false;
    if(offset >= arr.size())
          return;
    if(root->right!=NULL)
        dfs(root->right, arr, offset, flag);
}

// initialize the tree;
Node * init()
{
    // vector<int> tree = {8,3,10,1,6,-1,14,-1,-1,4,7,-1,-1,13,-1};
    Node * root  = new Node(8);
    // Node * p = new Node(3);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right  = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
    // dfs(root);
    return root;
    
}
int main()
{
    vector<int> arr = {1,6,10,13};
    Node * root = init();
    // first method
    cout <<ifContain(root, arr)<< endl;
  
    // second method
    bool flag = true;
    int offset = 0;
    dfs(root, arr, offset, flag);
    cout<<flag<<endl;
    return 0;
}
