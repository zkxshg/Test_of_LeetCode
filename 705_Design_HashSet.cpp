// LinkList
class MyHashSet {
public:
    /** Initialize your data structure here. */
    
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    
    vector<ListNode*> hashset;
    
    MyHashSet() {
        for (int i = 0; i < 10000; i++) {
            ListNode * temp  = new ListNode(i);
            hashset.push_back(temp);
        }
    }
    
    void add(int key) {
        int pos = key % 10000;
        int value = key / 10000;
        ListNode * posN = hashset[pos];
        ListNode * posL = new ListNode(value);
        if (!posN->next) posN->next = posL;
        else {
            bool bein = false;
            while (posN->next) {
                posN = posN->next;
                if (posN->val == value) {
                    bein = true;
                    break;
                }
            }
            if (!bein) posN->next = posL;
        } 
    }
    
    void remove(int key) {
        int pos = key % 10000;
        int value = key / 10000; 
        ListNode * posN = hashset[pos];
        while (posN->next) {
            if (posN->next->val == value) {
                posN->next = posN->next->next;
                break;
            }
            posN = posN->next;
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int pos = key % 10000;
        int value = key / 10000;
        ListNode * posN = hashset[pos];
        while (posN->next) {
            posN = posN->next;
            if (posN->val == value) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
