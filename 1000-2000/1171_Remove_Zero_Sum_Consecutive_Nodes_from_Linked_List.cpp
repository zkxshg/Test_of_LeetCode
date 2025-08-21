// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
// Two pointers
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        if (!head) return head;
        if (!head->next && head->val != 0) return head;
        
        vector<int> link;
        ListNode* nex = head;
        while (nex) {
            link.push_back(nex->val);
            nex = nex->next;
        }
        
        int start = 0;
        while (start < link.size()) {
            
            if (link[start] == 0) {
                link.erase(link.begin() + start);
                continue;
            }
            
            bool sum0 = false;
            int last, addup = link[start];
            for (int i = start + 1; i < link.size(); i++) {
                addup += link[i];
                if (addup == 0) {
                    last = i;
                    sum0 = true;
                    break;
                }
            }
            
            if (sum0) {
                link.erase(link.begin() + start, link.begin() + last + 1);
                start = 0;
            }
            else start++;
        }
        
        ListNode* pre = new ListNode(-1);
        nex = pre; 
        for (int i = 0; i < link.size(); i++) {
            ListNode* temp = new ListNode(link[i]);
            nex->next = temp;
            nex = nex->next;
        }
        return pre->next;
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
