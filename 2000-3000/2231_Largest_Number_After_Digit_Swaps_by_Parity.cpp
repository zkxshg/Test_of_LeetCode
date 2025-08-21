// https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/
// sortinh

class Solution {
public:
    int largestInteger(int num) {
        if (num < 10) return num;
        
        vector<char> odd;  vector<int> oddPos;
        vector<char> even; vector<int> evenPos;
        
        int tn = num, pos = 0, len = 0;
        while (tn) {
            int dig = tn % 10;
            
            if (dig % 2) {
                odd.push_back(dig + '0');  oddPos.push_back(pos++);
            }
            else {
                even.push_back(dig + '0'); evenPos.push_back(pos++);
            }
            
            tn /= 10; len++;
        }
        
        sort(odd.begin(), odd.end());   sort(oddPos.begin(), oddPos.end());
        sort(even.begin(), even.end()); sort(evenPos.begin(), evenPos.end());
        
        // for (int i : evenPos) cout << i << endl;
        
        string res = ""; for (int i = 0; i < len; i++) res += '0';
        
        for (int i = 0; i < oddPos.size(); i++)  res[len - 1 - oddPos[i]] = odd[i];
        for (int i = 0; i < evenPos.size(); i++) res[len - 1 - evenPos[i]] = even[i];
        
        int r = 0;
        for (int i = 0; i < len; i++) r = r * 10 + (res[i] - '0');
        return r;
    }
};
