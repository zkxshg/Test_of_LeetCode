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
    ListNode* middleNode(ListNode* head) {
        if (!head || !head->next) return head;
        
        int len = 0;
        ListNode* nex = head;
        while (nex){
            nex = nex->next;
            len++;
        }
        
        int middle = len / 2 + 1;
        nex = head;
        while (middle > 1){
            nex = nex->next;
            middle--;
        }
        return nex;
    }
};
