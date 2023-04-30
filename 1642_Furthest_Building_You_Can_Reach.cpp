// https://leetcode.com/problems/furthest-building-you-can-reach/
// heap + greedy
class Solution {
public:
    static bool cmp(int a, int b) {
        return a > b;
    }
    
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int res = 0, len = heights.size();
        if (len - 1 <= ladders) return len - 1;

        // Height need to up
        vector<int> hDiv(len, 0); 
        for (int i = 1; i < len; i++) hDiv[i] = max(0, heights[i] - heights[i - 1]);
   
        vector<int> ladUse;
        make_heap(ladUse.begin(), ladUse.end(), cmp); // head to store the use of ladders
        
        while (res < len - 1) {
            if (hDiv[res + 1] <= 0) res++; // lower
            else {
                int Bneed = hDiv[res + 1]; // bricks needed
                
                if (ladUse.size() < ladders) { // Have left ladders
                    ladUse.push_back(Bneed);
                    push_heap(ladUse.begin(), ladUse.end(), cmp); 
                    res++;
                }
                else {
                    if (!ladders || Bneed < ladUse.front()) {
                        if (bricks < Bneed) break; // no bricks remaining
                        else {
                            bricks -= Bneed;
                            res++;
                        }
                    }
                    else {
                        // update the head
                        ladUse.push_back(Bneed);
                        push_heap(ladUse.begin(), ladUse.end(), cmp); 
                        
                        int newBneed = ladUse.front();
                        if (bricks < newBneed) break; // no bricks
                        
                        pop_heap(ladUse.begin(), ladUse.end(), cmp); 
                        ladUse.pop_back();
                        
                        bricks -= newBneed;
                        res++;
                    }   
                }
            }
        } 
        
        return res;
    }
};

// greedy
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int res = 0, len = heights.size();
        if (len - 1 <= ladders) return len - 1;

        vector<int> hDiv(len, 0);
        for (int i = 1; i < len; i++) hDiv[i] = max(0, heights[i] - heights[i - 1]);
        
        int sumDiv = accumulate(hDiv.begin(), hDiv.end(), 0);
        if (sumDiv <= bricks + ladders) return len - 1;
   
        while (res < len - 1) {
            if (heights[res] >= heights[res + 1]) {
                res++;
                continue;
            }
            
            int div = heights[res + 1] - heights[res];
                
            if (div > bricks) {
                if (ladders > 0) {
                    ladders--;
                    res++;
                }
                else return res;
            }
            else {
                vector<int> nex(heights.begin() + res + 1, heights.end());
                int briNex = maxAss(nex, bricks - div);
                if (ladders > 0 && heights[res + 1] > briNex) {
                    ladders--;
                    res++;
                } else {
                    bricks -= heights[res + 1];
                    res++;
                }
            }
            
            sumDiv -= div;
            if (sumDiv <= bricks + ladders || len - 1 - res <= ladders) return len - 1;
        }
        
        return res;
    }
    
    int maxAss(vector<int>& heights, int bricks) {
        int maxDep = 0;
        
        int pos = 0, len = heights.size();
        while (bricks >= 0 && pos < len - 1) {
            if (heights[pos] >= heights[pos + 1]) pos++;
            else {
                int dep = heights[pos + 1] - heights[pos];
                bricks -= dep;
                maxDep = max(dep, maxDep);
                pos++;
            }     
        }
        
        return maxDep;
    }
};
