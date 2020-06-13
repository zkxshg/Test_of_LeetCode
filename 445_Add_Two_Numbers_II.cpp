// LinkList -> vector -> LinkList
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) return l2; if (!l2) return l1;
        
        vector<int> v1;  vector<int> v2;
        
        ListNode* nex = l1;
        while (nex) {
            v1.push_back(nex->val);
            nex = nex->next;
        }
        nex = l2;
        while (nex) {
            v2.push_back(nex->val);
            nex = nex->next;
        }
        
        if (v1.size() < v2.size()) v1.swap(v2);
        int len1 = v1.size(), len2 = v2.size(), addone = 0;
        
        for (int i = 0; i < len2; i++) {
            int addup = v1[len1 - 1 - i] + v2[len2 - 1 - i] + addone;
            if (addup > 9) {
                addone = 1;
                addup -= 10;
            }
            else addone = 0;
            
            if (i == 0) {
                ListNode* temp = new ListNode(addup);
                nex = temp;
                continue;
            }
            ListNode* temp = new ListNode(addup);
            temp->next = nex;
            nex = temp;
        }
        
        for (int i = len2; i < len1; i++) {
            int addup = v1[len1 - 1 - i] + addone;
            if (addup > 9) {
                addone = 1;
                addup -= 10;
            }
            else addone = 0;
            ListNode* temp = new ListNode(addup);
            temp->next = nex;
            nex = temp;
        }
        
        if (addone == 1) {
            ListNode* temp = new ListNode(1);
            temp->next = nex;
            nex = temp;
        }
      
        return nex;
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
