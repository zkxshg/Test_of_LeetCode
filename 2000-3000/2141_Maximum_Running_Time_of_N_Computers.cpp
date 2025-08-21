// https://leetcode.com/problems/maximum-running-time-of-n-computers/description/
// Binary search + greedy

class Solution {
public:
    #define ll long long

    bool isPossible(int n, vector<int>& orignal_arr, ll mid_duration) {
        vector<int> batteries = orignal_arr;
        //cout << mid_duration << endl;
        int computers_charged = 0; 
        int left = 0;
        int right = batteries.size() - 1;

        while (right >= 0 && computers_charged < n) {
            // cout << left << ":" << right << endl;
            if (batteries[right] >= mid_duration) {
                computers_charged++;
                right--;
            } 
            else {
                ll tem_d = mid_duration;

                while (left < right && batteries[right] < tem_d) {
                    if (batteries[left] + batteries[right] < tem_d) {
                        tem_d -= batteries[left]; left++;
                    }
                    else {
                        batteries[left] = batteries[left] - (tem_d - batteries[right]);
                        break;
                    }
                }
                // cout << left << ":" << batteries[left] << endl;
                if (left < right) {
                    computers_charged++;
                    right--;

                    if (batteries[left] <= 0) left++;
                } 
                else break;
            }
        }

        return computers_charged == n;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        if (n == 0) return 0;

        sort(batteries.begin(), batteries.end());

        ll low = 0;
        
        ll high = 0;
        for (int b : batteries) high += b / n + 1;

        ll result = 0;

        while (low <= high) {
            ll mid = low + (high - low) / 2;

            if (isPossible(n, batteries, mid)) {
                result = mid;
                low = mid + 1;
            } 
            else {
                high = mid - 1;
            }
        }

        return result;
    }
};
