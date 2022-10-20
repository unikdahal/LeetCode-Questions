//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
   public:
   Node*reverse(Node*head){
       Node*prev=NULL,*nex=NULL,*curr=head;
       while(curr!=NULL){
           nex=curr->next;
           curr->next=prev;
           prev=curr;
           curr=nex;
       }
       return prev;
   }
   //Function to add two numbers represented by linked list.
   struct Node* addTwoLists(struct Node* first, struct Node* second)
   {
       first=reverse(first);
       second=reverse(second);
       Node*curr=NULL,*res=NULL,*t;
       int s=0;
       int c=0;
       while(first!=NULL or second!=NULL){
           s=c+(first?first->data:0)+(second?second->data:0);
           c=(s>=10)?1:0;
           s=s%10;
           t=new Node(s);
           if(res==NULL)res=t;
           else curr->next=t;
           curr=t;
           if(first)first=first->next;
           if(second)second=second->next;
       }
       if(c>0){
           t=new Node(c);
           curr->next=t;
       }
       res=reverse(res);
       return res;
   }
};;

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends