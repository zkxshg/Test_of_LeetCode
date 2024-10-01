// https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/?envType=daily-question&envId=2024-09-01
// Linked List + Hash Table

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, int> mp;
        for (int n : nums) mp[n]++;

        ListNode* root = new ListNode(-1); 
        root->next = head;

        ListNode* nex = root;
        while (nex && nex->next) {
            if (mp.count(nex->next->val) != 0) {
                nex->next = nex->next->next;
            }
            else nex = nex->next;
        }

        return root->next;
        
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
