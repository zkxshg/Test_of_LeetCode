// https://leetcode.com/problems/sort-list/
// Merge sort 
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        return mergeSort(head);
    }
    
    ListNode* mergeSort(ListNode* head) {
        ListNode* mid = getMid(head);
        if (mid) {
            ListNode* lhead = head, * rhead = mid->next;
            mid->next = NULL;
            lhead = mergeSort(lhead);
            rhead = mergeSort(rhead);
            head = merge(lhead, rhead);
        }
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
    
    ListNode* getMid(ListNode* head) {
        if (!head || !head->next) return NULL;
        
        ListNode* slow = head, * fast = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
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
