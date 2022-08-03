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

//*my intution is traversing the whole LL to find the length of the linkedlist
//*and then returning the middle node by dividing the length by 2 and adding 1 to it.
//*for example length = 5 then I should return (5/2)+1 = 2+1 = which means I have to return node 3
//*if length is even then for eg : length = 6 then (6/2)+1 = 3+1 = 4th node should be returned which is right middle node.
Node *findMiddleOfLL(Node *head)
{
    int len = 0;
    int count = 1;
    Node *traversingNode = head;
    while (traversingNode != NULL)
    {
        traversingNode = traversingNode->next;
        len++;
    }
    len = (len / 2) + 1;
    traversingNode = head;
    while (count != len)
    {
        traversingNode = traversingNode->next;
        count++;
    }
    return traversingNode;
}

//*here I'm using slow and fast pointers approach
//*In this approach we are using slow and fast pointer and pointing them to the head
//*here my intution is when the fast pointer reaches the end , the slow pointer will be at the middle
//*then I'm returning the slow pointer since it contains the middle element of the LL
Node *SandFptr(Node *head)
{
    Node *slowPtr = head;
    Node *fastPtr = head;
    while (fastPtr != nullptr && fastPtr->next != nullptr)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }
    return slowPtr;
}

int main()
{
    Node *third = new Node(6);
    Node *second = new Node(5, third);
    Node *first = new Node(4, second);
    Node *head = new Node(3, first);
    printLL(head);
    cout << "Using normal approach : " << endl;
    Node *middleNode1 = findMiddleOfLL(head);
    printLL(middleNode1);
    cout << "Using slow and fast pointer approach : " << endl;
    Node *middleNode2 = SandFptr(head);
    printLL(middleNode2);
    return 0;
}