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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * prev=head;
        ListNode * curr=head;

        int len=0;
        ListNode * temp=head;
        while(temp!=NULL){
            temp=temp->next;
            len++;
        }

        int want_to_delete=len-n;
        if(want_to_delete==0){
            return head->next;
        }    
        while(want_to_delete>0){
            prev=curr;
            curr=curr->next;
            want_to_delete--;
        }
        prev->next=curr->next;
        delete(curr);
        return head;

        
    }
};