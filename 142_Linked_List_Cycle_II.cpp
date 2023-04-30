// https://leetcode.com/problems/linked-list-cycle-ii/
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
    ListNode *detectCycle(ListNode *head) {
        if (!head) return NULL;
        vector<ListNode *> pattern;
        while (head){
            if (!head->next) return NULL;
            for (int i = 0; i < pattern.size(); i++){
                if (head == pattern[i]) return pattern[i];
            }
            pattern.push_back(head);
            head = head->next;
        }
        return NULL;
    }
};
