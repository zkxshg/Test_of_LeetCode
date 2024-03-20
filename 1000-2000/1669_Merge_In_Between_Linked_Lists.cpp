// https://leetcode.com/problems/merge-in-between-linked-lists/?envType=daily-question&envId=2024-03-20
// Linked List

class Solution {
public:
    #define LN ListNode

    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        LN* l2end = list2;
        while (l2end->next) l2end = l2end->next;

        LN* pre = list1; LN* nex = list1->next; int cou = 1;
        
        while (cou < a) {
            pre = nex; nex = pre->next; cou++;
        }
        pre->next = list2;

        while (cou <= b) {
            pre = nex; nex = pre->next; cou++;
        }
        l2end->next = nex;

        return list1;
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
