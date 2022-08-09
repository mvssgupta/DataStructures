#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " " << x << endl;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
*   diameter of a Binary tree:- the largest path between any two nodes
*   note :- the path doesn't need to pass to through the root


*   eg:- 1:        3
*                /  \    the largest distance is between 4 and 5 it is 2.
*               4    5


*  eg:- 2:         3
*                /   \
*               4     5     Here the largest distance is between 10 and 11 , it is 6.
*                    / \            here the largest distance path not passed through the root
*                   6   7
*                  /     \
*                 8       9
*                /         \
*               10         11
*/

/// brute force approach

///here we are iterating through each and every element 
/// and we are calculating the maximum value.

int maxi = INT_MIN;
int heightOfBinTree(TreeNode *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(heightOfBinTree(root->left), heightOfBinTree(root->right));
}

/// here it takes O(n^2) time complexity .
int getDiameterBruteForceApproach(TreeNode *root)
{
    if (root == NULL)
        return 0;
    maxi = max(maxi, 1 + (heightOfBinTree(root->left) + heightOfBinTree(root->right)));
    return maxi;
}


//*optimised solution:-
//*time complexity:o(n)

int heightOfBinTreeOpt(TreeNode* root,int &maxi1)
{
    if(root==NULL) return 0;
    maxi1 = max(maxi1 , heightOfBinTreeOpt(root->left,maxi1)+heightOfBinTreeOpt(root->right,maxi1));
    return 1+ max(heightOfBinTreeOpt(root->left,maxi1),heightOfBinTreeOpt(root->right,maxi1));
}

int diameterOfBinTree(TreeNode* root)
{
    int diameter = 0;
    heightOfBinTreeOpt(root,diameter);
    return diameter;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->left->left = new TreeNode(8);
    root->right->left->left->left = new TreeNode(10);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(9);
    root->right->right->right->right = new TreeNode(11);
    cout<<getDiameterBruteForceApproach(root)<<endl;
    cout<<diameterOfBinTree(root)<<endl;
    return 0;
}