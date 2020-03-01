# Recursive for link list:
# if (n1->val <= n2->val){ if (mergeLk(n1->next, n2) == 2) n1->next = n2; return 1; }
# else { if (mergeLk(n1, n2->next) == 1) n2->next = n1; return 2; }
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == 0) return l2;
        else if (l2 == 0) return l1;
        int first = mergeLk(l1, l2);
        if (first == 1) return l1;
        else return l2;
    }
    int mergeLk(ListNode* n1, ListNode* n2){
        if (!(n1->next) && !(n2->next))
        {
            if (n1->val <= n2->val) {
                n1->next = n2;
                return 1;
            } 
            else {
                n2->next = n1;
                return 2;
            } 
        }
        
        if (!(n1->next)) {
            if (n1->val <= n2->val) {
                n1->next = n2;
                return 1;
            }   
            else if (mergeLk(n1, n2->next) == 1){
                n2->next = n1;
            }
            return 2;
        }
        
        if (!(n2->next)) {
            if (n1->val >= n2->val) {
                n2->next = n1;
                return 2;
            }   
            else if (mergeLk(n1->next, n2) == 2){
                n1->next = n2;
            }
            return 1;
        }
        
        if (n1->val <= n2->val){
            if (mergeLk(n1->next, n2) == 2) n1->next = n2;
            return 1;
        }
        else {
            if (mergeLk(n1, n2->next) == 1) n2->next = n1;
            return 2;
        }
    }
};
