/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

int traverse(ListNode* head){
    ListNode* temp=head;
    
    int count=0;
    while(temp->next!=NULL){
        count++;
        temp=temp->next;
    }
    return count+1;
    
}

void deletemiddle(ListNode* head,int count){
    int i=1;
    ListNode* temp=head;
    ListNode* temp1=head->next;
    while(i!=count/2 ){
        temp=temp1;
        temp1=temp1->next;
        i++;
    }
    
    temp->next=temp1->next;

}


class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        
        int count=traverse(head);
        if(count==1){
            return NULL;
        }
        
        deletemiddle(head,count);
        
        return head;
        
        
        
    }
};