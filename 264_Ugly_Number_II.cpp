// Queue * 3
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n < 7) return n;
        
        vector<int> l1, l2, l3;
        l1.push_back(4); l1.push_back(5); l1.push_back(6);
        l2.push_back(3);
        l3.push_back(2);
        int pos1 = 0, pos2 = 0, pos3 = 0, result = 0;
        
        n -= 6;
        while (n > 0) {
            int nex = INT_MAX;
            if (pos1 < l1.size()) nex = min(nex, l1[pos1] * 2);    
            if (pos2 < l2.size()) nex = min(nex, l2[pos2] * 3);
            if (pos3 < l3.size()) nex = min(nex, l3[pos3] * 5);
            
            if (pos1 < l1.size() && nex == l1[pos1] * 2) {
                l2.push_back(l1[pos1]);
                pos1++;
            }
            
            if (pos2 < l2.size() && l2[pos2] * 3 == nex) {
                l3.push_back(l2[pos2]);
                pos2++;
            }
            
            if (pos3 < l3.size() && l3[pos3] * 5 == nex) pos3++;
            
            result = nex;
            l1.push_back(nex);
            n--;
        }
        return result;
    }
};
