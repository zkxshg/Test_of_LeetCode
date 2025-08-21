//https://leetcode.com/problems/linked-list-in-binary-tree/
// two pointers
// searchNode? ifEqual : searchNode(left / right)
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        return searchNode(head, root);
    }
    
    bool searchNode(ListNode* head, TreeNode* root) {
        if (head->val == root->val) {
            if (ifEqual(head, root)) return true;
        }
        if (root->left) {
            if (searchNode(head, root->left)) return true;
        }
        if (root->right) {
            if (searchNode(head, root->right)) return true;
        }
        return false;
    }
    
    bool ifEqual(ListNode* head, TreeNode* root) {
        if (head->val != root->val) return false;
        if (!head->next) return true;
        if (root->left) {
            if (ifEqual(head->next, root->left)) return true;
        }
        if (root->right) {
            if (ifEqual(head->next, root->right)) return true;
        } 
        return false;   
    } 
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
