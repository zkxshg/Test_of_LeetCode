// https://leetcode.com/problems/kth-smallest-instructions/
// combination
class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int row = destination[0], column = destination[1];
        int len = row + column, num = pow(2, len);
        
        string res = "";
        for (int i = 0; i < len; i++) {
            if (column > 0) {
                int com = comb(row + column - 1, row);
                
                if (k <= com) {
                    res += 'H';
                    column--;
                }
                else {
                    k -= com;
                    res += 'V';
                    row--;
                }
                
            }
            else {
                res += 'V';
                row--;
            }
        }
        return res;
    }
    
    int comb(int n, int r) {
        long ans = 1;
        for (int i = 1, j = n - r + 1; i <= r; ++i, ++j) ans = ans * j / i;
        return ans;
    }
    
};

// permutation
    string kthSmallestPath(vector<int>& destination, int k) {
        int row = destination[0], column = destination[1];
        int len = row + column, num = pow(2, len);

        string res = "";
        for (int i = 0; i < column; i++) res += 'H';
        for (int i = 0; i < row; i++) res += 'V';
        k--;
        
        while (k > 0) {
            next_permutation(res.begin(), res.end());
            k--;
        }
        return res;
    }


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
