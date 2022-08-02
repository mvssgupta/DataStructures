#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " " << x << endl;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = nullptr;
    }

    Node(int val)
    {
        data = val;
        next = nullptr;
    }

    Node(int val, Node *nextLink)
    {
        data = val;
        next = nextLink;
    }
    /*
    short way :-
     Node(): data(0),next(nullptr) {}
     Node(int val): data(val),next(nullptr) {}
     Node(int val, Node* nextLink): data(0),next(nextLink) {}
    */
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

int main()
{
    Node *second = new Node(5);
    Node *first = new Node(4, second);
    Node *head = new Node(3, first);

    printLL(head);

    return 0;
}