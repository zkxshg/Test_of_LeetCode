// k = 4
// pre -> 1/cou/tail -> 2/nex -> 3 -> 4 -> 5
// pre -> 2/tail -> 1/cou -> 3/nex -> 4 -> 5
// pre -> 3/tail -> 2 -> 1/cou -> 4/nex -> 5
// pre -> 4/tail -> 3 -> 2 -> 1/cou -> 5/nex 
// 4 -> 3 -> 2 -> 1/pre -> 5 /cou/tail -> 6/nex
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1 || !head) return head;
        
        int len = 0;
        ListNode* cou = head, *nex, *tail, *pre;
        while (cou){
            cou = cou->next;
            len++;
        }
        if (len < k) return head;
        
        cou = head;
        for (int i = 0; i < k - 1; i++) cou = cou->next;
        ListNode* preh = new ListNode(-1);
        preh->next = cou;
        
        pre = preh;
        cou = head;
        nex = cou->next;
        tail = cou;
        while (len >= k){
            for (int i = 0; i < k-1; i++){
                cou->next = nex->next;
                nex->next = tail;
                tail = nex;
                nex = cou->next;
            }
            pre->next = tail;
            len -= k;
            if (len >= k){
                pre = cou;
                cou = nex;
                nex = cou->next;
                tail = cou;
            }
        }
        return preh->next;   
    }
};
