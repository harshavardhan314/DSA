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
ListNode* find_middle(ListNode* head){
    ListNode* slow=head;
    ListNode* fast=head;
    ListNode* prev=head;
    while(fast!=NULL && fast->next!=NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    return prev;

}
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
    

    if(head==NULL || head->next==NULL){
        return NULL;
    }

    ListNode* middle=find_middle(head);
    ListNode* next_node=middle->next;
    middle->next=middle->next->next;
    delete(next_node);
    return head;
    }
};