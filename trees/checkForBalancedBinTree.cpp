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
 * for a balanced binary tree the follow applies:
 * for every node :- height(left->subtree) - height(right->subtree) <= 1
 */

int heightOfBinTree(TreeNode *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(heightOfBinTree(root->left), heightOfBinTree(root->right));
}

//*time complexity: O(n)*O(n) = O(n^2)
//*since we are checking for everynode by using the height function(it is taking the extra O(n)time)
//*so we have to optimise this in our optimised solution

/// brute force approach
bool balancedBinaryTree(TreeNode *root)
{
    /// if node it null then it means it is balanced
    if (root == NULL)
        return true;

    /// if difference in height is greater than one then the tree is not balanced
    if (abs(heightOfBinTree(root->left) - heightOfBinTree(root->right)) > 1)
        return false;

    /// if any subtree is not balanced then that means that whole tree is not balanced
    if (!balancedBinaryTree(root->left) || !balancedBinaryTree(root->right))
        return false;

    /// finally if the above two cases satisfies which means
    /// all the subtrees are balanced then we have to return true
    return true;
}

/*
 *the intution for the optimised solution is :-
 *we are going to make a function which will give us
 * height of the tree if it is balanced binary tree
 * or it will return -1 incase of it is not a balanced binary tree
*/

int heightOrBoolBinTree(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int leftHeight = heightOrBoolBinTree(root->left);
    int rightHeight = heightOrBoolBinTree(root->right);
    if (leftHeight == -1 || rightHeight == -1)
        return -1;
    if (abs(leftHeight - rightHeight) > 1)
        return -1;
    return 1 + max(leftHeight, rightHeight);
}

//*this is the function which is used to check whether the given tree is balanced or not
bool isBalancedBinaryTree(TreeNode* root)
{
    return heightOrBoolBinTree(root)!=-1;
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
    if (bool(isBalancedBinaryTree(root)))
        cout << "Given binary tree is balanced" << endl;
    else
        cout << "Given binary tree is not balanced" << endl;
    return 0;
}