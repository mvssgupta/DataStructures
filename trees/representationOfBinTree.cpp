#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " " << x << endl;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

void InOrderRepresentation(Node *root)
{
    if (root != NULL)
    {
        InOrderRepresentation(root->left);
        cout << root->val << " ";
        InOrderRepresentation(root->right);
    }
}

void PreOrderRepresentation(Node *root)
{
    if (root != NULL)
    {
        cout << root->val << " ";
        PreOrderRepresentation(root->left);
        PreOrderRepresentation(root->right);
    }
}

void PostOrderRepresentation(Node *root)
{
    if (root != NULL)
    {
        PostOrderRepresentation(root->left);
        PostOrderRepresentation(root->right);
        cout << root->val << " ";
    }
}

int main()
{

    //? Binary tree representation

    //!        1
    //!      /  \
    //!     2    3
    //!   /  \  / \
    //! 4    5 6   7

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout << "PreOrder Representation of the given tree is : " << endl;
    PreOrderRepresentation(root);
    cout << endl;
    cout << "Inorder Representation of the given tree is : " << endl;
    InOrderRepresentation(root);
    cout << endl;
    cout << "PostOrder Representation of the given tree is : " << endl;
    PostOrderRepresentation(root);
    cout << endl;
    return 0;
}