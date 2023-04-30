// https://leetcode.com/problems/koko-eating-bananas/
// Binary Search

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        
        sort(piles.begin(), piles.end());
        
        int st = 1, en = piles.back(), mid = (st + en) / 2;
        
        while (st < en) {
            mid = (st + en) / 2;
            
            int cost = 0;
            for (int p : piles) cost += ceil(double(p) / mid);
            //cout << piles.back() << "/" << mid << "="  << ceil(double(piles.back()) / mid) << endl;
            if (cost > h) st = mid + 1;
            else en = mid;
            // else en = mid;
        }
        
        return st;
    }
};
