// x = 3; 
// case-nex >= x: preh -> 1 -> 2/pre -> 4/now -> 5/nex -> 2 ->3;
// case-nex <  x: preh -> 1 -> 2/pre -> 4 -> 5/now -> 2/nex ->3;
//                preh -> 1 -> 2 -> 2/pre -> 4 -> 5/now -> 3/nex;
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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;
        
        ListNode* pre = new ListNode(-1);
        pre->next = head;
        
        ListNode* now = pre, *nex = head, *preh = pre;
        
        while (nex){
            if (nex->val >= x) {
                nex = nex->next;
                now = now->next;
            }
            else{
                if (pre == now){
                    pre = pre->next;
                    now = pre;
                    nex = now->next;
                }
                else{
                    now->next = nex->next;
                    nex->next = pre->next;
                    pre->next = nex;
                    pre = pre->next;
                    nex = now->next;
                }
            }
        }
        return preh->next;
    }
};
