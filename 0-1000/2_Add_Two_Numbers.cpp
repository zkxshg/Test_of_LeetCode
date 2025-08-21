// ListNode temp(1) <- false; ListNode *l3 = new ListNode(1) <- right;
//  if (!(l1n->next) && l2 && l2->next){ l1n->next = l2->next; l2->next = NULL;}
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        
        ListNode* l1n = l1;
        bool add1 = false;
        int sum = 0;
        if (!(l1n->next) && l2->next){
            l1n->next = l2->next;
            l2->next = NULL;
        }
        
        while(l1n->next){
            sum = l1n->val;
            if (l2) sum += l2->val;
            if (add1) sum += 1;
            add1 = false;
            if (sum > 9){
                sum = sum % 10;
                add1 = true;
            }
            l1n->val = sum;
            l1n = l1n->next;
            if (l2) l2 = l2->next;
            if (!(l1n->next) && l2 && l2->next){
                l1n->next = l2->next;
                l2->next = NULL;
            }
        }
        
        sum = 0;
        if (l1n) sum += l1n->val;
        if (l2) sum += l2->val;
        if(add1) sum += 1;
        add1 = false;
        if (sum > 9){
            sum = sum % 10;
            add1 = true;
        }
        l1n->val = sum;
        if (add1){
            ListNode *l3 = new ListNode(1);
            l1n->next = l3;
        } 
        return l1;
    }
};
