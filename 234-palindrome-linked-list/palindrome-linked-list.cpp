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

ListNode* reverse(ListNode*middle){

    ListNode* prev=NULL;
    ListNode* temp=middle;
    while(temp!=NULL){
        ListNode* next_node=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next_node;
    }
    return prev;
}
class Solution {
public:
    bool isPalindrome(ListNode* head) {

        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast !=NULL && fast->next!=NULL){
           
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* back=reverse(slow);
        ListNode* front=head;
        while(back!=NULL){
            if(front->val!=back->val){
                return false;
            }
            front=front->next;
            back=back->next;
        }
        return true;
        
        
    }
};