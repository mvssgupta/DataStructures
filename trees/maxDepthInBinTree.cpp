#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" "<<x<<endl;
                                   
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x , TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//*height of a given binary tree using recursion
int maxDepthOfBinTree(TreeNode* root)
{
    if(root==NULL) return 0;
    return 1+ max(maxDepthOfBinTree(root->left),maxDepthOfBinTree(root->right));
}

int main()
{
    // ? Binary tree representation
                                   
    // !          3
    // !        /  \
    // !       4    5
    // !          /  \
    // !         8    6
    // !               \
    // !                7

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->right->right = new TreeNode(7);
    root->right->left = new TreeNode(8);
    int res = maxDepthOfBinTree(root);
    cout<<"Maximum depth of given binary tree is : "<<res<<endl;
    return 0;
}