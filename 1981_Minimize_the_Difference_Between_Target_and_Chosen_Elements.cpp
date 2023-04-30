// https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/
// Backtracking + hash map

class Solution {
public:
    int adiv, m, n;
    map<pair<int, int>, int> P;
    
     void solve(int index, int target, vector<vector<int> >& candidates) {
        if (!adiv) return;
         
        if(target == 0) {
            //for (int i = 0; i < m; i++) cout << ds[i] << ","; cout << endl;
            adiv = 0;
            return;
        }
        
        for (int j = 0; j < n - 1; j++) {
            int aim = candidates[index][j];
            adiv = min(adiv, abs(target - aim));
            
            if(aim > target) break;
            
            target -= aim;
            
            if (!P[make_pair(index, target)]) {
                P[make_pair(index, target)] = 1;
                for(int i = index; i < m - 1; i++)  solve(i+1, target, candidates);
            }
            
        } 
        
    }
    
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        m = mat.size();
        n = mat[0].size();
        
        // LowBound and UpBound 
        int minSum = 0, maxSum = 0;
        for (int i = 0; i < m; i++) {
            sort(mat[i].begin(), mat[i].end());
            minSum += mat[i][0]; maxSum += mat[i].back();
        }
        
        // Less than LB
        if (minSum >= target) return minSum - target;
        else adiv = target - minSum;
        
        // More than UB
        if (maxSum <= target) return target - maxSum;
        else adiv = min(adiv, maxSum - target);
        
        P.clear();
        
        // Rec the position
        // vector<int> npos(m, 0);
        
        // Rec the positive diff
        vector<vector<int> > div(m, vector<int>(n - 1, 0));
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n - 1; j++)
                div[i][j] = mat[i][j + 1] - mat[i][j];
        
        
        target -= minSum;
        
        // solve(0, target, div, npos);
        solve(0, target, div);
        
        return adiv;
    }
};
