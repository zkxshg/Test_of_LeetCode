// divide-and-conquer
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int pos = 0;
        while (pos < lists.size()) {
            if (!lists[pos]) lists.erase(lists.begin() + pos);
            else pos++;
        }
        
        int len = lists.size();
        if (len == 0) return NULL;
        if (len == 1) return lists[0];
        
        ListNode * head = lists[0];
        for (int i = 1; i < len; i++) head = merge(head, lists[i]);
        return head;
    }
    
    ListNode* merge(ListNode* lhead, ListNode* rhead) {
        ListNode * l1 = lhead, * l2 = rhead;
        if (l1->val > l2->val) {
            l1 = rhead;
            l2 = lhead;
        }
        ListNode * head = l1, * temp;
        while (l1->next && l2) {
            if (l2->val < l1->next->val) {
                temp = l2->next;
                l2->next = l1->next;
                l1->next = l2;
                l2 = temp;
            }
            l1 = l1->next;
        }
        if (l2) l1->next = l2;
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
