// https://leetcode.com/problems/kth-largest-element-in-a-stream/
// heap

class KthLargest {
public:
    int kth;
    vector<int> hp;
    
    static bool cmp(int a, int b) {
        return a > b;
    }
    
    KthLargest(int k, vector<int>& nums) {
        hp = nums; kth = k;
        make_heap(hp.begin(), hp.end(), cmp);
        
        while (hp.size() > k) {
            pop_heap(hp.begin(), hp.end(), cmp);
            hp.pop_back();
        }
    }
    
    int add(int val) {
        hp.push_back(val);
        push_heap(hp.begin(), hp.end(), cmp);
        
        if (hp.size() > kth) {
            pop_heap(hp.begin(), hp.end(), cmp);
            hp.pop_back();
        }
        
        return hp.front();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
