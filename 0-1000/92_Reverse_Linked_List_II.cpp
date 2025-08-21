// Recursively reverse + set start / end position
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head) return head;
        if (!(head->next)) return head;
        if (m == n) return head;
        
        ListNode* before = head;
        ListNode* after = head;
        
        for(int i = 1; i < n; i++){
            if(i == m - 1) before = after;
            after = after->next;
        }
        
        ListNode* endp = after;
        after = after->next;
        endp->next = NULL;
        
        if (m == 1){
            before = reverseLink(before);
            before->next = after;
            return endp;
        }
        
        ListNode* startp = before->next;
        startp = reverseLink(startp);
        startp->next = after;
        before->next = endp;
        
        return head;
    }
     ListNode* reverseLink(ListNode* node){
        if (!(node->next)) return node;
        ListNode* nex = reverseLink(node->next);
        nex->next = node;
        return node;
    }
};
