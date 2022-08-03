#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " " << x << endl;
struct Node
{
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};
void printLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

//*Time complexity : O(length(firstLL) + length(secondLL));
//*space complexity : O(1)
Node* mergeTwoLL(Node *head1, Node *head2)
{

    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    if (head1->val > head2->val)
        swap(head1, head2);
    Node *res = head1;
    while (head1 != NULL && head2 != NULL)
    {
        Node *temp = NULL;
        while (head1 != NULL && head1->val <= head2->val)
        {
            temp = head1;
            head1 = head1->next;
        }
        temp->next = head2;
        swap(head1, head2);
    }
    return res;
}

int main()
{
    Node *third1 = new Node(10);
    Node *second1 = new Node(8, third1);
    Node *first1 = new Node(4, second1);
    Node *head1 = new Node(3, first1);
    printLL(head1);
    
    Node *second2 = new Node(9);
    Node *first2 = new Node(7, second2);
    Node *head2 = new Node(5, first2);
    printLL(head2);

    Node*head = mergeTwoLL(head1,head2);

    printLL(head);

    return 0;
}