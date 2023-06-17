// https://leetcode.com/problems/make-array-strictly-increasing/description/
// DP

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        // Sort and remove duplicates from arr2
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());

        int n = arr1.size();
        arr1.push_back(2e9);  // Sentinel value to simplify the boundary check

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 2e9));
        dp[0][0] = -2e9;  // Base case

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (dp[i][j] < arr1[i]) {
                    dp[i + 1][j] = min(dp[i + 1][j], arr1[i]);
                }

                int pos = upper_bound(arr2.begin(), arr2.end(), dp[i][j]) - arr2.begin();
                if (pos != arr2.size()) {
                    dp[i + 1][j + 1] = min(dp[i + 1][j + 1], arr2[pos]);
                }
            }
        }

        for (int j = 0; j <= n; ++j) {
            if (dp[n][j] < arr1[n]) {
                return j;
            }
        }

        return -1;
    }
};

// Linear scan
class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        // Sort and remove duplicates from arr2
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());

        // Initial
        int n = arr1.size();
        set<tuple<int, int, int>> states;
        states.emplace(0, arr1[0], -1);
        if (arr1[0] > arr2[0]) states.emplace(1, arr2[0], 0);

        // Loop
        for (int i = 1; i < n; i++) {
            set<tuple<int, int, int>> new_states;

            for (const auto& state : states) {
                int ops, val, j;
                tie(ops, val, j) = state;

                if (arr1[i] > val) {
                    // Keep current value of arr1[i] if increasing
                    new_states.emplace(ops, arr1[i], j);
                    
                    // Replace the smallest arr1[i]
                    int lessPos =
                        upper_bound(arr2.begin(), arr2.end(), val) - arr2.begin();
                    if (lessPos < arr2.size() && arr2[lessPos] < arr1[i]) 
                        new_states.emplace(ops + 1, arr2[lessPos], lessPos);
                }
                else {
                    // Increase ops and find the smallest arr2[j] greater than pre
                    int nexPos = upper_bound(arr2.begin(), arr2.end(),val) - arr2.begin();

                    if (nexPos < arr2.size()) 
                        new_states.emplace(ops + 1, arr2[nexPos], nexPos);
                    else continue;
                }
            }

            states.swap(new_states);
        }

        int ans = -1;
        for (const auto& state : states) {
            int ops, val, j;
            tie(ops, val, j) = state;
            if (ans == -1 || ans > ops) {
                ans = ops;
            }
        }

        return ans;

    }
};
