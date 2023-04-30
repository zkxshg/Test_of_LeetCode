// linear scan: if ((n1->next->val) == val) n1->next = n1->next->next;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;
        
        while ((head->val) == val) {
            head = head->next;
            if(!head) return head;
        }
        ListNode* n1 = head;
        
        while (n1->next){
            if ((n1->next->val) == val) n1->next = n1->next->next;
            else n1 = n1->next;
        }
        return head;
    }
};
