//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    
    Node* getMid(Node *head){
        Node* slow=head;
        Node* fast=head->next;
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    Node* reverse(Node* mid) {
        if (!mid || !(mid -> next)) {
            return mid;
        }
        Node* node = reverse(mid -> next);
        mid-> next -> next = mid;
        mid -> next = NULL;
        return node;
    }
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node* head)
    {
        if(head->next==NULL){
            return true;
        }
        
        Node* mid=getMid(head);
        mid->next= reverse(mid->next);
        
        if(mid->next==NULL){
            if(head->data==mid->data && head->next==mid){
                return true;
            }
        }
        Node* temp=mid->next;
        
        while(temp!=NULL){
            if(head->data!=temp->data){
                return false;
            }
            head=head->next;
            temp=temp->next;
        }
        
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends