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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1==NULL && list2==NULL)return NULL;
        
        ListNode *first_ptr=list1;
        ListNode *second_ptr=list2;
        
        if(first_ptr==NULL){
            return second_ptr;
        }
        else if(second_ptr==NULL){
            return first_ptr;
        }
        
        ListNode *dummy_node= new ListNode(-1);
        ListNode *temp=dummy_node;
        while(first_ptr!=NULL && second_ptr!=NULL){
            if(first_ptr->val<=second_ptr->val){

                temp->next=first_ptr;
                temp=first_ptr;
                first_ptr=first_ptr->next;
            }
            else{
                temp->next=second_ptr;
                temp=second_ptr;
                second_ptr=second_ptr->next;
            }
        }
        if(first_ptr==NULL)temp->next=second_ptr;
        else if(second_ptr==NULL)temp->next=first_ptr;
        return dummy_node->next;
    }
};