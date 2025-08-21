// math: shorter lv + less num + eual num (DP) 
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int num = digits.size();
        int lv = calInt(n);
        
        vector<int> candi;
        for (string str : digits) candi.push_back(str[0] - '0');
        sort(candi.begin(), candi.end());
        
        int res = 0;
        for (int i = 1; i < lv; i++) res += pow(num, i);

        string ns = to_string(n);
        for (int i = 0; i < lv; i++) {
            bool ifEqu = false; 
            int tn = ns[i] - '0';
            
            int tempN = 0;
            for (int c : candi) {
                if (c < tn) tempN++;
                else if (c == tn) {
                    ifEqu = true;
                    break;
                }
                else break;
            }
            
            res += tempN * pow(num, lv - i - 1);
            
            if (ifEqu && i == lv - 1) res += 1;
            
            if (!ifEqu) break;
        }
        
        return res;
    }
    
    int calInt(int n) {
        int lv = 0;
        while (n) {
            n /= 10;
            lv++;
        }
        return lv;
    }
};
