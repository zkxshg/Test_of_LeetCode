// https://leetcode.com/problems/design-circular-queue/
// Design + queue + two pointers
class MyCircularQueue {
public:
    vector<int> Q;
    int len, st, en;
    
    MyCircularQueue(int k) {
        Q = vector<int>(k, -1);
        len = k; st = 0; en = 0;
    }
    
    bool enQueue(int value) {
        if (st == en && Q[st] < 0) Q[st] = value;
        else if ((en + 1) % len != st) {
            en = (en + 1) % len;
            Q[en] = value;
        }
        else return false;
        
        return true;
    }
    
    bool deQueue() {
        if (st == en) {
            if (Q[st] < 0) return false;
            else {
                Q[st] = -1; return true;
            }
        }
        
        Q[st] = -1;
        st = (st + 1) % len;
        
        return true;
    }
    
    int Front() {
        return Q[st];
    }
    
    int Rear() {
        return Q[en];
    }
    
    bool isEmpty() {
        if (st == en && Q[st] < 0) return true;
        return false;
    }
    
    bool isFull() {
        if ((en + 1) % len == st) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
