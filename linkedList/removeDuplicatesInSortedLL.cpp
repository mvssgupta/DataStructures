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

//*It is used to remove duplicated in sorted linkedList

//*here the intution is if any two adjacent linked list nodes->values are same then the 
//*current node's next property(which means link of current node) value will be set to next non duplicate node 

//*for example consider the following linkedlist :-
//* 1->2->2->4
//* here number 2 is occured two times , so we have to remove it.
Node* removeDuplicatesFromSortedLL(Node* head)
{
    Node* currentNode = head ;   //*this node it pointing to the current node in the linkedlist , initially set to head of LL
    Node* nextNode = head->next;  //*this node it pointing to the current's next node in the linkedlist , initially set to head's next of LL
    int currNodeVal = currentNode->val;  //*this variable is to check whether the values in the consequent nodes are same or not
    while(nextNode)
    {
        if(currentNode->val!=nextNode->val)  //*if you found that the adjacent nodes values are not same then perform the following steps
        {
            currentNode->next = nextNode;   //*assign the next node reference to current->next
            currNodeVal = nextNode->val;    //*change the variable value , since we need to find the remaining duplicates if any occurs in furthur
            currentNode = currentNode->next; //*move the current node one step forward
        }
        nextNode = nextNode->next;    //*if the adjacent nodes values are same then just move the nextNode forward 
    }
    currentNode->next = NULL;
    return head;
}

int main()
{
    Node *third = new Node(5);
    Node *second = new Node(2, third);
    Node *first = new Node(2, second);
    Node *head = new Node(3, first);
    printLL(head);
    head = removeDuplicatesFromSortedLL(head);
    printLL(head);
    return 0;
}