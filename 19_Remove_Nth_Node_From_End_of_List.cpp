// Two Pointers
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || n < 1) return head;
        if (!head->next)  return head->next;

        ListNode* temp = head, * nex = head->next;
        while (n > 1) {
            nex = nex->next;
            n--;
        }
        if (!nex) return head->next;
        
        while (nex->next) {
            nex = nex->next;
            temp = temp->next;
        }
        temp->next = temp->next->next;
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
