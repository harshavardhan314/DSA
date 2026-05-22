/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        map<ListNode*,int>mp;
        ListNode* temp1=headA;
        ListNode* temp2=headB;

        int len1=0;
        int len2=0;
        while(temp1!=NULL){
            len1++;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            len2++;
            temp2=temp2->next;
        }
        temp1=headA;
        if(len1>len2){
            int d=len1-len2;
            for(int i=0;i<d;i++){
                temp1=temp1->next;
            }
        }
        temp2=headB;
        if(len2>len1){
            int d=len2-len1;
            for(int i=0;i<d;i++){
                temp2=temp2->next;
            }
        }
        while(temp1!=NULL && temp2!=NULL){
            if(temp1==temp2){
                return temp1;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return NULL;
    }
};