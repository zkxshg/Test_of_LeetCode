// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/?envType=daily-question&envId=2024-07-05
// Link List + Two points

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int pos = 0, st = -1, pre = -1, preVal = -1;
        int res_1 = 100001, res_2 = -1;
        ListNode* nex = head;
        while (nex->next) {
            if (preVal > 0) {
                int tv = nex->val, nv = nex->next->val;
                // Get Ctritical P
                if ((tv > preVal && tv > nv) || (tv < preVal && tv < nv)) {
                    if (st < 0 || pre < 0) { // Start
                        st = pos; pre = pos;
                    }
                    else {
                        res_1 = min(res_1, pos - pre);
                        res_2 = max(res_2, pos - st);

                        pre = pos;
                    }
                }
            }

            preVal = nex->val;
            nex = nex->next;
            pos++;
        }

        if (res_2 > 0) return {res_1, res_2};

        return {-1, -1};
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
