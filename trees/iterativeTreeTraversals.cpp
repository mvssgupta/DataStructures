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

//*time complexity : O(n)
//*space complexity : O(n) since we are using a stack  
vector<int> IterativePreOrderTraversal(TreeNode *root)
{
    vector<int> preOrder;
    if (!root)
        return preOrder;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        root = st.top();
        st.pop();
        preOrder.push_back(root->val);
        if (root->right)
            st.push(root->right);
        if (root->left)
            st.push(root->left);
    }
    return preOrder;
}

//*time complexity : O(n)
//*space complexity : O(n) since we are using a stack  
vector<int> IterativeInOrderTraversal(TreeNode *root)
{
    vector<int> InOrder;
    stack<TreeNode *> st;
    TreeNode *node = root;
    while (true)
    {
        if (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty())
                break;
            node = st.top();
            InOrder.push_back(node->val);
            st.pop();
            node = node->right;
        }
    }
    return InOrder;
}

int main()
{
    // ? Binary tree representation

    //!             1
    //!          /    \
    //!         2      3
    //!       /  \   /  \
    //!      4   5  6    7
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    cout << "Iterative method of Pre-Order Traversal : ";
    vector<int> ans = IterativePreOrderTraversal(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Iterative method of In-Order Traversal : ";
    vector<int> InOrder = IterativeInOrderTraversal(root);
    for (auto i : InOrder)
    {
        cout << i << " ";
    }
    return 0;
}