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
    vector<int> arr = {1,6,10,12};
    Node * root = init();
    cout <<ifContain(root, arr)<< endl;
    return 0;
}

