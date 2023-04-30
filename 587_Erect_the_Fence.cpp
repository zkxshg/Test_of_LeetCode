// https://leetcode.com/problems/erect-the-fence/
// Convex Hull

class Solution {
public:
    #define _USE_MATH_DEFINES

    double get_angle(double x1, double y1, double x2, double y2, double x3, double y3) {
        double theta = atan2(x1 - x3, y1 - y3) - atan2(x2 - x3, y2 - y3);

        if (theta > M_PI) theta -= 2 * M_PI;

        if (theta < -M_PI) theta += 2 * M_PI;

        theta = abs(theta * 180.0 / M_PI);
        return theta;
    }
    
    double dist(double x1, double y1, double x2, double y2) {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2); 
    }
    
    static bool cmp(vector<double>& pa, vector<double>& pb) {    
        if (pa[0] == pb[0]) return pa[1] > pb[1];
        return pa[0] < pb[0];
    }
    
    int px, py;
    
    void sortVector(vector<vector<int>>& trees) {
        sort(trees.begin(), trees.end());
        for (auto& v : trees) {
            cout << v[0] << "," << v[1];
            cout << "|";
        }
        cout << endl;
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size(); 
        if (n < 4) return trees;
        
        vector<pair<int, int> > pts;
        
        // sortVector(trees);
        
        // 1 Find p0
        int minX = trees[0][0], minY = trees[0][1];
        for (int i = 1; i < n; i++) {
            bool changed = false;
            
            if (trees[i][1] < minY) changed = true;
            else if (minY == trees[i][1] && trees[i][0] < minX) changed = true;
            
            if (changed) {
                pts.push_back({minX, minY});
                minX = trees[i][0]; minY = trees[i][1];
            }
            else pts.push_back({trees[i][0], trees[i][1]});
        } // for (auto& v : pts) cout << v.first << "," << v.second << ";"; cout << endl;
        
        
        px = minX; py = minY;
        
        // 2 Sort points by angle with p0
        vector<vector<double> > sidx;
        
        // Rec the points with same angles
        unordered_map<double, vector<pair<int, int> > > dupAngle; 
        unordered_map<double, int> dupNum; 
        
        for (int i = 0; i < n - 1; i++) {
            double angle = get_angle(pts[i].first, pts[i].second, 2 * px + 100, py, px, py);
            double dis = dist(pts[i].first, pts[i].second, px, py);
            sidx.push_back({angle, dis, double(i)});
        }
        
        sort(sidx.begin(), sidx.end(), cmp);
        //for (auto& v : sidx) cout << pts[v[2]].first << ":" << pts[v[2]].second 
        //    << " = " <<v[0] << ","; cout << endl;
            
        vector<pair<int, int> > spts;
        for (auto& v : sidx) {
            if (!dupNum[v[0]]) spts.push_back(pts[v[2]]);
            else dupAngle[v[0]].push_back(pts[v[2]]);
            
            dupNum[v[0]]++;
        }
        spts.push_back({px, py});
        
        // cout << "P0 = (" << minX << "," << minY << ")\n";
        // for (auto& v : spts) cout << v.first << "," << v.second << ";"; cout << endl;
        
        // 3 Stack to scan next points
        vector<pair<int, int> > st;
        st.push_back({px, py});

        for (auto& p : spts) {
            
            // 3-1  while |stack| > 1 and ccw(next_to_top, top, po) <= 0, POP
            while (st.size() > 1) {
                int m = st.size() - 1;
                int x0 = st[m - 1].first, y0 = st[m - 1].second;
                int x1 = st[m].first, y1 = st[m].second;
                int x2 = p.first, y2 = p.second;
                
                bool ccw = false;
                if (x0 == x1) { // Vertical
                    if (y1 < y0) { // down
                        if (x2 >= x1) ccw = true;
                    }
                    else if (x2 <= x1) ccw = true; // up
                }
                else if (y0 == y1) { // Horizontal
                    if (x1 < x0) { // LEFT
                        if (y2 <= y1) ccw = true;
                    }
                    else if (y2 >= y1) ccw = true; // RIGHT
                }
                else {
                    double k0 = double(y1 - y0) / double(x1 - x0);
                    double b0 = y1 - k0 * x1;
                    
                    if (k0 > 0) { // k > 0
                        if (y1 > y0) { // UP
                            if (y2 - k0 * x2 - b0 >= 0) ccw = true;
                        }
                        else if (y2 - k0 * x2 - b0 <= 0) ccw = true; // DOWN
                        
                    }
                    else { // k < 0
                        if (y1 > y0) { // UP
                            if (y2 - k0 * x2 - b0 <= 0) ccw = true;
                        }
                        else if (y2 - k0 * x2 - b0 >= 0) ccw = true; // DOWN
                    } 
                }

                //cout << st[m - 1].first << ":"<< st[m - 1].second << " + " <<
                //    st[m].first << ":" << st[m].second << " + " << 
                //    p.first << ":" << p.second << " = " << ccw <<endl;
                
                if (!ccw) st.pop_back();
                else break;
            }
            st.push_back(p);
        }
        
        st.pop_back();
        // for (auto& v : st) cout << v.first << "," << v.second << ";"; cout << endl;
        
        vector<vector<int>> res;
        for (auto& v : st) res.push_back({v.first, v.second}); 
        
        double an_st = get_angle(st[1].first, st[1].second, 2 * px + 100, py, px, py);
        double an_en = get_angle(st.back().first, st.back().second, 2 * px + 100, py, px, py);
        
        if (dupNum[an_st] > 1) {
            for (auto& v : dupAngle[an_st]) res.push_back({v.first, v.second}); 
            dupNum[an_st] = 1;
        }
        if (dupNum[an_en] > 1) {
            for (auto& v : dupAngle[an_en]) res.push_back({v.first, v.second}); 
        }
        
        return res;
    }
};
