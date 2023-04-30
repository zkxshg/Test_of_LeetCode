// https://leetcode.com/problems/corporate-flight-bookings/
// prefix sum + dp

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> seats(n + 1);
        for (auto& v : bookings) {
            seats[v[1]] += v[2];
            seats[v[0] - 1] -= v[2];
        }
        // for (int i : seats) cout << i << ","; cout << endl;
        vector<int> res(n); 
        res[n - 1] = seats[n]; seats.pop_back();
        for (int i = n - 2; i >= 0; i--) {
            res[i] = res[i + 1] + seats.back(); seats.pop_back();
            
        }
        return res;
    }
}; 
