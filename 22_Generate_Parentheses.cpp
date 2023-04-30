// https://leetcode.com/problems/generate-parentheses/
// binary tree search: struct BTree { char val; struct BTree *left,*right; };
// BTree* create_tree(int level, int pos);
// void PreOrder(BTree* root, string str1, int cou, int cr, vector<string> *res);
class Solution {
public:
    struct BTree {
	    char val;
	    struct BTree *left,*right;
    };
    
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        BTree *node = new BTree;
        int lv = n*2;
        node->val = '\0';
        node->left = create_tree(lv-1, 0);
        node->right = create_tree(lv-1, 1);
        string str = "";
        int counter = 0;
        int cou_right = n;
        PreOrder(node, str, counter, cou_right, &result);
        return result;
    }
    
    BTree* create_tree(int level, int pos){
      BTree *branch = new BTree;
      if (pos == 0) branch->val = '(';
      else branch->val = ')';
      if (level == 0){
        branch->right = NULL;
        branch->left = NULL;
        return branch;
      }
      branch->left = create_tree(level-1, 0);
      branch->right = create_tree(level-1, 1);
      return branch;
 }
    
void PreOrder(BTree* root, string str1, int cou, int cr, vector<string> *res){
     if (root->left){
        if (root->val == '\0') cou = 0;
        else if (root->val == '(') {
                cou += 1;
                cr -= 1;
        }
        else cou -= 1;
        if (cou >= 0 && cr >= 0){
            string str2 = str1 + root->val;
            PreOrder(root->left, str2, cou, cr, res);
            PreOrder(root->right, str2, cou, cr, res);
        }
     }
     else
     {
        if (root->val == '(') {
            cou += 1;
            cr -= 1;
            }
        else cou -= 1;
        if (cou >= 0 && cr >= 0){
            string str2 = str1 + root->val;
            str2 = str2.substr(1, str2.size()-1);
            (*res).push_back(str2);
        }
     }
 }    
};

// Demo
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

struct BTree
{
	char val;
	struct BTree *left,*right;
};
BTree* create_tree(int level, int pos);
void PreOrder(BTree* root, string str1, int cou, int cr, vector<string> *res);

int main()
{
    int n = 6;
    vector<string> result;
    BTree *node = new BTree;
    int lv = n*2;
    node->val = '\0';
    node->left = create_tree(lv-1, 0);
    node->right = create_tree(lv-1, 1);
    string str = "";
    int counter = 0;
    int cou_right = n;
    PreOrder(node, str, counter, cou_right, &result);
    for (int i = 0; i < result.size(); i++) cout << result[i] << endl;
    return 0;
}
 BTree* create_tree(int level, int pos)
 {
     BTree *branch = new BTree;
     if (pos == 0) branch->val = '(';
     else branch->val = ')';
     if (level == 0){
        branch->right = NULL;
        branch->left = NULL;
        return branch;
     }
     branch->left = create_tree(level-1, 0);
     branch->right = create_tree(level-1, 1);
     return branch;
 }
 void PreOrder(BTree* root, string str1, int cou, int cr, vector<string> *res)
 {
     if (root->left){
        if (root->val == '\0') cou = 0;
        else if (root->val == '(') {
                cou += 1;
                cr -= 1;
        }
        else cou -= 1;
        if (cou >= 0 && cr >= 0){
            string str2 = str1 + root->val;
            PreOrder(root->left, str2, cou, cr, res);
            PreOrder(root->right, str2, cou, cr, res);
        }
     }
     else
     {
        if (root->val == '(') {
            cou += 1;
            cr -= 1;
            }
        else cou -= 1;
        if (cou >= 0 && cr >= 0){
            string str2 = str1 + root->val;
            str2 = str2.substr(1, str2.size()-1);
            (*res).push_back(str2);
        }
     }
 }
