// Two pointers
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode * pre = new ListNode(-1);
        pre->next = head;
        ListNode * nex = pre;
        int dupV = 0;
        while (nex->next) {
            if (nex->next->next && nex->next->val == nex->next->next->val) {
                dupV = nex->next->val;
                while (nex->next && nex->next->val == dupV) nex->next = nex->next->next;
            } else nex = nex->next;
        }
        return pre->next;
    }
};

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
