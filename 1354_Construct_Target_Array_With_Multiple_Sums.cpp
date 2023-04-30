// https://leetcode.com/problems/construct-target-array-with-multiple-sums/
// heap
class Solution {
public:
    bool isPossible(vector<int>& target) {
        int len = target.size();
        if (len < 2) {
            if (target[0] == 1) return true;
            else return false;
        }
        
        long long sum = 0;
        for (int i : target) sum += i;
        
        make_heap(target.begin(), target.end());
        
        while (sum > len) {
            int maxV  = target.front();
            
            long long lef = sum - maxV;
            if (lef >= maxV) return false;
            
            pop_heap(target.begin(), target.end()); target.pop_back();
            
            
            int newV = maxV % lef; 
            if (newV == 0) {
                if (lef == 1) return true;
                else return false;
            }
            lef = maxV - newV;

            target.push_back(newV); push_heap(target.begin(), target.end()); 
            
            sum -= lef;
            //for (int i : target) cout << i << ","; cout << endl;
        }
        
        return true;
    }
};
