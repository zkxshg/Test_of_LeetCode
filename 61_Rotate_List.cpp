// Two Pointers
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;
        int length = 1;
        ListNode * nex = head, * tail, * pre = head;
        while (nex->next) {
            nex = nex->next;
            length++;
        }
        k %= length;
        tail = nex;
        while (k > 0) {
            while (pre->next != tail) pre = pre->next;
            tail->next = head;
            head = tail;
            tail = pre;
            tail->next = NULL;
            pre = head;
            k--; 
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
