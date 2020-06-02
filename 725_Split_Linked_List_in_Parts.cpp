// linked list
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> result;
        if (k == 1) {
            result.push_back(root);
            return result;
        }
        if (!root) {
            for (int i = 0; i < k; i++) result.push_back(NULL);
            return result;
        }
        
        int length = 1, step;
        ListNode * nex = root, * head = root, * tail;
        while (nex->next) {
            nex = nex->next;
            length++;
        }
        
        int divi = length / k;
        int mod = length % k;
        
        for (int i = 0; i < mod; i++) {
            if (!head) {
                result.push_back(NULL);
                continue;
            }
            tail = head;
            step = 1;
            while (tail->next && step < divi + 1){
                tail = tail->next;
                step++;
            }
            result.push_back(head);
            head = tail->next;
            tail->next = NULL;
        }
        for (int i = mod; i < k; i++) {
            if (!head) {
                result.push_back(NULL);
                continue;
            }
            
            tail = head;
            step = 1;
            while (tail->next && step < divi){
                tail = tail->next;
                step++;
            }
            result.push_back(head);
            head = tail->next;
            tail->next = NULL;
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
