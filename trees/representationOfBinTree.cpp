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
        InOrderRepresentation(root->left);
        InOrderRepresentation(root->right);
    }
}

void PostOrderRepresentation(Node *root)
{
    if (root != NULL)
    {
        InOrderRepresentation(root->left);
        InOrderRepresentation(root->right);
        cout << root->val << " ";
    }
}

int main()
{

    //? Binary tree representation

    //!     3
    //!    / \
    //!   4   5

    Node *root = new Node(3);
    root->left = new Node(4);
    root->right = new Node(5);
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