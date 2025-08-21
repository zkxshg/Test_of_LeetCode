// https://leetcode.com/problems/rectangle-area-ii/
// Line sweep + hash table

class Solution {
public:
    #define ll long long

    int rectangleArea(vector<vector<int>>& rectangles) {
        ll ub = 1e9 + 1;

        unordered_map<int, vector<pair<int, int> > > bound;
        
        for (auto& rec : rectangles) {
            int x1 = rec[0], y1 = rec[1], x2 = rec[2], y2 = rec[3];
            
            for (int i = x1; i < x2; i++) {
                vector<pair<int, int> >& B = bound[i];
                
                if (B.empty()) {
                    B.push_back(make_pair(y1, y2)); continue;
                }
                
                for (int i = 0; i < B.size(); i++) {
                    if (y2 < B[i].first) { 
                        // [y1, y2] -> [L, R]
                        B.insert(B.begin() + i, make_pair(y1, y2));
                        break;
                    }
                    else if (y1 > B[i].second) {
                        // [L, R] -> [y1, y2]
                        if (i == B.size() - 1) {
                            B.push_back(make_pair(y1, y2));
                            break;
                        }
                    }
                    else if (y2 <= B[i].second) break; // [L,y1, y2, R]
                    else {
                        // [L,y1, R, y2]
                        if (i == B.size() - 1 || y2 < B[i + 1].first) {
                            B[i].second = y2; 
                            break; 
                        }
                        else {
                            B[i + 1].first = B[i].first;
                            B.erase(B.begin() + i);
                            i--;
                        }
                    }
                }
            }
        }
        
        ll res = 0;
        for (auto& p : bound) {
            for (auto& B : p.second) 
                //cout << B.first << ":" << B.second << ", "; cout << endl;
                res = (res + (B.second - B.first)) % ub;
        }
        
        return res;
    }
};
