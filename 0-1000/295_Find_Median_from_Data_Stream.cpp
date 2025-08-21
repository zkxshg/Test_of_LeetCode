// https://leetcode.com/problems/find-median-from-data-stream/
// heap

class MedianFinder {
public:
    bool even;
    vector<int> minHp;
    vector<int> maxHp;
    
    static bool cmp(int a, int b) {
        return a > b;
    }
    
    MedianFinder() {
        even = true;
        minHp.clear(); make_heap(minHp.begin(), minHp.end(), cmp);
        maxHp.clear(); make_heap(maxHp.begin(), maxHp.end());
    }
    
    void addNum(int num) {
        if (even) {
            minHp.push_back(num); push_heap(minHp.begin(), minHp.end(), cmp);
            maxHp.push_back(minHp.front()); push_heap(maxHp.begin(), maxHp.end());
            pop_heap(minHp.begin(), minHp.end(), cmp); minHp.pop_back();
        }
        else {
            maxHp.push_back(num); push_heap(maxHp.begin(), maxHp.end());
            minHp.push_back(maxHp.front()); push_heap(minHp.begin(), minHp.end(), cmp);
            pop_heap(maxHp.begin(), maxHp.end()); maxHp.pop_back();
        }
        even = !even;
    }
    
    double findMedian() {
        if (even) return double(maxHp.front() + minHp.front()) / 2.0;
        return maxHp.front();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
