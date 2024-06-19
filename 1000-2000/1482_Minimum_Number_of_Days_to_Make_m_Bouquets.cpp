// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/?envType=daily-question&envId=2024-06-19
// Binary search

class Solution {
public:
    bool scan(vector<int>& bloomDay, int m, int k, int days) {
        int bouquets = 0;
        int flowers = 0;
        
        for (int i = 0; i < bloomDay.size(); ++i) {
            if (bloomDay[i] <= days) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        
        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ((double)n / k < m) return -1; 

        int st = 1, en = *max_element(bloomDay.begin() , bloomDay.end()), mid = 0;

        // Binary search 
        while (st <= en) {
            mid = st + (en - st) / 2;
            
            if (scan(bloomDay, m, k, mid)) {
                en = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        if (!scan(bloomDay, m, k, mid)) return mid + 1;
        return mid;
    }
}; 
