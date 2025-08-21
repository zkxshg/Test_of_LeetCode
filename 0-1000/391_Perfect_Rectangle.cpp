// https://leetcode.com/problems/perfect-rectangle/
// Line Sweep
class Solution {
public:
    #define R rectangles
    
    int xL, xR, yD, yU;
    
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] != b[0]) return a[0] < b[0];
        
        if (a[2] * b[2] < 0) return (a[2] < 0);
        
        return a[1] < b[1];
    }
    
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int n = R.size();
        
        xL = R[0][0], xR = R[0][2], yD = R[0][1], yU = R[0][3];

        vector<vector<int> > hp;
        
        for (auto& rec : R) {
            int x0 = rec[0], x1 = rec[2], y0 = rec[1], y1 = rec[3]; 
            xL = min(xL, x0); xR = max(xR, x1); yD = min(yD, y0); yU = max(yU, y1);
            
            int h = y1 - y0;
            hp.push_back({x0, y0, h});
            hp.push_back({x1, y0, -h});
        }
        
        int recH = yU - yD;
        
        sort(hp.begin(), hp.end(), cmp);
        //for (auto& p : hp) cout << p[0] << ":" << p[1] << ":" << p[2] << ","; cout << endl;
        
        int pos = 0, len = hp.size(), temH = 0, temUB = yD;
        
        while (pos < len) {
            int x0 = hp[pos][0], y0 = hp[pos][1], h0 = hp[pos][2];
            
            // UpBound & LowBound
            if (y0 < yD || y0 + abs(h0) > yU) return false;
            //cout << x0 << "," << y0 << "," << h0 << "," << temH << "," << temUB << endl; 
            
            // check temp UpBound
            if (h0 >= 0 && y0 < temUB) return false; // cout << "check 1" << endl;
            
            // update temp UpBound
            if (h0 < 0 && temUB < -100000) temUB = y0;
            else if (h0 >= 0) temUB = y0 + h0;
            
            // update total height
            temH += hp[pos][2];
            
            // Check total height
            if (pos >= len - 1 || x0 != hp[pos + 1][0]) {
                if (pos >= len - 1){
                    if (temH) return false;
                }
                else if (temH != recH) return false;
                
                temUB = -100001; // Initialize
            } 
             
            pos++;
        }
        
         
        return true;
        
    }
};


// DP
class Solution {
public:
    #define R rectangles
    
    int xL, xR, yD, yU;
    
    bool perfect(vector<pair<int, int> >& S) {
        if (S.empty()) return false;
        
        int n = S.size();
        sort(S.begin(), S.end());
        
        // for (auto& p : S) cout << p.first << ":" << p.second << endl; cout << endl; 
        
        if (S[0].first != yD || S.back().second != yU) return false;
        
        for (int i = 1; i < n; i++) {
            // if (S[i - 1].first == S[i].first && S[i - 1].second == S[i].second) continue;
            if (S[i - 1].second != S[i].first) return false;
        }

        return true;
    }
    
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int n = R.size();
        
        xL = R[0][0], xR = R[0][2], yD = R[0][1], yU = R[0][3];
        
        unordered_map<int, int> H;
        
        for (auto& rec : R) {
            int x0 = rec[0], x1 = rec[2], y0 = rec[1], y1 = rec[3]; 
            xL = min(xL, x0); xR = max(xR, x1); yD = min(yD, y0); yU = max(yU, y1);
            // for (int i = x0 + 1; i <= x1; i++) sweep[i].push_back({y0, y1});
        }
        
        int recH = yU - yD;
        
        for (auto& rec : R) {
            int x0 = rec[0], x1 = rec[2], y0 = rec[1], y1 = rec[3]; 
            
            int temH = y1 - y0;
            
            for (int i = x0 + 1; i <= x1; i++) {
                H[i] += temH; 
                if (H[i] > recH) return false;
            }
        }

        for (int i = xL + 1; i <= xR; i++) //cout << "H" << i << "=" << H[i] << endl;
            if (H[i] != recH) return false;
         
        return true;
        
    }
};
