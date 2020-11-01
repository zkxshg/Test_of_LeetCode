// bit mask
class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int row = destination[0], column = destination[1];
        int len = row + column, num = pow(2, len);
        
        int totalNum = comb(row, column);
        k %= totalNum;
        
        int aim = 0;
        for (int i = 0; i < num; i++) {
            bitset<32> bits(i);
            if (bits.count() == row) k--;
            if (k == 0) {
                aim = i;
                break;
            }
        }
        
        string res = "";
        bitset<32> bits(aim);
        for (int i = 0; i < len; i++) {
            if (bits[i]) res += 'V';
            else res += 'H';
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
    
    int comb(int a, int b) {
        double res = 1.0;
        for (int i = a + b; i > a; i++)  res *= i;
        for (int i = 2; i < a; i++) res /= i;
        return res;
    }
};
