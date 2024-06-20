// https://leetcode.com/problems/magnetic-force-between-two-balls/?envType=daily-question&envId=2024-06-20
// Binary search

class Solution {
public:
    bool canPlaceBalls(vector<int>& position, int m, int mid) {
        int count = 1;
        int last_position = position[0];
        
        for (int i = 1; i < position.size(); ++i) {
            if (position[i] - last_position >= mid) {
                count++;
                last_position = position[i];
                
                if (count == m) return true;
            }
        }
        
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();

        sort(position.begin(), position.end());
        
        int st = 1;
        int en = position[n - 1] - position[0];
        int result = -1;
        
        while (st <= en) {
            int mid = st + (en - st) / 2;
            
            if (canPlaceBalls(position, m, mid)) {
                result = mid; 
                st = mid + 1; 
            } else {
                en = mid - 1;
            }
        }
        
        return result;
    }
};
