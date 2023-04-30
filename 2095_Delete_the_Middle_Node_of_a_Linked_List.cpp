// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
// LinkedList

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head->next) return NULL;
        
        ListNode* sp1 = head; ListNode* sp2 = head; ListNode* sp1Pre = head;
        
        while (sp2->next) {
            sp1Pre = sp1;
            sp1 = sp1->next;
            
            sp2 = sp2->next;
            if (sp2->next) sp2 = sp2->next;
        }
        
        sp1Pre->next = sp1->next;
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
