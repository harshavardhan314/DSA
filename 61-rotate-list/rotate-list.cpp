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

ListNode* find_last_node(ListNode * head,int pos){
    int cnt=1;
    while(head!=NULL){
        if(cnt==pos){
            return head;
        }
        head=head->next;
        cnt++;
    }
    return NULL;
}
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head==NULL) return head;

        ListNode* temp=head;
        int len=1;
        while(temp->next!=NULL){
            len++;
            temp=temp->next;

        }
        k=k%len;
        if(k==0)return head;

        ListNode* last_node=find_last_node(head,len-k);
        temp->next=head;
        head=last_node->next;
        last_node->next=NULL;
        return head;

        
    }
};