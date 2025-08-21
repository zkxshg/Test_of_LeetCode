// 3477. Fruits Into Baskets II
// Link: https://leetcode.com/problems/fruits-into-baskets-ii/
// Lang: C++
// Date: 2025-08-21 20:52:19.389 UTC

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        queue<int> q;
        for (int cap : baskets) {
            q.push(cap);
        }
        
        int unplaced = 0;
        
        for (int fruit : fruits) {
            bool placed = false;
            int m = q.size();
            queue<int> tmp;
            
            // Try to place this fruit in the leftmost fitting basket
            for (int i = 0; i < m; ++i) {
                int cap = q.front(); 
                q.pop();
                
                if (!placed && cap >= fruit) {
                    // Place fruit here: consume this basket
                    placed = true;
                } else {
                    // Keep this basket for future fruits
                    tmp.push(cap);
                }
            }
            
            // Restore the remaining baskets in order
            q.swap(tmp);
            
            if (!placed) {
                ++unplaced;
            }
        }
        
        return unplaced;
    }
};
