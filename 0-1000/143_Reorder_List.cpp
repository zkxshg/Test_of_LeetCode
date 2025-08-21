// https://leetcode.com/problems/reorder-list/
// Recursion
class Solution {
public:
    ListNode * temp;
    bool done = false;
    void reorderList(ListNode* head) {
        if (head && head->next) {
            temp = head;
            goTail(temp);
        }
    }
    void goTail(ListNode* head) {
        if (head->next) goTail(head->next);
        if (head != temp && head != temp->next && !done) {
            head->next= temp->next;
            temp->next = head;
            temp = head->next;
        }
        else if (!done){
            head->next = NULL;
            done = true;
        }
    }
};

// Can be reduced to O(n) based on recursion
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head && head->next) {
            ListNode * temp = head, * nex = head->next, * tail = nex;
            while (nex && nex->next) {
                while (tail->next->next) tail = tail->next;
            
                temp->next = tail->next;
                tail->next->next = nex;
                tail->next = NULL;
            
                temp = nex;
                nex = nex->next;
                tail = nex;
            }
        }
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
