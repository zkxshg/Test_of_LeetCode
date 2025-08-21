// https://leetcode.com/problems/lfu-cache/description/
// Queue + hash table; design

class LFUCache {
public:
    int cap, tcap; // capacity & temp capacity
    unordered_map<int, queue<int>> ods; // use orders
    unordered_map<int, int> vals; // values
    unordered_map<int, int> cnts; // use counters

    LFUCache(int capacity) {
        ods.clear(); vals.clear(); cnts.clear();
        tcap = 0; cap = capacity;
    }
    
    int get(int key) {
        if (cnts[key]) { // key exist
            cnts[key]++; // use counter++; 
            ods[cnts[key]].push(key); // use order++;

            return vals[key];
        }

        return -1;
    }
    
    void put(int key, int value) {
        if (!cap) return;
        // cout << key << ":" << value << endl;
        if (cnts[key]) { // key exist
            vals[key] = value; // update value
            cnts[key]++; // use counter
            ods[cnts[key]].push(key); // use order
        }
        else if (tcap < cap) { // cap not full
            vals[key] = value;
            cnts[key] = 1; 
            ods[1].push(key);

            tcap++;
        }
        else { // cap full -> use LFU
            bool pp = false;
            
            int tcnt = 1;
            while (!pp) {
                queue<int>& Q = ods[tcnt];
                while (!Q.empty()) { 
                    //cout << tcnt << ":" << "Q[" << Q.front() << "] = " << cnts[Q.front()] << endl; 
                    if (cnts[Q.front()] != tcnt) Q.pop(); // redundant key
                    else { // Get the LFU
                        int rkey = Q.front(); // LFU and LRU key

                        cnts[rkey] = 0; vals[rkey] = -1; Q.pop(); // remove rkey

                        vals[key] = value; cnts[key] = 1; ods[1].push(key); // add new key

                        pp = true; break;
                    }
                }
                tcnt++;
            }
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
