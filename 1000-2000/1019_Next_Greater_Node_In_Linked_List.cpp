// https://leetcode.com/problems/next-greater-node-in-linked-list/
// stack
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> result;
        vector<int> valStack;
        vector<int> indStack;
        
        if (!head) return result;
        if (!head->next) {
            result.push_back(0);
            return result;
        }
        
        int index = 0;
        while (head) {
            while (!valStack.empty() && valStack.back() < head->val) {
                result[indStack.back()] = head->val;
                valStack.pop_back();
                indStack.pop_back();
            }
            result.push_back(0);
            valStack.push_back(head->val);
            indStack.push_back(index++);
            head = head->next;
        }
        return result;
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
