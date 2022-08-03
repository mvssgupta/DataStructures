//*This is seems to be intersting
//*we should be provided by the reference to the node
//*which we should delete , we are not provided with the head node

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

//*here we have access to only to the right side of the reference
//*  1->2->6->8->9
//*for suppose we are asked to delete 6 then we should break the link
//*between 2 and 6 and we should make a link to 8 from 2 and then
//*using delete() operation delete 6


//*But it can done by simply coping the value of 8 to 6
//*simply break the link between 6->8
//*then it looks like 1->2->8->9
//*here another need to be done is we should link the new 8 to 9

void deleteNodeFromLL(Node *refToNode)
{
    Node* nextNode = refToNode->next;
    refToNode->val = nextNode->val;
    refToNode->next = refToNode->next->next;
    delete(nextNode);
}

int main()
{
    Node *third = new Node(6);
    Node *second = new Node(5, third);
    Node *first = new Node(4, second);
    Node *head = new Node(3, first);
    printLL(head);
    //*here I'm passing reference of node with value 5
    //*It means node with value 5 should be deleted
    deleteNodeFromLL(second);
    printLL(head);
    return 0;
}