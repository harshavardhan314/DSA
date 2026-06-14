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
    int pairSum(ListNode* head) {
        stack<int>st;
        ListNode* temp=head;
        while(temp!=NULL){
            st.push(temp->val);
            temp=temp->next;
        }
        int n=st.size();
        int half=n/2;
        temp=head;
        int ans=0;
        while(st.size()>half){
            ans=max(ans,temp->val+st.top());
            st.pop();
            temp=temp->next;

        }
        return ans;

    }
};