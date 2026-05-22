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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head==NULL)return NULL;
        ListNode* dummy=new ListNode(-1);

        int len=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            len++;
        }
       
        k=k%len;
        if(k==0){
            return head;
        }
        int pos=len-k;
        int node_pos=1;
        temp=head;
        while(node_pos<pos){
            temp=temp->next;
            node_pos++;
        }
        ListNode* next_node=temp->next;
        temp->next=NULL;
        temp=next_node;
        dummy->next=temp;
        while(temp!=NULL && temp->next!=NULL){
            temp=temp->next;
        }
        if(temp!=NULL)
        temp->next=head;
        return dummy->next;


        
    }
};