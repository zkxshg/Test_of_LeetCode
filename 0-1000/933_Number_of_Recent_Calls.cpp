// Queue
class RecentCounter {
public:
    queue<int> callQ;
    
    RecentCounter() {
        clearQ(callQ);
    }
    
    int ping(int t) {          
        int LB = t - 3000;
        while (!callQ.empty() && callQ.front() < LB) callQ.pop();
        callQ.push(t);
        return callQ.size();
    }
    
    void clearQ(queue<int>& q) {
	    queue<int> empty;
	    swap(empty, q);
    }
};


/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
