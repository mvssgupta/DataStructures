#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " " << x << endl;

struct Node
{
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

void printLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* removeNthNode(Node* head,int nthNode){
    int count=1;
    Node* dummyNode = NULL;
    if(nthNode==1){
        dummyNode = head;
        head = head->next;
        delete(dummyNode);
    }
    else{
        dummyNode = head;
        Node* deletedNode = NULL;
        while(count<nthNode-1){
            dummyNode = dummyNode->next;
            count++;
        }
        deletedNode = dummyNode->next;
        dummyNode->next = dummyNode->next->next;
        delete(deletedNode);
    }
    return head;
}

int main()
{
    Node *third = new Node(6);
    Node *second = new Node(5,third);
    Node *first = new Node(4, second);
    Node *head = new Node(3, first);
    printLL(head);
    head = removeNthNode(head,4);
    printLL(head);
    return 0;
}