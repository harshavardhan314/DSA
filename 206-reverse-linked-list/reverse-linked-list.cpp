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
 ListNode* reverse(ListNode* prev,ListNode* temp,ListNode* front){
    
    if(temp==NULL) return prev;

            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
            return reverse(prev,temp,front);

 }
class Solution {

public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* temp=head;
        ListNode* front=head;
        // while(temp!=NULL){
        //     front=temp->next;
        //     temp->next=prev;
        //     prev=temp;
        //     temp=front;
        // }
        return reverse(prev,temp,head);
        
    }
};