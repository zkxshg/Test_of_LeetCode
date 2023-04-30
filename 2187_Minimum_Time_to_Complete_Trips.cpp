// https://leetcode.com/problems/minimum-time-to-complete-trips/description/
// binary search

class Solution {
public:
    #define ll long long

    long long searchTrip(vector<int>& time, ll totalTime) {
        ll trips = 0;
        for (int t : time) trips += (totalTime / t);
        return trips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();

        ll maxT = *max_element(time.begin(), time.end());
        ll minT = *min_element(time.begin(), time.end());

        ll st = totalTrips * minT / n, en = totalTrips * maxT + 1;

        // cout << maxT << "," << minT << "," << st << "," << en << endl;

        while (st < en) {
            ll mid = (st + en) / 2;

            ll trips = searchTrip(time, mid);

            if (trips < totalTrips) st = mid + 1;
            else if (trips > totalTrips) en = mid;
            else {
                if (searchTrip(time, mid - 1) < totalTrips) return mid;
                else en = mid;
            }
        }

        return st;
    }
};
