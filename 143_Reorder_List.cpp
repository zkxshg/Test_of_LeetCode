// Can be reduced to O(n) based on recursion
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head && head->next) {
            ListNode * temp = head, * nex = head->next, * tail = nex;
            while (nex && nex->next) {
                while (tail->next->next) tail = tail->next;
            
                temp->next = tail->next;
                tail->next->next = nex;
                tail->next = NULL;
            
                temp = nex;
                nex = nex->next;
                tail = nex;
            }
        }
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
