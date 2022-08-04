#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" "<<x<<endl;
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

//*here we are just pushing the values into a vector and checking whether it is palindrome or not
//* It takes a space complexity of O(length(vector)) since we are using a vector to store the values of nodes of linkedlist
bool checkLLPalindrome(Node *head)
{
    vector<int> v;
    while(head != NULL)
    {
        v.push_back(head->val);
        head = head->next;
    }
    for(int i=0;i<v.size()/2;i++)
    {
        if(v[i]!=v[v.size()-i-1]) return false;
    }
    return true;
}

//*Optimized solution
//*The intution is find the mid point of the linkedlist and the break the ll in to two parts
//*and then reverse the second part and then compare it with the first part of ll
//*if it matches return true else false

bool checkLLpalindromeOptSol(Node* head)
{
    Node* slowPtr = head, *fastPtr = head->next;
    while(fastPtr!=NULL && fastPtr->next!=NULL)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }
    fastPtr = slowPtr->next;
    slowPtr->next = NULL; //*breaking the linked list into two halves

    //*now we have to reverse the second half
    fastPtr = reverseLinkedList(fastPtr);

    //*checking whether the given LL is palindrome or not
    while(fastPtr!=NULL)
    {
        if(fastPtr->val!=head->val) return false;
        fastPtr = fastPtr->next;
        head = head->next;
    }
    if(fastPtr==NULL) return true;
    return false;
}

int main()
{
    Node *third = new Node(3);
    Node *second = new Node(4, third);
    Node *first = new Node(4, second);
    Node *head = new Node(3, first);
    (checkLLPalindrome(head))?(cout<<"Given linkedList is Palindrome"<<endl):(cout<<"Given linkedList is not a Palindrome"<<endl);
    (checkLLpalindromeOptSol(head))?(cout<<"Given linkedList is Palindrome"<<endl):(cout<<"Given linkedList is not a Palindrome"<<endl);
    return 0;
}