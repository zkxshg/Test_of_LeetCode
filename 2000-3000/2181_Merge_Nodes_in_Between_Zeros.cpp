// https://leetcode.com/problems/merge-nodes-in-between-zeros/?envType=daily-question&envId=2024-07-04
// Link list + DFS

class Solution {
public:
    #define LN ListNode
    
    void dfs(LN* head, LN* tem, int total) {
        if (head->val == 0) {
            tem->val = total;

            if (head->next) {
                tem = tem->next;
                dfs(head->next, tem, 0);
            }
            else tem->next = nullptr;
        }
        else {
            dfs(head->next, tem, total + head->val);
        }
    }
    
    ListNode* mergeNodes(ListNode* head) {
        LN* tem = head;
        dfs(head->next, tem, 0);
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
