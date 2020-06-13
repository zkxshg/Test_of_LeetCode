// DFS
class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;
        
        Node* now = head, *nex = head->next, *kid;
        while (now->next) {
            if (now->child) {
                kid = searchChild(now);
                kid->next = nex;
                nex->prev = kid;
            }
            else {
                now = now->next;
                nex = now->next;
            }
        }
        
        if (now->child) nex = searchChild(now);
        return head;
    }
    
    Node* searchChild(Node* head) {
        head->next = head->child;
        head->child->prev = head;
        head->child = NULL;
        
        Node* now = head, *nex = head->next, *kid;
        while(now->next) {
            if (now->child) {
                kid = searchChild(now);
                kid->next = nex;
                nex->prev = kid;
                
                now = nex;
                nex = now->next;
            }
            else {
                now = now->next;
                nex = now->next;
            }
        }
        
        if (now->child) return searchChild(now);
        return now;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
