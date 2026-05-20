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
        ListNode *new_list=new ListNode(0);
        if( list1==NULL){
            new_list->val=list2->val;
            list2=list2->next;
        }
        else if(list2==NULL){
            new_list->val=list1->val;
            list1=list1->next;
        }
        else{
            if(list1->val<list2->val){
                new_list->val=list1->val;
                list1=list1->next;
            }
            else{
                new_list->val=list2->val;
                list2=list2->next;
            }
        }
        ListNode *prev=new_list;
        while(list1!=NULL && list2!=NULL){
            if(list1->val<list2->val){
                ListNode *temp=new ListNode(list1->val);
                list1=list1->next;
                prev->next=temp;
                prev=temp;
            }
            else{
                ListNode *temp=new ListNode(list2->val);
                list2=list2->next;
                prev->next=temp;
                prev=temp;
            }
            
        }
        while(list1!=NULL){
            ListNode *temp=new ListNode(list1->val);
                list1=list1->next;
                prev->next=temp;
                prev=temp;

        }
        while(list2!=NULL){
            ListNode *temp=new ListNode(list2->val);
                list2=list2->next;
                prev->next=temp;
                prev=temp;

        }
        prev->next=NULL;
        return new_list;
        
    }
};