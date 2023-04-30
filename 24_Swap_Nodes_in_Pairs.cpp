// 1-2-3-4 -> 1-3/2-3-4 -> 2-1-3-4
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
    ListNode* swapPairs(ListNode* head) {
        if (!head) return head;
        if (!head->next) return head;
        
        ListNode* result = head->next;
        if (!head->next->next){
            head->next = result->next;
            result->next = head;
            return result;
        }
        
        ListNode* temp;
        while (head && head->next){
            temp = head->next;
            head->next = temp->next;
            temp->next = head;
            temp = head;
            head = head->next;
            if(head && head->next) temp->next = head->next;
        }
        return result;
    }
};
