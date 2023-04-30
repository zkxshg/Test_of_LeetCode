// https://leetcode.com/problems/insertion-sort-list/
// Two points: pre->head, tail
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode * pre = new ListNode(-1);
        pre->next = head;
        
        ListNode * temp = head->next, * tail = head, * nex;
        
        while (temp) {
            if (head->val >= temp->val) {
                pre->next = temp;
                tail->next = temp->next;
                temp->next = head;
                head = temp; 
            }
            else if (tail->val <= temp->val) tail = temp;
            else {
                nex = head;
                while (temp->val > nex->next->val) nex = nex->next;
                tail->next = temp->next;
                temp->next = nex->next;
                nex->next = temp;
            }
            temp = tail->next;
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
