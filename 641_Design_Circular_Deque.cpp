// https://leetcode.com/problems/design-circular-deque/
// Linked List

class MyCircularDeque {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    
    ListNode *root;
    int cap, tem;
    
    MyCircularDeque(int k) {
        cap = k; tem = 0;
        
        root = new ListNode(-1);
    }
    
    bool insertFront(int value) {
        if (tem < cap) {
            ListNode * frt = new ListNode(value);
            frt->next = root->next;
            root->next = frt;
            
            tem++;
            return true;
        }
        
        return false;
    }
    
    bool insertLast(int value) {
        if (tem < cap) {
            ListNode* lst = new ListNode(value);
            
            ListNode* nex = root;
            while (nex->next) nex = nex->next;
            nex->next = lst;

            tem++;
            return true;
        }
        
        return false;
    }
    
    bool deleteFront() {
        if (tem > 0) {
            ListNode* frt = root->next;
            root->next = frt->next;
            
            tem--;
            return true;
        }
        
        return false;
    }
    
    bool deleteLast() {
        if (tem > 0) {
            ListNode* nex = root;
            while (nex->next->next) nex = nex->next;
            nex->next = NULL;
            
            tem--;
            return true;
        }
        return false;
    }
    
    int getFront() {
        if (root->next) return root->next->val;
        return -1;
    }
    
    int getRear() {
        if (root->next) {
            ListNode* nex = root;
            while (nex->next) nex = nex->next;
            
            return nex->val;
        }
        
        return -1;
    }
    
    bool isEmpty() {
        return (tem == 0);
    }
    
    bool isFull() {
        return (tem == cap);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
