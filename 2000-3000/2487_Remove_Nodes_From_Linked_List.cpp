// https://leetcode.com/problems/remove-nodes-from-linked-list/?envType=daily-question&envId=2024-05-06
// recursion

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if (!head->next) return head;

        ListNode* nex = removeNodes(head->next);

        if (nex->val > head->val) return nex;
        
        head->next = nex;
        return head;
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
