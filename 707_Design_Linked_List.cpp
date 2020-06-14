// design
class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    
    ListNode * pre;
    
    /** Initialize your data structure here. */
    MyLinkedList() {
        pre = new ListNode(-1);
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        ListNode * nex = pre->next;
        int cou = 0;
        while (cou < index && nex->next) {
            nex = nex->next;
            cou++;
        }
        if (cou == index) return nex->val;
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode * temp = new ListNode(val);
        temp->next = pre->next;
        pre->next = temp;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode * temp = new ListNode(val);
        ListNode * nex = pre;
        while (nex->next) nex = nex->next;
        nex->next = temp;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        ListNode * temp = new ListNode(val);
        ListNode * nex = pre;
        int cou = 0;
        while (cou < index && nex->next) {
            nex = nex->next;
            cou++;
        }
        if (cou == index) {
            temp->next = nex->next;
            nex->next = temp;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        ListNode * nex = pre;
        int cou = 0;
        while (cou < index && nex->next) {
            nex = nex->next;
            cou++;
        }
        if (cou == index && nex->next) nex->next = nex->next->next; 
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
