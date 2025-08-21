// Recursively reverse: if (!(node->next)) return node; istNode* nex = reverseLink(node->next); 
// nex->next = node; return node;
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
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        if (!(head->next)) return head;
      
        ListNode* last = head;
        while (last->next) last = last->next;
        
        ListNode* first = reverseLink(head);
        first->next = NULL;
        
        return last;
    }
    ListNode* reverseLink(ListNode* node){
        if (!(node->next)) return node;
        ListNode* nex = reverseLink(node->next);
        nex->next = node;
        return node;
    }
};
