// https://leetcode.com/problems/linked-list-cycle/
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
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        vector<ListNode *> pattern;
        while (head){
            if (!head->next) return false;
            for (int i = 0; i < pattern.size(); i++){
                if (head == pattern[i]) return true;
            }
            pattern.push_back(head);
            head = head->next;
        }
        return true;
    }
};
