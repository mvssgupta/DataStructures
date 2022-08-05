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

//*Also known as level order traversal
vector<vector<int>> BFStraversal(TreeNode *root)
{
    vector<vector<int>> res;
    if (root == NULL)
        return res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        int len = q.size();
        vector<int> levelTraversal;
        for (int i = 0; i < len; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left!=NULL)
                q.push(node->left);
            if (node->right!=NULL)
                q.push(node->right);
            levelTraversal.push_back(node->val);
        }
        res.push_back(levelTraversal);
    }
    return res;
}

int main()
{

    //? Binary tree representation

    //!             3
    //!          /    \
    //!         4      5
    //!       /  \   /  \
    //!      1   9  6    7

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(9);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    vector<vector<int>> res = BFStraversal(root);
    for (auto i : res)
    {
        for (auto j : i)
        {
            cout<<j<<" ";
        }
    }
    return 0;
}
