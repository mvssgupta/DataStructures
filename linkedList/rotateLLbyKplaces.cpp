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

Node *rotateLLbyKplaces(Node *head , int k)
{
    int lenOfLL = 1;
    Node *dummy = head;
    while (dummy->next != NULL)
    {
        dummy = dummy->next;
        lenOfLL++;
    }
    dummy->next = head;

    //*here we only perform rotation if k is not a mutiple of length of LL 
    //*Why because if k is multiple of length of LL Then there is no need of rotation of LL
    if(k = k%lenOfLL) for (int i = 0; i < lenOfLL - (k % lenOfLL); i++) dummy = dummy->next;

    //*here we can see if K is multiple of Length of LL then the above loop will be skipped
    //*and simply we are returning the actual linkedlist head as our answer.
    //* (previously we store our actual LL head in dummy->next and if we skip 
    //* the above loop then it means we are simply returning the actual head since no need of rotation)    
    Node* newHead = dummy->next;      
    
    dummy->next = NULL;
    return newHead;
}

int main()
{
    Node *third = new Node(3);
    Node *second = new Node(4, third);
    Node *first = new Node(2, second);
    Node *head = new Node(1, first);
    printLL(head);
    int k=0;
    cout<<"Enter the value of K : ";
    cin>>k;
    head = rotateLLbyKplaces(head , k);
    printLL(head);
    return 0;
}