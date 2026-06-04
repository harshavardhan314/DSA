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
ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (l1 && l2) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    tail->next = (l1 ? l1 : l2);

    return dummy.next;
}
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return NULL;

    ListNode* prev = lists[0];

    for (int i = 1; i < lists.size(); i++) {
        prev = merge(prev, lists[i]);
    }

    return prev;
}
};