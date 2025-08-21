// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
// sc[1] += 1; sc[0] += (root->val) * pow(2, sc[1]);
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
    int getDecimalValue(ListNode* head) {
        if (!head) return 0;
        if (!(head->next)) {
            if (head->val == 0) return 0;
            else return 1;
        }
        vector<int> sum_count(2);
        calSum(head, sum_count);
        return sum_count[0];
    }
    
    void calSum(ListNode* root, vector<int> &sc){
        if (!(root->next)){
            sc[1] = 0;
            sc[0] += (root->val) * pow(2, sc[1]);
        }
        else{
            calSum(root->next, sc);
            sc[1] += 1;
            sc[0] += (root->val) * pow(2, sc[1]);
        }
    }
};
