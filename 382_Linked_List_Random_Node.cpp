// random
class Solution {
public:
    ListNode* root;
    int len;
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        root = head;
        
        ListNode*  nex = head; int leng = 1;
        while (nex->next) {
            leng++;
            nex = nex->next;
        }
        len = leng;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int ran = rand() % len;
        ListNode* nex = root;
        
        while (ran > 0) {
            nex = nex->next;
            ran--;
        }
        return nex->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
 
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
