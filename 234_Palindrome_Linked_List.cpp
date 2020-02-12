//if ((findN(index, head)->val)!=(findN(count - index - 1, head)->val)) pali = false; 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == 0) return true;
        ListNode* n1 = head->next;
        if (n1 == 0) return true;
        int count = 2;
        while (n1 = n1->next)   count++;
        int index = 0;
        int pali = true;
        while (index < count / 2) {
            ListNode * m1 = findN(index, head);
            ListNode * m2 = findN(count - index - 1, head);
            if ((m1->val)!=(m2->val)) {
                pali = false;
                break;
            }
            index ++;
        }
        return pali;
    }
    ListNode * findN(int n, ListNode* first) {
        ListNode* n1 = first;
        for (int i = 0; i < n; i++) n1 = n1->next;
        return n1;
    }
};

// ==========================================
// Demo
#include <cmath>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode * findN(int n, ListNode* first);
bool isPalindrome(ListNode* head);

int main()
{
    ListNode * l1 = new ListNode(1);
    ListNode * l2 = new ListNode(2);
    l2->next = l1;
    ListNode * l3 = new ListNode(1);
    l3->next = l2;
    cout << l3->val << " " << l3->next->val << " " << l3->next->next->val << endl;
    cout << isPalindrome(l3);
    return 0;
}

bool isPalindrome(ListNode* head) {
    if (head == 0) return false;
    ListNode* n1 = head->next;
    if (n1 == 0) return true;
    int count = 2;
    while (n1 = n1->next)   count++;
    int index = 0;
    int pali = true;
    while (index < count / 2) {
        ListNode * m1 = findN(index, head);
        ListNode * m2 = findN(count - index - 1, head);
        if ((m1->val)!=(m2->val)) {
            pali = false;
            break;
        }
        index ++;
    }
    return pali;
}

ListNode * findN(int n, ListNode* first) {
    ListNode* n1 = first;
    for (int i = 0; i < n; i++) n1 = n1->next;
    return n1;
}
