// https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/?envType=daily-question&envId=2024-09-01
// Linked List + Math

class Solution {
public:
    int calculateGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* pre = head;
        ListNode* nex = head->next;

        while (nex != nullptr) {
            int gcdValue = calculateGCD(pre->val, nex->val);
            ListNode* gcdNode = new ListNode(gcdValue);

            pre->next = gcdNode;
            gcdNode->next = nex;

            pre = nex;
            nex = nex->next;
        }

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
