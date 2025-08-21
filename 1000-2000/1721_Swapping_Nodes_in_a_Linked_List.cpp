// two pointers
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* f2th = head; ListNode* l2th = head;
        
        for (int i = 1; i < k; i++) f2th = f2th->next;
        
        ListNode* nex = f2th;
        while (nex->next) {
            nex = nex->next; l2th = l2th->next;  
        }
        
        int tem = f2th->val; f2th->val = l2th->val; l2th->val = tem;
        
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
