// https://leetcode.com/problems/circular-array-loop/
// array

class Solution {
public:
    int next(int pos, int n) {
        pos %= n;

        if (pos < 0) return n + (pos % n);
        return pos;
    }
    
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size(), index = 1001;
        
        for (int i = 0; i < n; i++) {
            if (next(i + nums[i], n) == i || nums[i] > 1000) continue;
            
            bool neg = (nums[i] < 0) ? true : false;
            
            int pre = i, cou = 1; 
            while (cou <= n) {
                int nex = next(pre + nums[pre], n); nums[pre] = index;
                // cout << pre << "->" << nex << endl;
                
                if (nex == pre) break;
                else if (nums[nex] == index) return true;
                else if (!nums[nex] || nums[nex] > 1000) break;
                else if (!(neg ^ (nums[nex] > 0))) break;
   
                pre = nex;
                cou++;
            }
            
            index++;
        }
        
        return false;
    }
};
