// linear scan
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        if (head->next == NULL) return head;
        ListNode *latter = head;
        while(latter->next){
            if (latter->val == latter->next->val) latter->next = latter->next->next;
            else latter = latter->next;
            if(latter == NULL) break;
        }
        return head;
    }
};
