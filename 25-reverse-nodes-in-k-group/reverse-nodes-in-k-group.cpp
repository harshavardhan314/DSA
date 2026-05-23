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
ListNode* reverse(ListNode* st,ListNode* prev){
    while(st!=NULL){
        ListNode* next_node=st->next;
        st->next=prev;
        prev=st;
        st=next_node;
    }
    return prev;

}
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {


        if(head==NULL || head->next==NULL){
            return head;
        }
        int cnt=1;
        ListNode* temp=head;
        ListNode* answer=head;
        ListNode* group_started=head;
        ListNode* prev_node=head;
        while(temp!=NULL){

            if(cnt==k){
                ListNode* next_node=temp->next;
                temp->next=NULL;
                if(group_started==head){
                    answer=reverse(group_started,NULL);
                    prev_node=group_started;
                }
                else{
                    ListNode* curr=reverse(group_started,NULL);
                    prev_node->next=curr;
                    prev_node=group_started;
                    
                }

                group_started->next=next_node;
                temp=next_node;
                cnt=1;
            }
            if(cnt==1){
                group_started=temp;
            }
            cnt++;
            if(temp==NULL) break;
            temp=temp->next;
        }
        return answer;
    }
};