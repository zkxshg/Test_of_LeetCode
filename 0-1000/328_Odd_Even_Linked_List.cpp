// Linked list
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode * tail = head, * odd = head, * even = head->next, * endL;
        
        while(tail->next) tail = tail->next;
        endL = tail;
        
        while(even->next) {
            odd->next = even->next;
            even->next = tail->next;
            tail->next = even;
            tail = tail->next;
            
            if (even == endL) break;
            odd = odd->next;
            if (odd == endL) break;
            even = odd->next;
        }
        return head; 
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
