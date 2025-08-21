// https://leetcode.com/problems/copy-list-with-random-pointer/
// double list + hash table
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;
   
        Node * nex = head, * ori, * result;
        
        while (nex) {
            Node * bro = new Node(nex->val);
            bro->next = nex->next;
            nex->next = bro;
            nex = nex->next->next;
        }
        
        nex = head;
        while (nex) {
            if (nex->random) nex->next->random = nex->random->next;
            nex = nex->next->next;
        }
        
        nex = head->next;
        ori = head;
        result = nex;
        while (nex->next) {
            ori->next = nex->next;
            ori = ori->next;
            nex->next = ori->next;
            nex = nex->next;
        }
        ori->next = NULL;
        return result;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
