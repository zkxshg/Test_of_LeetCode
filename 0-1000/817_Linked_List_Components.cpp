// Transform to calculate the number of connected links by hash table
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        if (!head || G.size() == 0) return 0;
        if (G.size() == 1) return 1;
        
        unordered_map<int, int> linkDict;
        unordered_map<int, int> freDict;
        vector<int> alphabet;
        
        ListNode* nex = head;
        while (nex->next) {
            linkDict[nex->val] = nex->next->val;
            freDict[nex->val] = 0;
            alphabet.push_back(nex->val);
            nex = nex->next;
        }
        linkDict[nex->val] = -1;
        freDict[nex->val] = 0;
        freDict[-1] = 0;
        alphabet.push_back(nex->val);
        for (int i : G) freDict[i] = 1;
        
        int result = 0;
        for (int i : G) result += freDict[linkDict[i]];
        return G.size() - result;
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
