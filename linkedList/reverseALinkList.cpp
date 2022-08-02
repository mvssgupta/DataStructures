#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " " << x << endl;

struct Node
{
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(0), next(next) {}
};

Node *reverseLinkedList(Node *head)
{
    Node *dummyNode = NULL;
    while (head != NULL)
    {
        Node* next = head->next;
        head->next = dummyNode;
        dummyNode = head;
        head = next;
    }
    return dummyNode;
}
void printLL(Node* head){
    while(head != NULL){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}
int main()
{
    Node* head = new Node(5);
    head->next = new Node(4);
    head->next->next = new Node(3);
    printLL(head);
    head = reverseLinkedList(head);
    printLL(head);
    return 0;
}