// https://leetcode.com/problems/seat-reservation-manager/
// Design + set

class SeatManager {
public:
    set<int> S;
    
    SeatManager(int n) {
        S.clear();
        for (int i = 1; i <= n; i++) S.insert(i);
    }
    
    int reserve() {
        int seat = *S.begin();
        S.erase(seat);
        return seat;
    }
    
    void unreserve(int seatNumber) {
        S.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
