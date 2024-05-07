// https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/?envType=daily-question&envId=2024-05-07
// link List

class Solution {
public:
    int recur(ListNode* head) {
        int v = head->val * 2;

        if (head->next) v += recur(head->next);

        head->val = v % 10;

        return v / 10;
    }

    ListNode* doubleIt(ListNode* head) {
        int h = recur(head);

        if (h > 0) {
            ListNode* H = new ListNode(1);
            H->next = head;
            return H;
        }

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
