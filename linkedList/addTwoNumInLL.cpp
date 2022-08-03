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

int lengthOfLL(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        head = head->next;
        count++;
    }
    return count;
}


Node* addTwoNumbersInLL(Node *head1, Node *head2)
{
    Node *dummy = new Node();
    Node *temp = dummy;
    int carry = 0;
    while ((head1 != NULL || head2 != NULL) || carry)
    {
        int sum = 0;
        if (head1 != NULL)
        {
            sum += head1->val;
            head1 = head1->next;
        }

        if (head2 != NULL)
        {
            sum += head2->val;
            head2 = head2->next;
        }

        sum += carry;
        carry = sum / 10;
        Node *node = new Node(sum % 10);
        temp->next = node;
        temp = temp->next;
    }
    return dummy->next;
}
int main()
{
    Node *third1 = new Node(8);
    Node *second1 = new Node(3,third1);
    Node *first1 = new Node(4, second1);
    Node *head1 = new Node(2, first1);
    printLL(head1);
    
    Node *second2 = new Node(4);
    Node *first2 = new Node(6, second2);
    Node *head2 = new Node(5, first2);
    printLL(head2);

    Node* newNode = addTwoNumbersInLL(head1,head2);
    printLL(newNode);
    return 0;
}